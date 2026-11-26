import { existsSync, readFileSync } from "node:fs";
import { dirname, join, resolve } from "node:path";
import { OpenRouter } from "@openrouter/sdk";
import { jtkLint, jtkMake, runGenerator, type CmdResult } from "./jtk.ts";
import { applyFileWrites, readProblemContext } from "./pbm.ts";
import { buildProblemPdfs, type PdfBuildResult } from "./pdf.ts";

export interface ModelInfo {
  id: string;
  note: string;
}

export const CHEAP_MODELS: ModelInfo[] = [
  { id: "openai/gpt-4o-mini", note: "Default ultra-low-cost reliable JSON model" },
  { id: "google/gemini-2.5-flash-lite", note: "Ultra-low-cost fast Gemini model" },
  { id: "deepseek/deepseek-chat-v3-0324", note: "DeepSeek model (per Nov 12 meeting)" },
];

export const DEFAULT_MODEL = process.env.PEDIT_MODEL || CHEAP_MODELS[0].id;

export const EDIT_PRESETS: Record<string, string> = {
  "add-edge-tests":
    "Add meaningful edge-case tests (minimum N, maximum/boundary values, negatives/zeros if valid, ties) to sample-2.inp or private-correctness-*.inp / generate.ts without modifying *.cor files.",
  "add-slow-solution":
    "Add a plausible O(n^2) solution-slow.cc and a large efficiency test (e.g. private-efficiency-1.inp or via generate.ts plus a .ops time limit) so slow solutions exceed the limit.",
  "tighten-constraints":
    "Tighten input bounds in problem.<lang>.tex and generate.ts so naive brute-force solutions time out, keeping the golden solution valid.",
  "translate-es":
    "Translate the existing English statement (problem.en.tex and problem.en.yml) accurately into Spanish (problem.es.tex and problem.es.yml), preserving math and \\Sample macros.",
  "translate-ca":
    "Translate the existing statement accurately into Catalan (problem.ca.tex and problem.ca.yml), preserving math and \\Sample macros.",
  "fix-lint":
    "Fix all structure, LaTeX, handler.yml, or testcase issues reported by jtk lint and jtk make.",
};

export interface AiEditResponse {
  summary: string;
  runGenerator?: boolean;
  files: Record<string, string>;
}

export interface ClosedLoopResult {
  ok: boolean;
  model: string;
  attempts: number;
  summary: string;
  writtenFiles: string[];
  steps: Array<{
    attempt: number;
    summary: string;
    writtenFiles: string[];
    skippedProtectedFiles?: string[];
    generator?: CmdResult | null;
    make?: CmdResult;
    pdf?: PdfBuildResult;
    lint?: CmdResult;
  }>;
  error?: string;
}

function findEnvKey(): string | undefined {
  if (process.env.OPENROUTER_API_KEY) return process.env.OPENROUTER_API_KEY;
  if (
    process.env.ANTHROPIC_AUTH_TOKEN &&
    (process.env.ANTHROPIC_BASE_URL || "").toLowerCase().includes("openrouter")
  ) {
    return process.env.ANTHROPIC_AUTH_TOKEN;
  }
  let cur = resolve(process.cwd());
  for (let i = 0; i < 6; i++) {
    const envPath = join(cur, ".env");
    if (existsSync(envPath)) {
      const text = readFileSync(envPath, "utf8");
      for (const line of text.split(/\r?\n/)) {
        const m = /^\s*(?:export\s+)?OPENROUTER_API_KEY\s*=\s*["']?([^"'\s#]+)["']?/.exec(line);
        if (m) return m[1];
      }
    }
    const parent = dirname(cur);
    if (parent === cur) break;
    cur = parent;
  }
  return undefined;
}

export function loadSkillsPrompt(editorRoot?: string): string {
  const candidates = [
    editorRoot,
    resolve(import.meta.dir, "../.."),
    resolve(process.cwd()),
  ].filter(Boolean) as string[];

  const snippets: string[] = [];
  for (const base of candidates) {
    const skillPath = join(base, "skills", "problemes-jutge", "SKILL.md");
    const specPath = join(base, "spec", "problema-jutge.md");
    const constPath = join(base, "spec", "constitucio.md");
    if (existsSync(skillPath) || existsSync(specPath)) {
      if (existsSync(constPath)) {
        snippets.push("## Constitution (excerpt)\n" + readFileSync(constPath, "utf8").slice(0, 2200));
      }
      if (existsSync(specPath)) {
        snippets.push("## Jutge Problem Spec (excerpt)\n" + readFileSync(specPath, "utf8").slice(0, 3200));
      }
      if (existsSync(skillPath)) {
        snippets.push("## Skill: problemes-jutge\n" + readFileSync(skillPath, "utf8").slice(0, 1800));
      }
      break;
    }
  }
  return snippets.join("\n\n");
}

function extractJsonObject(raw: string): AiEditResponse {
  const cleaned = raw.trim();
  let jsonText = cleaned;
  const fenced = /```(?:json)?\s*([\s\S]*?)```/.exec(cleaned);
  if (fenced) {
    jsonText = fenced[1].trim();
  } else {
    const first = cleaned.indexOf("{");
    const last = cleaned.lastIndexOf("}");
    if (first !== -1 && last > first) {
      jsonText = cleaned.slice(first, last + 1);
    }
  }
  const parsed = JSON.parse(jsonText) as Partial<AiEditResponse>;
  if (!parsed || typeof parsed.files !== "object" || parsed.files === null) {
    throw new Error("Model response JSON must contain a 'files' object.");
  }
  return {
    summary: typeof parsed.summary === "string" ? parsed.summary : "Updated problem files",
    runGenerator: Boolean(parsed.runGenerator),
    files: parsed.files as Record<string, string>,
  };
}

async function callOpenRouter(
  model: string,
  systemPrompt: string,
  userPrompt: string,
): Promise<AiEditResponse> {
  const apiKey = findEnvKey();
  if (!apiKey) {
    throw new Error(
      "OPENROUTER_API_KEY is not set. Export it in your shell or add it to a gitignored .env file.",
    );
  }
  const client = new OpenRouter({ apiKey });
  const response = await client.chat.send({
    chatRequest: {
      model,
      temperature: 0.2,
      stream: false,
      messages: [
        { role: "system", content: systemPrompt },
        { role: "user", content: userPrompt },
      ],
    },
  });

  const msgContent = response.choices?.[0]?.message?.content;
  const text =
    typeof msgContent === "string"
      ? msgContent
      : Array.isArray(msgContent)
        ? msgContent
            .map((part) => ("text" in part && typeof part.text === "string" ? part.text : ""))
            .join("")
        : "";

  if (!text.trim()) {
    throw new Error("OpenRouter returned an empty response.");
  }
  return extractJsonObject(text);
}

export async function runClosedLoopAi(opts: {
  mode: "create" | "edit";
  pbmDir: string;
  prompt: string;
  model?: string;
  maxRetries?: number;
}): Promise<ClosedLoopResult> {
  const model = opts.model || DEFAULT_MODEL;
  const maxRetries = opts.maxRetries ?? 2;
  const pbmDir = resolve(opts.pbmDir);
  const skills = loadSkillsPrompt();

  const systemPrompt = [
    "You are pedit, an expert Jutge.org programming problem authoring agent.",
    "Return ONLY valid JSON with this exact schema:",
    '{"summary":"short description","runGenerator":false,"files":{"relative/path":"full file content"}}',
    "",
    "Strict `.pbm` rules:",
    "- NEVER output any `*.cor` file or `problem.yml` (jtk generates `.cor` automatically from the golden solution).",
    "- Keep `handler.yml` valid, e.g.:\n  handler: std\n  source_modifier: none\n  compilers: G++17",
    "- `problem.<lang>.yml` (original language) MUST contain ALL THREE keys: `title`, `author`, and `email` (use `author@jutge.org` as placeholder, never personal emails). Translations must instead have `title`, `translator`, `translator_email`, and `original_language`.",
    "- `problem.en.tex` MUST start with `\\Problem{...}`, include `\\Statement`, `\\Input`, `\\Output`, and `\\SampleTwoCol` (or `\\SampleOneCol`). Use `$...$` for math.",
    "- Include `solution.cc` (clean C++17 reading from `std::cin` and writing `std::cout`, compiling cleanly with `g++ -std=c++17`) and at least `sample-1.inp` and `sample-2.inp`.",
    "- If you generate private tests dynamically, write a Bun-compatible `generate.ts` (no `*.cor` writes) and set `runGenerator: true`.",
    "",
    skills,
  ].join("\n");

  const steps: ClosedLoopResult["steps"] = [];
  let feedback = "";

  for (let attempt = 1; attempt <= maxRetries + 1; attempt++) {
    const existingFiles = existsSync(pbmDir) ? readProblemContext(pbmDir) : {};
    const userPrompt = [
      `Mode: ${opts.mode}`,
      `Target folder: ${pbmDir}`,
      `User request: ${opts.prompt}`,
      Object.keys(existingFiles).length
        ? `\nExisting files:\n${JSON.stringify(existingFiles, null, 2)}`
        : "\nFolder is new/empty. Create all required files for a valid `.pbm` problem.",
      feedback ? `\nPrevious build/lint failed. Fix these exact errors:\n${feedback}` : "",
    ].join("\n");

    let aiResp: AiEditResponse;
    try {
      aiResp = await callOpenRouter(model, systemPrompt, userPrompt);
    } catch (err) {
      return {
        ok: false,
        model,
        attempts: attempt,
        summary: "OpenRouter call failed",
        writtenFiles: [],
        steps,
        error: err instanceof Error ? err.message : String(err),
      };
    }

    // Never write *.cor or problem.yml returned by the model; jtk generates *.cor.
    const skippedProtectedFiles: string[] = [];
    const writableFiles: Record<string, string> = {};
    for (const [k, v] of Object.entries(aiResp.files)) {
      if (k.endsWith(".cor") || k === "problem.yml") {
        skippedProtectedFiles.push(k);
      } else {
        writableFiles[k] = v;
      }
    }

    const writtenFiles = applyFileWrites(pbmDir, writableFiles);
    const generator =
      aiResp.runGenerator || writtenFiles.includes("generate.ts") ? await runGenerator(pbmDir) : null;
    const make = await jtkMake(pbmDir, ["all"]);
    const pdf = make.ok ? await buildProblemPdfs(pbmDir) : undefined;
    const lint = make.ok ? await jtkLint(pbmDir) : undefined;

    steps.push({
      attempt,
      summary: aiResp.summary,
      writtenFiles,
      skippedProtectedFiles: skippedProtectedFiles.length ? skippedProtectedFiles : undefined,
      generator,
      make,
      pdf,
      lint,
    });

    const allOk =
      (generator === null || generator.ok) &&
      make.ok &&
      Boolean(pdf?.ok) &&
      Boolean(lint?.ok);

    if (allOk) {
      return {
        ok: true,
        model,
        attempts: attempt,
        summary: aiResp.summary,
        writtenFiles,
        steps,
      };
    }

    const errs: string[] = [];
    if (generator && !generator.ok) errs.push(`generator error:\n${generator.stdout}\n${generator.stderr}`);
    if (!make.ok) errs.push(`jtk make error:\n${make.stdout}\n${make.stderr}`);
    if (pdf && !pdf.ok) errs.push(`pdf error:\n${pdf.warnings.join("\n")}\n${pdf.jtkResult.stdout}`);
    if (lint && !lint.ok) errs.push(`jtk lint error:\n${lint.stdout}\n${lint.stderr}`);
    feedback = errs.join("\n---\n").slice(0, 4000);
  }

  return {
    ok: false,
    model,
    attempts: steps.length,
    summary: steps[steps.length - 1]?.summary || "Failed after retries",
    writtenFiles: steps.flatMap((s) => s.writtenFiles),
    steps,
    error: feedback || "Closed-loop verification failed after maximum retries.",
  };
}
