#!/usr/bin/env bun
import { cpSync, existsSync, mkdirSync, readdirSync, rmSync, writeFileSync } from "node:fs";
import { basename, join, resolve } from "node:path";
import { discoverProblems, readProblemContext } from "../pedit/src/pbm.ts";

const outDir = resolve(process.argv[2] || join(import.meta.dir, "dist"));
const rootDir = resolve(process.env.PEDIT_PROBLEMS_DIR || join(import.meta.dir, ".."));
const indexHtmlPath = join(import.meta.dir, "public", "index.html");

rmSync(outDir, { recursive: true, force: true });
mkdirSync(join(outDir, "problems"), { recursive: true });
mkdirSync(join(outDir, "samples"), { recursive: true });

cpSync(indexHtmlPath, join(outDir, "index.html"));

const problems = discoverProblems(rootDir, false);
const manifestProblems: Array<{
  id: string;
  name: string;
  relPath: string;
  title: string;
  languages: string[];
  pdfs: Record<string, string>;
  solutions: string[];
  sampleTests: string[];
  filesUrl: string;
}> = [];

for (const p of problems) {
  const destProbDir = join(outDir, "problems", p.id);
  mkdirSync(destProbDir, { recursive: true });

  const pdfLinks: Record<string, string> = {};
  for (const [lang, pdfAbs] of Object.entries(p.pdfs)) {
    if (existsSync(pdfAbs)) {
      const pdfFile = `problem.${lang}.pdf`;
      cpSync(pdfAbs, join(destProbDir, pdfFile));
      pdfLinks[lang] = `./problems/${p.id}/${pdfFile}`;
    }
  }

  const files = readProblemContext(p.path);
  const { path: _omitAbsPath, ...publicSummary } = p;
  writeFileSync(
    join(destProbDir, "files.json"),
    JSON.stringify({ summary: publicSummary, files }, null, 2),
    "utf8",
  );

  manifestProblems.push({
    id: p.id,
    name: p.name,
    relPath: p.relPath,
    title: p.title,
    languages: p.languages,
    pdfs: pdfLinks,
    solutions: p.solutions,
    sampleTests: p.sampleTests,
    filesUrl: `./problems/${p.id}/files.json`,
  });
}

// Copy top-level exam PDFs if present in generated-exam-sample/
const examDir = join(rootDir, "generated-exam-sample");
const extraPdfs: Array<{ label: string; url: string }> = [];
if (existsSync(examDir)) {
  for (const entry of readdirSync(examDir).sort()) {
    if (entry.endsWith(".pdf")) {
      cpSync(join(examDir, entry), join(outDir, "samples", entry));
      extraPdfs.push({ label: basename(entry, ".pdf"), url: `./samples/${entry}` });
    }
  }
}

writeFileSync(
  join(outDir, "manifest.json"),
  JSON.stringify(
    {
      mode: "static",
      sourceLabel: "problem-editor/ (generated-demo/, generated-exam-sample/, spec/models/)",
      generatedAt: new Date().toISOString(),
      problems: manifestProblems,
      extraPdfs,
    },
    null,
    2,
  ),
  "utf8",
);

console.log(
  `Exported static PDF viewer to ${outDir} (${manifestProblems.length} problems, ${extraPdfs.length} exam PDFs).`,
);
