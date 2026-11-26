# Phase 02 — `pedit` CLI & PDF Problem Viewer

> **Current Focus:** Build **`pedit`** (AI-assisted Jutge problem editor CLI) + a minimal local web PDF problem viewer on top of unmodified `jtk`.

## Table of Contents

- [Working Copy Workflow](#working-copy-workflow)
- [Build Order (After Plan Confirmation)](#build-order-after-plan-confirmation)

Phase 02 implements the two post-Nov 12 priorities:

1. [**`cli/`**](./cli/readme.md) — `pedit` CLI wrapping unmodified `jtk` (`4.4.50`), common `.pbm` editing helpers, and OpenRouter SDK integration.
2. [**`pdf-viewer/`**](./pdf-viewer/readme.md) — Minimal local web PDF & problem viewer (`Bun.serve`) to demonstrate problems visually.

---

## Working Copy Workflow

- All implementation code will live inside `projects/02/problem-editor/` (copied cleanly without `.git` from `resources/`). Only `resources/private-local/` remains local/gitignored.
- Once Phase 02 features are built and verified locally, Simin will manually copy/replace them into her upstream `problem-editor` GitHub repository.

---

## Build Order (After Plan Confirmation)

1. **`pedit` deterministic CLI + `jtk` JSON wrapper** (`projects/02/problem-editor/pedit/`).
2. **PDF Problem Viewer** (`projects/02/problem-editor/viewer/`).
3. **OpenRouter SDK + skill-backed `pedit edit`** (separating long specs/skills from the user's short idea/edit prompt).
