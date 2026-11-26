# PDF Problem Viewer — Plan

> **Goal (2026-11-12 meeting notes):** Simple web interface to demonstrate a problem folder visually — no special architecture, database, or auth.

---

## Architecture

- Lightweight **`Bun.serve`** local HTTP server + plain HTML/CSS/JS frontend inside `projects/02/problem-editor/viewer/`.
- Reads `.pbm` folders directly from a configured local directory and calls unmodified `jtk make pdf` (`xelatex`) on demand.

---

## Core Features

1. **Problem Sidebar:** Lists all `.pbm` folders in the target directory.
2. **PDF Statement Pane:** Displays `problem.<lang>.pdf` inline with a **Rebuild PDF** button and language switcher.
3. **Inspection Tabs:** View `handler.yml`, `solution.*`, `sample-*.inp` / `.cor`, and `jtk lint` / `verify` output.

---

## What We Build First (MVP Step 1)

1. `Bun.serve` API endpoints:
   - `GET /api/problems` — scan target folder for `.pbm` directories and available languages.
   - `GET /api/problems/:id/pdf` — serve `problem.<lang>.pdf` (auto-run `jtk make pdf` if missing or on `?rebuild=1`).
   - `GET /api/problems/:id/files` — return key files (`handler.yml`, statements, solutions, samples) as JSON.
2. Minimal single-page UI (sidebar + embedded PDF + Rebuild button + file tabs).
3. Smoke test against `projects/02/problem-editor/generated-exam-sample/` `.pbm` folders.
