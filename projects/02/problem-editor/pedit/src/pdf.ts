import { existsSync, mkdirSync, readdirSync, readFileSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { basename, join, resolve } from "node:path";
import YAML from "yaml";
import { runCmd, type CmdResult } from "./jtk.ts";
import { inspectProblem } from "./pbm.ts";

export interface PdfBuildResult {
  ok: boolean;
  jtkResult: CmdResult;
  pdfs: Record<string, string>;
  usedFallback: boolean;
  warnings: string[];
}

function findChromeBinary(): string | null {
  const candidates = [
    process.env.CHROME_BIN,
    "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome",
    "/Applications/Chromium.app/Contents/MacOS/Chromium",
    "/usr/bin/google-chrome",
    "/usr/bin/chromium",
    "/usr/bin/chromium-browser",
  ].filter(Boolean) as string[];

  for (const bin of candidates) {
    if (existsSync(bin)) return bin;
  }
  return null;
}

function escapeHtml(s: string): string {
  return s.replace(/[&<>"]/g, (c) => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;" }[c]!));
}

function texInlineToHtml(tex: string): string {
  let out = tex
    .replace(/\\begin\{htmlonly\}[\s\S]*?\\end\{htmlonly\}/g, "")
    .replace(/\\begin\{latexonly\}|\\end\{latexonly\}/g, "")
    .replace(/\\medskip|\\smallskip|\\bigskip/g, "<br/>")
    .replace(/\\,/g, "&thinsp;")
    .replace(/\\ldots/g, "...")
    .replace(/\\leq/g, "≤")
    .replace(/\\geq/g, "≥")
    .replace(/\\neq/g, "≠")
    .replace(/\\times/g, "×")
    .replace(/\\cdot/g, "·")
    .replace(/\\rightarrow|\\to/g, "→")
    .replace(/\\infty/g, "∞");

  // Basic math $...$ and inline formatting before HTML escaping
  out = out.replace(/\\emph\{([^{}]*)\}/g, "<em>$1</em>");
  out = out.replace(/\\textbf\{([^{}]*)\}/g, "<strong>$1</strong>");
  out = out.replace(/\\texttt\{([^{}]*)\}/g, "<code>$1</code>");
  out = out.replace(/\\begin\{itemize\}/g, "<ul>").replace(/\\end\{itemize\}/g, "</ul>");
  out = out.replace(/\\begin\{enumerate\}/g, "<ol>").replace(/\\end\{enumerate\}/g, "</ol>");
  out = out.replace(/\\item\s+/g, "<li>");

  // Preserve tags while rendering inline math gently
  out = out.replace(/\$\$([\s\S]*?)\$\$/g, (_, m) => `<div class="math-block">${escapeHtml(m.trim())}</div>`);
  out = out.replace(/\$([^$]+)\$/g, (_, m) => `<span class="math">${escapeHtml(m)}</span>`);
  out = out.replace(/\n\s*\n/g, "</p><p>");
  return `<p>${out}</p>`;
}

function parseTexSections(tex: string): {
  title: string;
  sections: Array<{ heading: string; html: string }>;
  samples: Array<{ name: string; inp: string; cor: string }>;
} {
  let title = "";
  const titleMatch = /\\Problem\{([^{}]*)\}/.exec(tex);
  if (titleMatch) title = titleMatch[1].trim();

  const markerRe = /\\(Statement|Observation|Input|Output|Precondition|Author)\b/g;
  const matches = Array.from(tex.matchAll(markerRe));
  const sections: Array<{ heading: string; html: string }> = [];

  for (let i = 0; i < matches.length; i++) {
    const start = matches[i].index! + matches[i][0].length;
    const end = i + 1 < matches.length ? matches[i + 1].index! : tex.length;
    let body = tex.slice(start, end);
    body = body.replace(/\\Sample(One|Two)Col/g, "").trim();
    if (!body) continue;
    sections.push({
      heading: matches[i][1],
      html: texInlineToHtml(body),
    });
  }

  return { title, sections, samples: [] };
}

function buildStatementHtml(pbmDir: string, lang: string): string {
  const rootTex = join(pbmDir, `problem.${lang}.tex`);
  const subTex = join(pbmDir, lang, `problem.${lang}.tex`);
  const texPath = existsSync(rootTex) ? rootTex : subTex;
  const tex = existsSync(texPath) ? readFileSync(texPath, "utf8") : "";

  const rootYml = join(pbmDir, `problem.${lang}.yml`);
  const subYml = join(pbmDir, lang, `problem.${lang}.yml`);
  const ymlPath = existsSync(rootYml) ? rootYml : subYml;
  const meta = existsSync(ymlPath)
    ? ((YAML.parse(readFileSync(ymlPath, "utf8")) as Record<string, string> | null) || {})
    : {};

  const parsed = parseTexSections(tex);
  const title = meta.title || parsed.title || basename(pbmDir, ".pbm");

  const files = readdirSync(pbmDir).sort();
  const sampleInps = files.filter((f) => f.includes("sample") && f.endsWith(".inp"));
  const samples = sampleInps.map((inp) => {
    const cor = inp.replace(/\.inp$/, ".cor");
    return {
      name: inp.replace(/\.inp$/, ""),
      inp: readFileSync(join(pbmDir, inp), "utf8"),
      cor: existsSync(join(pbmDir, cor)) ? readFileSync(join(pbmDir, cor), "utf8") : "(not generated yet)",
    };
  });

  return `<!doctype html>
<html lang="${escapeHtml(lang)}">
<head>
<meta charset="utf-8" />
<style>
  @page { size: A4; margin: 18mm 18mm 18mm 18mm; }
  body { font-family: Georgia, "Times New Roman", serif; color: #111; line-height: 1.5; font-size: 11pt; }
  .header { border-bottom: 1.5px solid #222; padding-bottom: 6pt; margin-bottom: 14pt; display: flex; justify-content: space-between; align-items: baseline; }
  .header h1 { margin: 0; font-size: 18pt; font-family: system-ui, -apple-system, sans-serif; }
  .header .tag { font-family: system-ui, sans-serif; font-size: 9pt; color: #555; text-transform: uppercase; letter-spacing: 0.04em; }
  h2 { font-family: system-ui, -apple-system, sans-serif; font-size: 12pt; margin: 14pt 0 5pt; color: #1f2328; }
  p { margin: 5pt 0; }
  .math { font-style: italic; font-family: Georgia, serif; }
  .math-block { margin: 8pt 0; text-align: center; font-style: italic; }
  code, pre { font-family: ui-monospace, SFMono-Regular, Menlo, monospace; font-size: 9.5pt; }
  .sample-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 10pt; margin-top: 8pt; break-inside: avoid; }
  .sample-box { border: 1px solid #cbd5e1; border-radius: 4px; overflow: hidden; }
  .sample-box .lbl { background: #f1f5f9; padding: 3pt 8pt; font-family: system-ui, sans-serif; font-size: 8.5pt; font-weight: 700; border-bottom: 1px solid #cbd5e1; }
  .sample-box pre { margin: 0; padding: 7pt 8pt; white-space: pre-wrap; word-break: break-word; background: #fff; }
  .footer { margin-top: 18pt; border-top: 1px solid #e2e8f0; padding-top: 6pt; font-size: 8.5pt; color: #64748b; font-family: system-ui, sans-serif; }
</style>
</head>
<body>
  <div class="header">
    <h1>${escapeHtml(title)}</h1>
    <span class="tag">Jutge.org • ${escapeHtml(lang.toUpperCase())}</span>
  </div>
  ${parsed.sections.map((s) => `<section><h2>${escapeHtml(s.heading)}</h2>${s.html}</section>`).join("\n")}
  ${
    samples.length
      ? `<section><h2>Samples</h2>${samples
          .map(
            (smp, i) => `
          <div class="sample-grid">
            <div class="sample-box"><div class="lbl">Sample Input ${i + 1}</div><pre>${escapeHtml(smp.inp)}</pre></div>
            <div class="sample-box"><div class="lbl">Sample Output ${i + 1}</div><pre>${escapeHtml(smp.cor)}</pre></div>
          </div>`,
          )
          .join("\n")}</section>`
      : ""
  }
  <div class="footer">${escapeHtml(basename(pbmDir))}${meta.author ? ` • Author: ${escapeHtml(meta.author)}` : ""}</div>
</body>
</html>`;
}

export async function renderFallbackPdf(
  pbmDir: string,
  lang: string,
  outPdfPath: string,
): Promise<{ ok: boolean; error?: string }> {
  const chrome = findChromeBinary();
  if (!chrome) {
    return { ok: false, error: "Chrome/Chromium binary not found for headless PDF rendering." };
  }

  const tmp = join(tmpdir(), `pedit-pdf-${Date.now()}-${Math.random().toString(36).slice(2, 7)}`);
  mkdirSync(tmp, { recursive: true });
  const htmlPath = join(tmp, "statement.html");
  writeFileSync(htmlPath, buildStatementHtml(pbmDir, lang), "utf8");

  try {
    const res = await runCmd(
      [
        chrome,
        "--headless",
        "--disable-gpu",
        "--no-sandbox",
        "--no-pdf-header-footer",
        `--print-to-pdf=${outPdfPath}`,
        `file://${htmlPath}`,
      ],
      tmp,
      45_000,
    );
    if (!existsSync(outPdfPath)) {
      return { ok: false, error: `Chrome did not produce PDF: ${res.stderr || res.stdout}` };
    }
    return { ok: true };
  } finally {
    rmSync(tmp, { recursive: true, force: true });
  }
}

export async function buildProblemPdfs(pbmDir: string): Promise<PdfBuildResult> {
  const abs = resolve(pbmDir);
  const jtkResult = await runCmd(["jtk", "make", "pdf", "-d", abs], abs);
  const warnings: string[] = [];
  if (jtkResult.stdout.includes("Error in LaTeX")) {
    warnings.push("jtk make pdf reported a LaTeX error (missing TeX packages locally); using fallback renderer where PDF is missing.");
  }

  let info = inspectProblem(abs);
  let usedFallback = false;

  for (const lang of info.languages) {
    if (!info.pdfs[lang]) {
      const targetPdf = existsSync(join(abs, lang, `problem.${lang}.tex`))
        ? join(abs, lang, `problem.${lang}.pdf`)
        : join(abs, `problem.${lang}.pdf`);
      const fb = await renderFallbackPdf(abs, lang, targetPdf);
      if (fb.ok) {
        usedFallback = true;
      } else if (fb.error) {
        warnings.push(`Fallback PDF failed for ${lang}: ${fb.error}`);
      }
    }
  }

  info = inspectProblem(abs);
  return {
    ok: Object.keys(info.pdfs).length > 0,
    jtkResult,
    pdfs: info.pdfs,
    usedFallback,
    warnings,
  };
}
