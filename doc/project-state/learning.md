# Learning Tracker & Skill Board

> Targeted technologies needed for `pedit`, problem generation, and exam tooling.

---

## Skill Dashboard

| ID | Skill / Technology | Priority | Status | Jutge Application |
|---|---|---|---|---|
| `SK-01` | **Typst** | `P0 - High` | In Progress | Used by Pau for exam/solution PDFs (`PRO2_Parcial_2026P_Solucio.typ`); fast alternative to heavy LaTeX/Pandoc PDF builds. |
| `SK-02` | **MCP / CLI Agent Bridge** | `P0 - High` | Planned | Treating unmodified `jtk` as an MCP/tool backend driven deterministically by `pedit`. |
| `SK-03` | **WebStreams / SSE** | `P1 - Medium` | Planned | Understanding `api.jutge.org` streaming outputs (`upload`, JutgeAI chat routing). |
| `SK-04` | **OpenRouter SDK & DeepSeek Harness** | `P0 - High` | Planned | Calling DeepSeek v4 and other models from `pedit` before later Jutge API routing. |
| `SK-05` | **OpenCode CLI** | `P1 - Medium` | Planned | Evaluating terminal-based OpenRouter workflows (Pau's suggestion). |

---

## Active Focus: `SK-01` Typst

- [ ] Install locally (`brew install typst`) and verify with `typst --version` plus Tinymist in VS Code.
- [ ] Review Pau's template (`resources/professor gave 2026-10-25/problem-editor/generated-exam-sample/PRO2_Parcial_2026P_Solucio.typ`) using `@preview/codly` and `#let p1 = read(...)`.
- [ ] Convert a sample `.pbm` statement (`projects/01-demo-20261112/01-claude-task/dominant-peaks.pbm/problem.en.tex`) to Typst and benchmark `typst compile`.

## Upcoming: `SK-04` OpenRouter SDK & DeepSeek Harness

- [ ] Test OpenRouter SDK (TypeScript/Bun) with DeepSeek models using keys stored strictly in `.env` (gitignored).
- [ ] Design the tool-calling loop between the LLM, `pedit` editing commands, and `jtk` verification commands.
