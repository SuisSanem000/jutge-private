# PDF Problem Viewer

> Implemented in `projects/02/problem-editor/viewer/`.

## Table of Contents

- [Architecture](#architecture)
- [Endpoints & Files](#endpoints--files)
- [How to Run](#how-to-run)
- [Verification Results](#verification-results)
- [Issues Log](#issues-log)

---

## Architecture

- **Zero-framework local server:** `server.ts` (`Bun.serve`, port `3456`) scans `projects/02/problem-editor/` (`generated-demo/`, `generated-exam-sample/`, `spec/models/`, excluding `private-problems/` unless `?private=1`), serves compiled PDFs, and supports switching folders via `POST /api/open-dir`.
- **Dual-mode UI:** `public/index.html` shows the opened root folder at the top of the sidebar, includes an **Open `.pbm` from PC** folder picker (working client-side on both GitHub Pages and localhost), and provides **Rebuild PDF**, **`jtk make`**, and **`jtk lint`** buttons in server mode.
- **Static exporter:** `export-static.ts` bundles `index.html`, `manifest.json`, PDFs, and sanitized `files.json` (omitting local machine paths and `problem.yml`) for GitHub Pages.

---

## Endpoints & Files

- `GET /api/problems` — list discovered `.pbm` problems, opened `root`/`sourceLabel`, and languages.
- `POST /api/open-dir` — switch scanned local folder on the live server.
- `GET /api/problems/:id/pdf?lang=<lang>&rebuild=0` — serve `problem.<lang>.pdf` (auto-builds if missing or `rebuild=1`).
- `GET /api/problems/:id/files` — return `handler.yml`, `problem.<lang>.tex`/`.yml`, `solution*`, and `sample-*`.
- `POST /api/problems/:id/action` — execute `make`, `pdf`, `lint`, or `verify`.

---

## How to Run

```bash
cd projects/02/problem-editor/viewer
bun run server.ts
# Open http://localhost:3456
```

---

## Verification Results

- Live `Bun.serve` smoke test (`PORT=3459`): `GET /api/problems` listed `generated-demo/sum-evens.pbm` + 10 public `.pbm` folders; `GET /api/problems/generated-demo__sum-evens.pbm/pdf` returned HTTP `200` (`112,086` bytes, `%PDF-1.4`).
- `bun run export-static.ts`: Exported `11` problems (`sum-evens.pbm` + `P1`..`P3` PDFs) and `2` exam PDFs cleanly with local paths stripped.

---

## Issues Log

See [PDF Viewer Issues](./issues.md).
