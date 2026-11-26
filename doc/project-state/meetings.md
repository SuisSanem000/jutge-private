# Meeting Notes Summary

> Source originals remain untouched under `resources/original-info-from-professors/`.

---

## 2026-11-12 — Pivot to `pedit` & Next Steps

- **Keep `jtk` unchanged:** Treat `jtk` as an MCP/CLI tool that AI invokes; build a separate tool named **`pedit`** for AI-driven problem creation and editing.
- **Folder-based storage & simple UI:** Store problems in a folder and display them in a simple web interface (no heavy architecture yet).
- **LLM & SDK stack:** Use the **OpenRouter SDK** (DeepSeek v4, selectable models) for now, with the option to route requests through Jutge's backend API later.
- **Prompt vs. skills:** Move long structural instructions out of master prompts into skills so the prompt stays focused purely on the problem idea.
- **Problem-editing scope:** Catalog every operation someone needs when editing a problem and design dedicated helper commands for common edits.
- **References to study:** DeepSeek agent/harness architecture (suggested by Jordi) and OpenCode terminal with OpenRouter (suggested by Pau).

---

## 2026-10-22 — Kickoff Meeting

- **Motivation:** Jutge's problem bank ages quickly as solutions circulate; AI-assisted authoring lowers the barrier so more teachers can publish verified problems.
- **Problem varieties:** Support both full I/O programs and function-only (`no_main`) problems across C++, Python, Haskell, and Clojure.
- **Format truth & tooling:** `.pbm` folders compiled/verified via `jtk` remain the source of truth; Pau provided `problem-editor` specs, Claude skills, and sample problems; Jordi highlighted API/token integration and web-service delivery.
