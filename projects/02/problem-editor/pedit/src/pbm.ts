import { existsSync, mkdirSync, readdirSync, readFileSync, statSync, writeFileSync } from "node:fs";
import { basename, join, relative, resolve } from "node:path";
import YAML from "yaml";

export interface ProblemSummary {
  id: string;
  name: string;
  path: string;
  relPath: string;
  title: string;
  languages: string[];
  pdfs: Record<string, string>;
  hasHandler: boolean;
  hasGenerator: boolean;
  solutions: string[];
  sampleTests: string[];
  privateTests: string[];
  missingCor: string[];
}

const SKIP_DIRS = new Set([
  "node_modules",
  ".git",
  ".vscode",
  "public",
  "pedit",
  "viewer",
  "private-problems",
]);

export function discoverProblems(rootDir: string, includePrivate = false): ProblemSummary[] {
  const absRoot = resolve(rootDir);
  if (!existsSync(absRoot)) return [];
  const results: ProblemSummary[] = [];

  function walk(dir: string) {
    let entries: string[] = [];
    try {
      entries = readdirSync(dir);
    } catch {
      return;
    }
    for (const entry of entries) {
      if (entry.startsWith(".") || entry.startsWith("jtk-")) continue;
      if (entry === "private-problems" && !includePrivate) continue;
      if (SKIP_DIRS.has(entry) && entry !== "private-problems") continue;

      const full = join(dir, entry);
      let isDir = false;
      try {
        isDir = statSync(full).isDirectory();
      } catch {
        continue;
      }
      if (!isDir) continue;

      if (entry.endsWith(".pbm")) {
        results.push(inspectProblem(full, absRoot));
      } else {
        walk(full);
      }
    }
  }

  if (absRoot.endsWith(".pbm")) {
    results.push(inspectProblem(absRoot, resolve(absRoot, "..")));
  } else {
    walk(absRoot);
  }

  return results.sort((a, b) => a.relPath.localeCompare(b.relPath));
}

export function inspectProblem(pbmDir: string, baseDir?: string): ProblemSummary {
  const abs = resolve(pbmDir);
  const relPath = baseDir ? relative(resolve(baseDir), abs) || basename(abs) : basename(abs);
  const id = relPath.replace(/[^a-zA-Z0-9._-]+/g, "__");
  const files = existsSync(abs) ? readdirSync(abs) : [];

  const langSet = new Set<string>();
  const pdfs: Record<string, string> = {};
  let title = basename(abs, ".pbm");

  // Multi-language layout at .pbm root: problem.<lang>.tex / yml / pdf
  for (const f of files) {
    const texMatch = /^problem\.([a-z]{2})\.tex$/.exec(f);
    if (texMatch) langSet.add(texMatch[1]);

    const pdfMatch = /^problem\.([a-z]{2})\.pdf$/.exec(f);
    if (pdfMatch) pdfs[pdfMatch[1]] = join(abs, f);

    const ymlMatch = /^problem\.([a-z]{2})\.yml$/.exec(f);
    if (ymlMatch) {
      langSet.add(ymlMatch[1]);
      if (ymlMatch[1] === "en" || title === basename(abs, ".pbm")) {
        try {
          const parsed = YAML.parse(readFileSync(join(abs, f), "utf8")) as Record<string, unknown> | null;
          if (parsed && typeof parsed.title === "string" && parsed.title.trim()) {
            title = parsed.title.trim();
          }
        } catch {
          // ignore invalid yaml during scan
        }
      }
    }
  }

  // Single-language subfolder fallback (e.g. en/problem.en.tex)
  for (const lang of ["en", "ca", "es", "fr", "de"]) {
    const sub = join(abs, lang);
    if (existsSync(sub) && statSync(sub).isDirectory()) {
      if (existsSync(join(sub, `problem.${lang}.tex`)) || existsSync(join(sub, `problem.${lang}.yml`))) {
        langSet.add(lang);
      }
      if (existsSync(join(sub, `problem.${lang}.pdf`))) {
        pdfs[lang] = join(sub, `problem.${lang}.pdf`);
      }
    }
  }

  const solutions = files.filter((f) => /^solution([-_.].+)?\.[a-zA-Z0-9]+$/.test(f)).sort();
  const inpFiles = files.filter((f) => f.endsWith(".inp")).sort();
  const sampleTests = inpFiles.filter((f) => f.includes("sample"));
  const privateTests = inpFiles.filter((f) => !f.includes("sample"));
  const missingCor = inpFiles.filter((f) => !existsSync(join(abs, f.replace(/\.inp$/, ".cor"))));

  return {
    id,
    name: basename(abs),
    path: abs,
    relPath,
    title,
    languages: Array.from(langSet).sort(),
    pdfs,
    hasHandler: existsSync(join(abs, "handler.yml")),
    hasGenerator: files.some((f) => f.startsWith("generate.")),
    solutions,
    sampleTests,
    privateTests,
    missingCor,
  };
}

export function readProblemContext(pbmDir: string): Record<string, string> {
  const abs = resolve(pbmDir);
  if (!existsSync(abs)) {
    throw new Error(`Problem directory does not exist: ${abs}`);
  }
  const files = readdirSync(abs).sort();
  const out: Record<string, string> = {};
  const keepPatterns = [
    /^handler\.yml$/,
    /^scores\.yml$/,
    /^tags\.yml$/,
    /^IDEA\.md$/,
    /^problem\.[a-z]{2}\.(tex|yml)$/,
    /^solution.*\.(cc|cpp|py|hs|clj|java|rs)$/,
    /^generate\.(ts|py|cc)$/,
    /^sample-.*\.(inp|cor)$/,
    /^.*\.ops$/,
  ];

  for (const f of files) {
    if (f === "problem.yml") continue; // never expose credentials
    if (!keepPatterns.some((re) => re.test(f))) continue;
    const full = join(abs, f);
    if (!statSync(full).isFile()) continue;
    const content = readFileSync(full, "utf8");
    out[f] = content.length > 16_000 ? content.slice(0, 16_000) + "\n... [truncated]" : content;
  }
  return out;
}

export function assertSafeRelativePath(pbmDir: string, relFile: string): string {
  const normalized = relFile.replace(/\\/g, "/").replace(/^\/+/, "");
  if (
    !normalized ||
    normalized.includes("..") ||
    normalized.startsWith(".") ||
    normalized === "problem.yml" ||
    normalized.endsWith(".cor") ||
    normalized.startsWith("jtk-")
  ) {
    throw new Error(`Refusing unsafe or protected file write: ${relFile}`);
  }
  const absTarget = resolve(pbmDir, normalized);
  const absRoot = resolve(pbmDir);
  if (!absTarget.startsWith(absRoot + "/") && absTarget !== absRoot) {
    throw new Error(`Path escapes problem directory: ${relFile}`);
  }
  return absTarget;
}

export function applyFileWrites(pbmDir: string, files: Record<string, string>): string[] {
  mkdirSync(pbmDir, { recursive: true });
  const written: string[] = [];
  for (const [relFile, content] of Object.entries(files)) {
    const absTarget = assertSafeRelativePath(pbmDir, relFile);
    const parent = resolve(absTarget, "..");
    mkdirSync(parent, { recursive: true });
    writeFileSync(absTarget, content, "utf8");
    written.push(relFile);
  }
  return written;
}

export function updateProblemMeta(
  pbmDir: string,
  lang: string,
  patch: { title?: string; author?: string; email?: string },
): { path: string; data: Record<string, unknown> } {
  const ymlPath = join(resolve(pbmDir), `problem.${lang}.yml`);
  let current: Record<string, unknown> = {};
  if (existsSync(ymlPath)) {
    current = (YAML.parse(readFileSync(ymlPath, "utf8")) as Record<string, unknown>) || {};
  }
  if (patch.title !== undefined) current.title = patch.title;
  if (patch.author !== undefined) current.author = patch.author;
  if (patch.email !== undefined) current.email = patch.email;
  writeFileSync(ymlPath, YAML.stringify(current), "utf8");
  return { path: ymlPath, data: current };
}

export function updateProblemHandler(
  pbmDir: string,
  patch: Record<string, unknown>,
): { path: string; data: Record<string, unknown> } {
  const ymlPath = join(resolve(pbmDir), "handler.yml");
  let current: Record<string, unknown> = {};
  if (existsSync(ymlPath)) {
    current = (YAML.parse(readFileSync(ymlPath, "utf8")) as Record<string, unknown>) || {};
  }
  for (const [k, v] of Object.entries(patch)) {
    if (v !== undefined) current[k] = v;
  }
  writeFileSync(ymlPath, YAML.stringify(current), "utf8");
  return { path: ymlPath, data: current };
}
