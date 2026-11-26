# `pedit` CLI — Plan

> **Core rule:** Keep `jtk` (`4.4.50`) completely unchanged. `jtk` acts as the deterministic tool/MCP backend; `pedit` is the new problem-editor CLI built around it.

## Table of Contents

- [Goal](#goal)
- [Problem-Editing Operations Catalog](#problem-editing-operations-catalog)
- [What We Build First (MVP Step 1)](#what-we-build-first-mvp-step-1)

---

## Goal

Give teachers and AI agents a scriptable CLI inside `projects/02/problem-editor/pedit/` to inspect, edit, verify, and AI-update `.pbm` problem folders with structured `--json` feedback.

---

## Problem-Editing Operations Catalog

1. **Inspect:** `list` problems in a folder, `status` (files, languages, `.cor`/`.pdf` state), and `show` (`handler.yml`, statement, solution, samples).
2. **Statement & Metadata:** Edit `problem.<lang>.yml` (title, author, translation flags), `problem.<lang>.tex`, and multi-language files.
3. **Solutions & Handler:** Edit `handler.yml` (problem type, compiler, tolerances, checkers), `scores.yml`, `solution.<ext>`, and `solution-*.<ext>`.
4. **Tests & Generators:** Edit `sample-*.inp`, `private-*.inp`, `generate.ts`, and `.ops` limits (`*.cor` is always regenerated via `jtk make`, never hand-written).
5. **Build & Verify Wrappers:** Run `jtk make`, `jtk make pdf`, `jtk verify`, `jtk lint`, and `jtk clean` and return clean `--json` results + exit codes.
6. **AI-Assisted Edit (`pedit edit "<request>"`):** Use **OpenRouter SDK** (DeepSeek v4 default, selectable model, routable to Jutge API later) with specs/skills loaded from `spec/` and `skills/` so the user prompt stays short and focused only on the edit or problem idea.

---

## What We Build First (MVP Step 1)

1. Scaffold a Bun/TypeScript CLI (`pedit`) in `projects/02/problem-editor/pedit/`.
2. Implement deterministic `jtk` wrappers + inspection commands (`list`, `status`, `build`, `pdf`, `verify`, `lint`) with `--json` output and helper commands for common `.pbm` edits.
3. Add OpenRouter SDK integration (`OPENROUTER_API_KEY` in gitignored `.env`) + skill loader for `pedit edit`.
