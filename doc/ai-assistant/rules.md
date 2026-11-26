# AI Assistant Rules

Read this file and [Project State](../project-state/state.md) at the start of every session.

## Hard Rules

1. **Read-only `resources/`:** Never create, edit, or delete any file under `resources/` or production grading repos (`jutge-driver-std`, `jutge-dockerfiles`, `jutge-exec`).
2. **Write scope:** Write only inside `doc/`, `projects/`, root `README.md`, and `.gitignore`. Do not create root `CLAUDE.md` or stray memory files.
3. **Commit & push:** Commit and push to `origin/main` after every change. Keep the repository public (`SuisSanem000/jutge-private`) unless explicitly instructed otherwise.
4. **Local-only folders:** Keep local/private folders (`resources/`, `private-local/`, `jutge_repos/`, `problem-editor/`, `.env`, `.env.*`) in `.gitignore`; never track, commit, or push them.
5. **Privacy & secrets:** Never commit personal email addresses, passwords, passcodes, API tokens, or local PC file paths (`/Users/...`, `file:///Users/...`). Use generic placeholders (e.g., `<your-upc-email>`, `<your-password>`, `<repo-root>/...`) and relative markdown links.
6. **Naming convention:** Use short, semantically accurate, lowercase-with-dashes names for all files and folders (except platform-required names such as root `README.md` or `.pbm` problem-spec files).
7. **AI response logging:** Save every response in `doc/ai-log/YYYY-MM-DD/NN-YYYY-MM-DD-HHMM.md` (two-digit daily counter `01`, `02`, ...), keeping it as short, concise, technically accurate, and goal-aligned as possible. In chat, reply **only** with the clickable link to that log file.
8. **Technical integrity:** Never hand-write or LLM-generate `*.cor` files (always generate them via `jtk make`). Do not modify `jtk`; build `pedit` to interact with `jtk`. Verify claims against source code, label unchecked claims as *inference*, and never invent terminal output.
9. **Project phases:** Organize deliverables in `projects/` as 10–15 day phases (`01-...`, `02-...`) for supervisor reviews and keep [Project State](../project-state/state.md) updated.
