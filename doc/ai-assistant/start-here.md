# AI Assistant Start Here

## Table of Contents

- [1. Read First](#1-read-first)
- [2. New Meeting / New Phase Workflow](#2-new-meeting--new-phase-workflow)

---

## 1. Read First

1. [AI Assistant Rules](./rules.md) — workspace boundaries, naming, TOC, privacy, git, and logging rules.
2. [Project State](../project-state/state.md) — current mandate, meeting decisions, phase registry, and timeline.
3. [`resources/original-info-from-professors/`](../../resources/original-info-from-professors/) — check for any new meeting notes added by Simin (strictly read-only).

---

## 2. New Meeting / New Phase Workflow

When Simin opens a new chat and asks you to read this file:

1. **Study new inputs:** Read the latest meeting notes in `resources/original-info-from-professors/` and any relevant files in `resources/` (never modify `resources/`).
2. **Update project state:** Record new decisions, next focus, and the new phase row in [Project State](../project-state/state.md).
3. **Plan in `projects/`:** Create the next numbered phase folder under `projects/` (e.g. `projects/03/` or feature subfolders) with concise `readme.md` plans explaining what will be built first.
4. **Wait for approval:** Present the plan (via the AI log) and **wait for Simin's confirmation or tweaks** before writing implementation code.
5. **Follow output rules:** Save every response summary in `doc/ai-log/YYYY-MM-DD/NN.md`, include a `## Table of Contents` in every markdown file, commit & push to `origin/main`, and reply in chat **only** with the clickable link to the log file.
