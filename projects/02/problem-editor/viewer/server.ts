#!/usr/bin/env bun
import { existsSync, readFileSync } from "node:fs";
import { join, resolve } from "node:path";
import { jtkLint, jtkMake, jtkVerify } from "../pedit/src/jtk.ts";
import { discoverProblems, inspectProblem, readProblemContext } from "../pedit/src/pbm.ts";
import { buildProblemPdfs } from "../pedit/src/pdf.ts";

const PORT = Number(process.env.PORT || 3456);
let rootDir = resolve(process.env.PEDIT_PROBLEMS_DIR || join(import.meta.dir, ".."));
const INDEX_HTML_PATH = join(import.meta.dir, "public", "index.html");

function json(data: unknown, status = 200): Response {
  return new Response(JSON.stringify(data, null, 2), {
    status,
    headers: { "Content-Type": "application/json; charset=utf-8" },
  });
}

function findById(id: string, includePrivate: boolean) {
  return discoverProblems(rootDir, includePrivate).find((p) => p.id === id);
}

const server = Bun.serve({
  port: PORT,
  async fetch(req) {
    const url = new URL(req.url);
    const pathname = url.pathname;
    const includePrivate = url.searchParams.get("private") === "1";

    if (pathname === "/" || pathname === "/index.html") {
      return new Response(readFileSync(INDEX_HTML_PATH, "utf8"), {
        headers: { "Content-Type": "text/html; charset=utf-8" },
      });
    }

    if (pathname === "/api/problems" && req.method === "GET") {
      const problems = discoverProblems(rootDir, includePrivate);
      return json({
        mode: "server",
        root: rootDir,
        sourceLabel: rootDir,
        problems,
      });
    }

    if (pathname === "/api/open-dir" && req.method === "POST") {
      const body = (await req.json().catch(() => ({}))) as { dir?: string };
      if (!body.dir || !existsSync(resolve(body.dir))) {
        return json({ error: "Directory does not exist" }, 400);
      }
      rootDir = resolve(body.dir);
      const problems = discoverProblems(rootDir, includePrivate);
      return json({ mode: "server", root: rootDir, sourceLabel: rootDir, problems });
    }

    const pdfMatch = /^\/api\/problems\/([^/]+)\/pdf$/.exec(pathname);
    if (pdfMatch && req.method === "GET") {
      const id = decodeURIComponent(pdfMatch[1]);
      const p = findById(id, includePrivate);
      if (!p) return json({ error: "Problem not found" }, 404);

      const reqLang = url.searchParams.get("lang") || p.languages[0] || "en";
      const rebuild = url.searchParams.get("rebuild") === "1";

      let info = inspectProblem(p.path, rootDir);
      let pdfPath = info.pdfs[reqLang] || Object.values(info.pdfs)[0];

      if (!pdfPath || rebuild) {
        const res = await buildProblemPdfs(p.path);
        info = inspectProblem(p.path, rootDir);
        pdfPath = info.pdfs[reqLang] || Object.values(info.pdfs)[0];
        if (!res.ok && !pdfPath) {
          return json({ error: "PDF build failed", details: res }, 500);
        }
      }

      if (!pdfPath || !existsSync(pdfPath)) {
        return json({ error: `PDF not available for language '${reqLang}'` }, 404);
      }

      return new Response(Bun.file(pdfPath), {
        headers: {
          "Content-Type": "application/pdf",
          "Content-Disposition": `inline; filename="${p.name}.${reqLang}.pdf"`,
        },
      });
    }

    const filesMatch = /^\/api\/problems\/([^/]+)\/files$/.exec(pathname);
    if (filesMatch && req.method === "GET") {
      const id = decodeURIComponent(filesMatch[1]);
      const p = findById(id, includePrivate);
      if (!p) return json({ error: "Problem not found" }, 404);
      return json({ summary: p, files: readProblemContext(p.path) });
    }

    const actionMatch = /^\/api\/problems\/([^/]+)\/action$/.exec(pathname);
    if (actionMatch && req.method === "POST") {
      const id = decodeURIComponent(actionMatch[1]);
      const p = findById(id, includePrivate);
      if (!p) return json({ error: "Problem not found" }, 404);

      const body = (await req.json().catch(() => ({}))) as { action?: string };
      const action = body.action || "lint";
      if (action === "make") return json(await jtkMake(p.path, ["all"]));
      if (action === "pdf") return json(await buildProblemPdfs(p.path));
      if (action === "lint") return json(await jtkLint(p.path));
      if (action === "verify") return json(await jtkVerify(p.path));
      return json({ error: `Unsupported action '${action}'` }, 400);
    }

    return json({ error: "Not found" }, 404);
  },
});

console.log(`PDF Problem Viewer running at http://localhost:${server.port} (root: ${rootDir})`);
