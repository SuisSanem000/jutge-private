# PDF Problem Viewer — Issues Log

## Table of Contents

- [2026-11-26 — `jtk make pdf` Fails Silently (`exit 0`) Under macOS BasicTeX](#2026-11-26--jtk-make-pdf-fails-silently-exit-0-under-macos-basicteX)

---

## 2026-11-26 — `jtk make pdf` Fails Silently (`exit 0`) Under macOS BasicTeX

- **What happened:** Running `jtk make pdf` printed `Error in LaTeX: root.log` while still exiting `0` and producing no `.pdf` file. Inspecting `root.log` showed `! LaTeX Error: File 'moreverb.sty' not found.` under `/usr/local/texlive/2026basic/`.
- **Fix:** Added `pedit/src/pdf.ts` (`buildProblemPdfs`) shared by both `pedit pdf` and `viewer/server.ts`. It still invokes `jtk make pdf` first, checks whether `problem.<lang>.pdf` actually exists on disk, and automatically falls back to rendering the statement, LaTeX math, and sample I/O tables via headless Chrome (`--print-to-pdf`).
- **Verification:** Generated working PDFs for `generated-demo/sum-evens.pbm` and `generated-exam-sample/P1..P3` (`%PDF-1.4`, HTTP `200` via viewer).
