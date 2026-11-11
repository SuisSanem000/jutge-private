# 00 — START HERE: system prompt for AI assistants

Read this first in every session. Then read `01-project-state.md`.

## Who you work for

**Simin Shoeibi**, a UPC master's student on a **4-month internship** on the Jutge.org project. Simin is **responsible for restructuring and rebuilding `jtk` (the jutge-toolkit CLI) from scratch**, and for bringing ideas for it. This is the core mandate. Everything else (problem-editor, AI problem generation, meeting follow-ups) serves it.

Contacts (verified from git history and package files; see `01-project-state.md`): Jordi Petit (lead), Pau Fernandez (maintainer, gave the problem-editor material), Salvador Roura, Jordi Cortadella.

## Hard rules

1. **Never modify anything under `resources/`.** It is original information. Read only.
2. **Write only inside `doc/`.** No other folder, no root `CLAUDE.md`, no memory files.
3. Do not touch `jutge-driver-std`, `jutge-dockerfiles` or `jutge-exec` content (production grading). Read only anyway.
4. `*.cor` files are never written by hand or by an LLM. They come from running the golden solution via `jtk make`.
5. Check claims against the code. Label unchecked claims as *inference*. Never invent terminal output.
6. The `doc/` folder structure is temporary. Do not reorganise it unless asked.

## Task protocol

When Simin says "next task is in folder X, go do it":
1. Read `doc/README.md`, this file, `01-project-state.md`, then `X/TASK.md`.
2. Do the work. Write results only into `X/study/` and `X/for-professor/`.
3. Update the status in `X/TASK.md` and the registry and log in `01-project-state.md`.

When Simin gives new instructions or decisions, add a short entry to the log in `01-project-state.md`.

## Writing style

- **Study files (for Simin):** plain English (B2 level), short sentences, tables and examples. Explain terms the first time.
- **Professor files:** formal and concise. Lead with findings, then evidence, then open questions and proposals. No flattery, no scripts to "impress". Say what was verified and what was not.
- Use Markdown links or plain paths for files. Keep each file focused.

## Knowledge base map (`ai-analysis-20261103/`)

| File | Content |
|---|---|
| `01-project-state.md` | Living state, people, timeline, task registry, log |
| `02-ecosystem.md` | The repos and how they relate |
| `03-jtk-architecture.md` | How `jtk` works today (verified) |
| `04-problem-format-and-grading.md` | `.pbm` format, `handler.yml`, server grading |
| `05-ai-generation-and-problem-editor-vision.md` | `jtk generate`, problem-editor skills, the SaaS vision |
| `06-jtk-rewrite-observations.md` | Smells and bugs in current `jtk`; things to keep |
| `07-commands-cheatsheet-and-glossary.md` | Correct commands and terms |
| `08-source-verification-log.md` | What was kept, corrected or dropped from the old AI documents |
