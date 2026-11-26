# AI Assistant Rules

## Table of Contents

- [Hard Rules](#hard-rules)

Read this file and [Project State](../project-state/state.md) at the start of every session.

## Hard Rules

1. **Read-only `resources/`:** Never create, edit, or delete any file under `resources/` or production grading repos (`jutge-driver-std`, `jutge-dockerfiles`, `jutge-exec`). The cloned `problem-editor/` repo lives directly under `resources/` root (`resources/problem-editor/`).
2. **Write scope:** Write only inside `doc/`, `projects/`, `.github/`, root `README.md`, and `.gitignore`. Do not create root `CLAUDE.md` or stray memory files.
3. **Commit & push:** Commit and push to `origin/main` after every change. Keep the repository public (`SuisSanem000/jutge-private`) unless explicitly instructed otherwise.
4. **Local-only folders:** Keep `resources/private-local/`, `**/problem-editor/` (and any `private-local/`, `jutge_repos/`, `**/problem.yml`, `.env`, `.env.*`) in `.gitignore`; never track, commit, or push them. Track and push `resources/` (outside `resources/private-local/`), `doc/`, and `projects/`.
5. **Privacy & secrets:** Never commit personal emails, passwords, passcodes, API tokens, or local PC paths (`/Users/...`, `file:///Users/...`). Use generic placeholders (e.g., `<your-upc-email>`, `<your-password>`, `<repo-root>/...`) and relative markdown links.
6. **Naming convention:** Use short, semantically accurate, lowercase-with-dashes names for all files and folders (except platform-required names such as root `README.md` or `.pbm` problem-spec files).
7. **AI response logging:** Save every response in `doc/ai-log/YYYY-MM-DD/NN.md` (two-digit daily order `01.md`, `02.md`, ...), keeping it as short, concise, technically accurate, and goal-aligned as possible. In chat, reply **only** with the clickable link to that log file.
8. **Technical integrity:** Never hand-write or LLM-generate `*.cor` files (always generate them via `jtk make`). Do not modify `jtk`; build `pedit` to interact with `jtk`. Verify claims against source code, label unchecked claims as *inference*, and never invent terminal output.
9. **Project phases:** Organize deliverables in `projects/` as 10–15 day phases (`01-...`, `02-...`) for supervisor reviews and keep [Project State](../project-state/state.md) updated.
10. **Auto-sync rules:** Whenever Simin states or implies a project rule in chat, immediately update this `doc/ai-assistant/rules.md` file (without duplicates).
11. **Table of Contents (TOC):** Every markdown file in `doc/`, `projects/`, and root `README.md` must include a `## Table of Contents` section with anchor links.
12. **Task-scoped docs:** Save technical and informational notes for a specific feature/task inside its `projects/<phase>/<feature>/` folder, while always saving a concise response summary in `doc/ai-log/YYYY-MM-DD/NN.md`.
13. **Sync to `pedit-demo` & `jutge-org/problem-editor`:** Source of truth for Phase 02 code is local `projects/02/problem-editor/` (gitignored in `jutge-private`). Only sync to **`SuisSanem000/pedit-demo`** (public Pages mirror, safe self-authored files only) and **`jutge-org/problem-editor`** (private upstream) when Simin explicitly asks to run [`sync-problem-editor.md`](./sync-problem-editor.md).
14. **Supervisor-ready `projects/` README style:** Every `readme.md` in `projects/` must lead with **What This Achieves** (clear outcome for supervisors), place **Technical Details** at the bottom, and use only **tables and short bullet lists** (no wordy paragraphs).
