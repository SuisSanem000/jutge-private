# 00 — START HERE: system prompt for AI assistants

Read this first in every session. Then read `01-project-state.md`.

## Who you work for

**Simin Shoeibi**, a UPC master's student on a **4-month internship** on the Jutge.org project. Simin is **responsible for restructuring and rebuilding `jtk` (the jutge-toolkit CLI) from scratch**, and for bringing ideas for it. This is the core mandate. Everything else (problem-editor, AI problem generation, meeting follow-ups) serves it.

Contacts (verified from git history and package files; see `01-project-state.md`): Jordi Petit (lead), Pau Fernandez (maintainer, gave the problem-editor material), Salvador Roura, Jordi Cortadella.

## Hard rules

1. **Never modify anything under `resources/`.** It is original information managed solely by Simin. Read only.
2. **Write only inside `doc/` and `work/`.** Never touch `resources/`. No root `CLAUDE.md`, no memory files.
3. Do not touch `jutge-driver-std`, `jutge-dockerfiles` or `jutge-exec` content (production grading). Read only anyway.
4. `*.cor` files are never written by hand or by an LLM. They come from running the golden solution via `jtk make`.
5. Check claims against the code. Label unchecked claims as *inference*. Never invent terminal output.
6. The folder structure is: `doc/ai-analysis/`, `doc/understanding/`, `doc/meetings-and-next-steps/`, and `work/`.
7. **Clickable Relative Links:** All links in markdown documents must be clean, clickable markdown links using valid relative paths (e.g. `[Title](relative-target-path)`). Never display raw file paths/addresses as the link text, and never use brittle absolute `file:///` paths that break preview navigation. Every file or folder referenced in markdown documents must be directly clickable to open in the editor.
8. **Clean External Copies & Git Ignore Rule:** The entire `resources/` directory and all `problem-editor/` folders are ignored in `.gitignore`. Simin maintains their working copy of `problem-editor` elsewhere on their machine for committing and pushing. The copy in `resources/` is for read-only AI context. If a new `problem-editor` copy is brought into `resources/`, always immediately remove any nested `.git/` directory so it is never tracked as a submodule or gitlink.
9. **No Shortcut Folders:** Never create shortcut, alias, or symlink folders (such as `ai-assistant`). The directory is named strictly `doc/ai-analysis/`.

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

## Knowledge base map

| Category | File | Content |
|---|---|---|
| AI Settings | [01. AI System Prompt](./01-ai-system-prompt.md) | System prompt, rules, and task protocols |
| Understanding | [01. Senior Dev Brief](../understanding/01-senior-dev-brief.md) | High-level onboarding briefing |
| Understanding | [02. Ecosystem](../understanding/02-ecosystem.md) | The repos and how they relate |
| Understanding | [03. jtk Architecture](../understanding/03-jtk-architecture.md) | How `jtk` works today (verified) |
| Understanding | [04. Problem Format & Grading](../understanding/04-problem-format-and-grading.md) | `.pbm` format, `handler.yml`, server grading |
| Understanding | [05. AI Problem Generation Analysis](../understanding/05-ai-problem-generation-analysis.md) | `jtk generate`, problem-editor skills, the SaaS vision |
| Understanding | [06. jtk Rewrite Observations](../understanding/06-jtk-rewrite-observations.md) | Smells and bugs in current `jtk`; things to keep |
| Understanding | [07. Commands & Glossary](../understanding/07-commands-and-glossary.md) | Correct commands and terms |
| Understanding | [08. Source Verification Log](../understanding/08-source-verification-log.md) | What was kept, corrected or dropped |
| Meetings | [01. Kickoff Summary (2026-10-22)](../meetings-and-next-steps/01-meeting-notes-summary-20261022.md) | Meeting notes summary |
| Meetings | [02. Meeting Prep & Study Plan (2026-11-12)](../meetings-and-next-steps/02-meeting-prep-and-study-plan-20261112.md) | Study roadmap and pitch |
| Meetings | [03. Project State & Living Log](../meetings-and-next-steps/03-project-state-and-living-log-20261111.md) | Living state, people, timeline, task registry, log |
