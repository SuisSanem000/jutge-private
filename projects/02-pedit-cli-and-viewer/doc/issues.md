# Phase 02 — Issues Log

## Table of Contents

- [CLI Issues](#cli-issues)
- [PDF & Viewer Issues](#pdf--viewer-issues)
- [GitHub Pages & CI Issues](#github-pages--ci-issues)

## CLI Issues

| Date | Issue | Resolution |
|---|---|---|
| 2026-11-26 | `google/gemini-2.0-flash-lite-001` retired on OpenRouter | Switched `CHEAP_MODELS` / default to `openai/gpt-4o-mini` |
| 2026-11-26 | `jtk make` failed Zod check when `problem.en.yml` omitted `email` | Updated `ai.ts` prompt to require `title`, `author`, and `email` |
| 2026-11-26 | Small models echoed protected `*.cor` keys on `pedit edit` | Stripped `*.cor` / `problem.yml` from LLM writes in `ai.ts` so `jtk make` regenerates `.cor` |

## PDF & Viewer Issues

| Date | Issue | Resolution |
|---|---|---|
| 2026-11-26 | `jtk make pdf` exited `0` with `Error in LaTeX` (`moreverb.sty` missing in macOS BasicTeX) | Added `pedit/src/pdf.ts` to verify `.pdf` creation and fall back to headless Chrome HTML-to-PDF |

## GitHub Pages & CI Issues

| Date | Issue | Resolution |
|---|---|---|
| 2026-11-26 | `jutge-org/problem-editor` returned HTTP `422` enabling Pages (private org plan) | Created public safe mirror `SuisSanem000/pedit-demo` for live Pages |
