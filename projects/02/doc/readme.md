# Phase 02 — `pedit` CLI & PDF Problem Viewer

> **Status:** Implemented & synced to `jutge-org/problem-editor` (`687f6f5`, tag `v2026-11-26`).

## Table of Contents

- [Deliverables](#deliverables)
- [Implementation Summary](#implementation-summary)
- [Live Pages & Sync](#live-pages--sync)
- [Issues Log](#issues-log)

---

## Deliverables

1. [**`cli/`** — `pedit` CLI](../cli/doc/readme.md) (`projects/02/problem-editor/pedit/`)
2. [**`pdf-viewer/`** — Problem PDF Viewer](../pdf-viewer/doc/readme.md) (`projects/02/problem-editor/viewer/`)

---

## Implementation Summary

- **Unmodified `jtk` (`4.4.50`) backend:** `pedit` invokes `jtk make`, `jtk make pdf`, `jtk lint`, `jtk verify`, and `jtk clean` cleanly while adding JSON output, hidden skills/specs, OpenRouter closed-loop retries, and headless Chrome PDF fallback.
- **OpenRouter live verification:** Generated `projects/02/problem-editor/generated-demo/sum-evens.pbm` via `pedit create` and added `sample-3.inp` via `pedit edit` using `openai/gpt-4o-mini` + `jtk make` + `jtk lint`.
- **PDF Viewer verified:** `Bun.serve` + dual live/static UI (`projects/02/problem-editor/viewer/public/index.html`) exports all 11 public `.pbm` problems and exam PDFs cleanly.

---

## Live Pages & Sync

- **GitHub Pages (`jutge-private`):** `/02/pedit-cli-and-pdf-viewer/` (`cli/` with `pedit.tar.gz` download + `pdf-viewer/` static app).
- **Upstream sync (`jutge-org/problem-editor`):** Pushed `pedit/`, `viewer/`, `generated-demo/`, compiled PDFs, `.github/workflows/pages.yml`, and `README.md` at `687f6f5` (tag `v2026-11-26`).

---

## Issues Log

See [Phase 02 Issues](./issues.md), [CLI Issues](../cli/doc/issues.md), and [PDF Viewer Issues](../pdf-viewer/doc/issues.md).
