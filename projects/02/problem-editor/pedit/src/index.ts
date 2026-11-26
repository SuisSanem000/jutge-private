#!/usr/bin/env bun
import { existsSync, readFileSync } from "node:fs";
import { join, resolve } from "node:path";
import { createInterface } from "node:readline/promises";
import { CHEAP_MODELS, DEFAULT_MODEL, EDIT_PRESETS, runClosedLoopAi } from "./ai.ts";
import { jtkClean, jtkLint, jtkMake, jtkVerify, runGenerator } from "./jtk.ts";
import { buildProblemPdfs } from "./pdf.ts";
import {
  discoverProblems,
  inspectProblem,
  updateProblemHandler,
  updateProblemMeta,
} from "./pbm.ts";

interface ParsedArgs {
  flags: Record<string, string | boolean>;
  positional: string[];
}

function parseArgs(argv: string[]): ParsedArgs {
  const flags: Record<string, string | boolean> = {};
  const positional: string[] = [];
  for (let i = 0; i < argv.length; i++) {
    const a = argv[i];
    if (a === "--") {
      positional.push(...argv.slice(i + 1));
      break;
    }
    if (a.startsWith("--")) {
      const eq = a.indexOf("=");
      if (eq !== -1) {
        flags[a.slice(2, eq)] = a.slice(eq + 1);
      } else {
        const key = a.slice(2);
        const next = argv[i + 1];
        if (
          next !== undefined &&
          !next.startsWith("-") &&
          !["json", "include-private", "help", "h"].includes(key)
        ) {
          flags[key] = next;
          i++;
        } else {
          flags[key] = true;
        }
      }
    } else if (a === "-h") {
      flags.help = true;
    } else {
      positional.push(a);
    }
  }
  return { flags, positional };
}

function printResult(asJson: boolean, data: unknown, humanText?: string) {
  if (asJson) {
    console.log(JSON.stringify(data, null, 2));
  } else if (humanText !== undefined) {
    console.log(humanText);
  } else {
    console.log(JSON.stringify(data, null, 2));
  }
}

function helpText(): string {
  return `pedit — AI-assisted Jutge problem editor CLI (wraps unmodified jtk)

Usage:
  pedit list [--dir <path>] [--include-private] [--json]
  pedit status <problem.pbm> [--json]
  pedit show <problem.pbm> [file] [--json]

Deterministic jtk wrappers:
  pedit build <problem.pbm> [--json]     Run generate.ts (if present) + jtk make all
  pedit pdf <problem.pbm> [--json]       Run jtk make pdf
  pedit lint <problem.pbm> [--json]      Run jtk lint
  pedit verify <problem.pbm> [files...]  Run jtk verify
  pedit clean <problem.pbm> [--json]     Run jtk clean

Deterministic editors:
  pedit meta <problem.pbm> --lang en [--title "..."] [--author "..."] [--email "..."]
  pedit handler <problem.pbm> [--handler std] [--compilers G++17] [--source_modifier none]

AI commands (OpenRouter SDK, closed-loop with jtk):
  pedit models [--json]                  List recommended low-cost models (default: ${DEFAULT_MODEL})
  pedit presets [--json]                 List suggested edit presets
  pedit create <dir.pbm> "<idea>" [--model <id>] [--json]
  pedit edit <dir.pbm> ["<instruction>"] [--preset <name>] [--model <id>] [--json]
  pedit chat <dir.pbm> [--model <id>]    Interactive editing loop`;
}

async function main() {
  const { flags, positional } = parseArgs(process.argv.slice(2));
  const asJson = Boolean(flags.json);
  const cmd = positional[0];

  if (!cmd || flags.help || cmd === "help") {
    console.log(helpText());
    return;
  }

  if (cmd === "models") {
    printResult(
      asJson,
      { default: DEFAULT_MODEL, models: CHEAP_MODELS },
      CHEAP_MODELS.map((m) => `- ${m.id}${m.id === DEFAULT_MODEL ? " (default)" : ""}: ${m.note}`).join("\n"),
    );
    return;
  }

  if (cmd === "presets") {
    printResult(
      asJson,
      EDIT_PRESETS,
      Object.entries(EDIT_PRESETS)
        .map(([k, v]) => `- ${k}: ${v}`)
        .join("\n"),
    );
    return;
  }

  if (cmd === "list") {
    const dir = typeof flags.dir === "string" ? flags.dir : ".";
    const problems = discoverProblems(dir, Boolean(flags["include-private"]));
    printResult(
      asJson,
      problems,
      problems.length
        ? problems
            .map(
              (p) =>
                `${p.relPath} | title="${p.title}" | langs=[${p.languages.join(",")}] | pdfs=[${Object.keys(p.pdfs).join(",")}]`,
            )
            .join("\n")
        : "No .pbm problem folders found.",
    );
    return;
  }

  const target = positional[1];
  if (!target) {
    console.error(`Missing <problem.pbm> path for command '${cmd}'.`);
    process.exit(1);
  }
  const pbmDir = resolve(target);

  if (cmd === "status") {
    const info = inspectProblem(pbmDir);
    printResult(
      asJson,
      info,
      [
        `Problem: ${info.name} (${info.title})`,
        `Languages: ${info.languages.join(", ") || "none"}`,
        `PDFs: ${Object.keys(info.pdfs).join(", ") || "none"}`,
        `Solutions: ${info.solutions.join(", ") || "none"}`,
        `Samples: ${info.sampleTests.length}, Private: ${info.privateTests.length}, Missing .cor: ${info.missingCor.length}`,
      ].join("\n"),
    );
    return;
  }

  if (cmd === "show") {
    const file = positional[2];
    if (!file) {
      const info = inspectProblem(pbmDir);
      printResult(asJson, info);
      return;
    }
    if (file === "problem.yml") {
      console.error("Refusing to display problem.yml credentials.");
      process.exit(1);
    }
    const full = join(pbmDir, file);
    if (!existsSync(full)) {
      console.error(`File not found: ${full}`);
      process.exit(1);
    }
    const content = readFileSync(full, "utf8");
    printResult(asJson, { file, content }, content);
    return;
  }

  if (cmd === "build") {
    const gen = await runGenerator(pbmDir);
    const make = await jtkMake(pbmDir, ["all"]);
    const ok = (gen === null || gen.ok) && make.ok;
    printResult(asJson, { ok, generator: gen, make }, `${make.stdout}\n${make.stderr}`.trim());
    if (!ok) process.exit(1);
    return;
  }

  if (cmd === "pdf") {
    const res = await buildProblemPdfs(pbmDir);
    printResult(
      asJson,
      res,
      `PDFs: ${Object.keys(res.pdfs).join(", ") || "none"}${res.usedFallback ? " (via Chrome fallback)" : ""}\n${res.warnings.join("\n")}`.trim(),
    );
    if (!res.ok) process.exit(1);
    return;
  }

  if (cmd === "lint") {
    const res = await jtkLint(pbmDir);
    printResult(asJson, res, `${res.stdout}\n${res.stderr}`.trim());
    if (!res.ok) process.exit(1);
    return;
  }

  if (cmd === "verify") {
    const res = await jtkVerify(pbmDir, positional.slice(2));
    printResult(asJson, res, `${res.stdout}\n${res.stderr}`.trim());
    if (!res.ok) process.exit(1);
    return;
  }

  if (cmd === "clean") {
    const res = await jtkClean(pbmDir);
    printResult(asJson, res, `${res.stdout}\n${res.stderr}`.trim());
    if (!res.ok) process.exit(1);
    return;
  }

  if (cmd === "meta") {
    const lang = typeof flags.lang === "string" ? flags.lang : "en";
    const res = updateProblemMeta(pbmDir, lang, {
      title: typeof flags.title === "string" ? flags.title : undefined,
      author: typeof flags.author === "string" ? flags.author : undefined,
      email: typeof flags.email === "string" ? flags.email : undefined,
    });
    printResult(asJson, res, `Updated ${res.path}`);
    return;
  }

  if (cmd === "handler") {
    const patch: Record<string, unknown> = {};
    for (const key of ["handler", "compilers", "source_modifier", "checker"]) {
      if (typeof flags[key] === "string") patch[key] = flags[key];
    }
    const res = updateProblemHandler(pbmDir, patch);
    printResult(asJson, res, `Updated ${res.path}`);
    return;
  }

  if (cmd === "create" || cmd === "edit") {
    const model = typeof flags.model === "string" ? flags.model : DEFAULT_MODEL;
    const presetName = typeof flags.preset === "string" ? flags.preset : undefined;
    const presetText = presetName ? EDIT_PRESETS[presetName] : undefined;
    if (presetName && !presetText) {
      console.error(`Unknown preset '${presetName}'. Run 'pedit presets' to see valid presets.`);
      process.exit(1);
    }
    const rawPrompt = positional.slice(2).join(" ").trim();
    const prompt = [presetText, rawPrompt].filter(Boolean).join("\nAdditional notes: ");
    if (!prompt) {
      console.error(`Provide an instruction or --preset for '${cmd}'.`);
      process.exit(1);
    }
    const res = await runClosedLoopAi({
      mode: cmd,
      pbmDir,
      prompt,
      model,
    });
    printResult(
      asJson,
      res,
      res.ok
        ? `OK (${res.model}, ${res.attempts} attempt(s)): ${res.summary}\nFiles: ${res.writtenFiles.join(", ")}`
        : `FAILED (${res.model}): ${res.error}`,
    );
    if (!res.ok) process.exit(1);
    return;
  }

  if (cmd === "chat") {
    const model = typeof flags.model === "string" ? flags.model : DEFAULT_MODEL;
    const rl = createInterface({ input: process.stdin, output: process.stdout });
    console.log(`pedit interactive chat on ${pbmDir} (model: ${model}). Type 'exit' to quit.`);
    while (true) {
      const line = (await rl.question("pedit> ")).trim();
      if (!line || line === "exit" || line === "quit") break;
      const res = await runClosedLoopAi({ mode: "edit", pbmDir, prompt: line, model });
      console.log(res.ok ? `OK: ${res.summary}` : `ERROR: ${res.error}`);
    }
    rl.close();
    return;
  }

  console.error(`Unknown command '${cmd}'. Run 'pedit --help'.`);
  process.exit(1);
}

main().catch((err) => {
  console.error(err instanceof Error ? err.message : String(err));
  process.exit(1);
});
