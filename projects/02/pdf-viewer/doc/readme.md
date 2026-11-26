# PDF Problem Viewer

## Table of Contents

- [What This Achieves](#what-this-achieves)
- [Features & Modes](#features--modes)
- [Technical Details](#technical-details)
- [Verification](#verification)

## What This Achieves

- **Instant visual review:** Shows any `.pbm` problem's compiled PDF statement alongside its LaTeX, solution, sample tests, and `handler.yml`.
- **Transparent folder scope:** Displays the opened root folder (`sourceLabel` / `root`) at the top of the sidebar.
- **Open any `.pbm` from PC:** Includes a browser folder picker (`Open .pbm from PC`) that works offline/client-side even on static GitHub Pages, plus server directory switching locally.
- **Zero heavy stack:** Runs with `Bun.serve` + plain HTML/JS (no database, auth, or framework).

## Features & Modes

| Mode | Where It Runs | Capabilities |
|---|---|---|
| **Live Server (`server.ts`)** | Localhost (`PORT=3456`) | Scans folder, auto-builds PDFs, **Rebuild PDF** / **`jtk make`** / **`jtk lint`** buttons, `Switch Server Folder` |
| **Static Pages (`export-static.ts`)** | GitHub Pages (`pedit-demo`) | Prebuilt `manifest.json` + PDFs + sanitized `files.json` + client-side **Open `.pbm` from PC** |

## Technical Details

- **API Endpoints (`server.ts`):**
  - `GET /api/problems`: Returns opened `root`/`sourceLabel` and `.pbm` list (excludes `private-problems/` unless `?private=1`).
  - `POST /api/open-dir`: Switches the scanned local directory on the live server.
  - `GET /api/problems/:id/pdf?lang=<lang>&rebuild=0`: Serves `problem.<lang>.pdf` (calls `buildProblemPdfs` if missing or `rebuild=1`).
  - `GET /api/problems/:id/files`: Returns inspectable text files (never exposes `problem.yml`).
  - `POST /api/problems/:id/action`: Runs `make`, `pdf`, `lint`, or `verify` via unmodified `jtk`.
- **Run locally:** `cd projects/02/problem-editor/viewer && bun run server.ts`.

## Verification

| Check | Result |
|---|---|
| **Live server (`PORT=3459`)** | `GET /api/problems` listed `11` public `.pbm` problems; `/pdf` returned `HTTP 200` (`%PDF-1.4`, `112,086` bytes) |
| **Static export (`export-static.ts`)** | Exported `11` problems (`sum-evens.pbm` + `P1..P3` PDFs) and `2` exam PDFs with local paths stripped |
| **Issues** | See [PDF Viewer Issues](./issues.md) (macOS BasicTeX `moreverb.sty` fallback) |
