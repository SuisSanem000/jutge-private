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

- **Zero-framework local server:** `server.ts` (`Bun.serve`, port `3456`) scans `.pbm` folders (excluding `private-problems/` unless `?private=1`), serves compiled PDFs, and runs `jtk make` / `jtk lint` / `jtk verify` / PDF builds on demand.
- **Dual-mode UI:** `public/index.html` automatically uses `/api/problems` when run under `Bun.serve` (with **Rebuild PDF**, **`jtk make`**, and **`jtk lint`** buttons) and `./manifest.json` when hosted statically on GitHub Pages.
- **Static exporter:** `export-static.ts` bundles `index.html`, `manifest.json`, PDFs, and sanitized `files.json` (omitting local machine paths and `problem.yml`) for GitHub Pages.

---

## Endpoints & Files

- `GET /api/problems` — list discovered `.pbm` problems and languages.
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
