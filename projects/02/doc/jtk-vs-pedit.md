# How `pedit` Differs from `jtk`

## Table of Contents

- [Summary](#summary)
- [Side-by-Side Comparison](#side-by-side-comparison)
- [Technical Role of Each Tool](#technical-role-of-each-tool)

## Summary

- **`jtk` (`@jutge.org/toolkit` v4.4.50):** Remains unchanged; handles deterministic compiling, `.cor` generation, PDF building, linting, and Jutge.org uploads.
- **`pedit`:** Sits on top of `jtk` to provide interactive AI editing, model selection, hidden skills, and automatic verification retries.

## Side-by-Side Comparison

| Dimension | `jtk` (Existing) | `pedit` (New CLI) |
|---|---|---|
| **Primary Role** | Build, test, PDF, lint, upload | AI-assisted problem authoring & editing |
| **LLM Provider** | Fixed Jutge API (`openai/gpt-6-luna`) | OpenRouter SDK (default `openai/gpt-4o-mini`; Jutge API later) |
| **Workflow** | One-shot `jtk generate` (open-loop) | Conversational `edit` / `chat` + preset commands |
| **Prompts / Rules** | Hardcoded in CLI | Hidden master prompts loaded from `spec/` & `skills/` |
| **Verification** | Manual (`jtk make` / `lint` run separately) | Closed-loop (`jtk` runs automatically with 2 auto-fix retries) |

## Technical Role of Each Tool

- **`jtk` owns:** `solution.cc` compilation, `*.cor` generation, `jtk lint`, `jtk verify`, `jtk upload`, `jtk submit`.
- **`pedit` owns:** Reading `.pbm` context, applying presets (`add-edge-tests`, `add-slow-solution`, `tighten-constraints`, `translate-es`, `translate-ca`, `fix-lint`), blocking unsafe `*.cor`/`problem.yml` writes, and calling `jtk` after every edit.
