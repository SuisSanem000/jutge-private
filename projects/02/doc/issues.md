# Phase 02 — Workspace & CI Issues

## Table of Contents

- [2026-11-26 — GitHub Pages Disabled on Private `jutge-org/problem-editor`](#2026-11-26--github-pages-disabled-on-private-jutge-orgproblem-editor)

---

## 2026-11-26 — GitHub Pages Disabled on Private `jutge-org/problem-editor`

- **What happened:** Enabling GitHub Pages via `gh api -X POST repos/jutge-org/problem-editor/pages -f build_type=workflow` failed with HTTP `422`: `"Your current plan does not support GitHub Pages for this repository."`
- **Cause:** `jutge-org/problem-editor` is currently `PRIVATE`, and the org's GitHub plan only supports Pages on `PUBLIC` repositories (or GitHub Team/Enterprise).
- **Workaround / Next action:** Kept `.github/workflows/pages.yml` committed on `jutge-org/problem-editor` (`main`) and verified identical Pages build/deployment on public `SuisSanem000/jutge-private`. Once `jutge-org/problem-editor` is made public (or upgraded), Pages will deploy automatically.
