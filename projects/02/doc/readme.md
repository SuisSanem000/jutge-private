# Phase 02 — `pedit` CLI & PDF Problem Viewer

## Table of Contents

- [What This Achieves](#what-this-achieves)
- [Deliverables](#deliverables)
- [Live Demos & Repositories](#live-demos--repositories)
- [Technical Steps](#technical-steps)

## What This Achieves

- **Keeps `jtk` unchanged:** Uses `jtk` (`4.4.50`) as the deterministic build, test, and lint engine.
- **AI problem editing (`pedit`):** Teachers write a short request; `pedit` loads Jutge rules/skills, calls OpenRouter (`openai/gpt-4o-mini`), edits `.pbm` files, and auto-verifies with `jtk`.
- **Visual problem inspection (`viewer`):** Teachers select any `.pbm` folder (from repo or PC) and view its PDF statement, code, and sample tests in a browser.
- **Safe public demo:** Hosts only self-authored tools and synthetic `sum-evens.pbm` on GitHub Pages without exposing private exam problems.

## Deliverables

| Deliverable | Purpose | Docs |
|---|---|---|
| **`pedit` CLI** | AI + deterministic `.pbm` editor wrapping `jtk` | [CLI Docs](../cli/doc/readme.md) • [`jtk` vs `pedit`](../cli/doc/jtk-vs-pedit.md) • [Issues](../cli/doc/issues.md) |
| **PDF Problem Viewer** | Browser UI for `.pbm` PDFs, code, and samples | [Viewer Docs](../pdf-viewer/doc/readme.md) • [Issues](../pdf-viewer/doc/issues.md) |
| **Phase Notes** | Supervisor email draft & CI notes | [Supervisor Email](./supervisor-email.md) • [Phase Issues](./issues.md) |

## Live Demos & Repositories

| Target | Contents | Status |
|---|---|---|
| **Local Source** (`projects/02/problem-editor/`) | `pedit/`, `viewer/`, `generated-demo/sum-evens.pbm/` | Gitignored source of truth |
| **Public Pages Mirror** ([`SuisSanem000/pedit-demo`](https://github.com/SuisSanem000/pedit-demo)) | `pedit/`, `viewer/`, `demo-problems/sum-evens.pbm/` | Live: [Hub](https://suissanem000.github.io/pedit-demo/) • [CLI](https://suissanem000.github.io/pedit-demo/cli/) • [Viewer](https://suissanem000.github.io/pedit-demo/pdf-viewer/) |
| **Private Upstream** (`jutge-org/problem-editor`) | Synced at `f4465de` (`v2026-11-26-2`) | Up to date |

## Technical Steps

- **Step 1 — CLI (`pedit/`):** Built Bun/TS CLI (`index.ts`, `jtk.ts`, `pbm.ts`, `pdf.ts`, `ai.ts`); verified `bun test` (2/2) + live `create` and `edit` on `sum-evens.pbm`.
- **Step 2 — PDF Fallback (`pdf.ts`):** Runs `jtk make pdf` first; falls back to headless Chrome if local BasicTeX lacks `moreverb.sty`.
- **Step 3 — Viewer (`viewer/`):** Built `Bun.serve` API (`server.ts`), static exporter (`export-static.ts`), and dual-mode UI (`public/index.html`) with local PC `.pbm` folder picker.
- **Step 4 — GitHub Actions:** Automated `pedit.tar.gz` bundle + static viewer deployment on `SuisSanem000/pedit-demo`.
