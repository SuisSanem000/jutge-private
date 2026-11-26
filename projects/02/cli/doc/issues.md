# `pedit` CLI — Issues Log

## Table of Contents

- [2026-11-26 — Retired Default Model ID (`google/gemini-2.0-flash-lite-001`)](#2026-11-26--retired-default-model-id-googlegemini-20-flash-lite-001)
- [2026-11-26 — Missing `email` in Generated `problem.en.yml`](#2026-11-26--missing-email-in-generated-problemenyml)
- [2026-11-26 — LLM Echoing Protected `*.cor` Files on `pedit edit`](#2026-11-26--llm-echoing-protected-cor-files-on-pedit-edit)

---

## 2026-11-26 — Retired Default Model ID (`google/gemini-2.0-flash-lite-001`)

- **What happened:** First live OpenRouter call returned an error because `google/gemini-2.0-flash-lite-001` is no longer served on OpenRouter.
- **Fix:** Queried live OpenRouter `/api/v1/models` and updated `CHEAP_MODELS` / `DEFAULT_MODEL` in `pedit/src/ai.ts` to active low-cost/free models (`google/gemma-4-26b-a4b-it:free`, `openai/gpt-4o-mini`, `deepseek/deepseek-chat-v3-0324`).

## 2026-11-26 — Missing `email` in Generated `problem.en.yml`

- **What happened:** `jtk make all` failed Zod validation when `problem.en.yml` omitted `email`.
- **Fix:** Updated system prompt in `pedit/src/ai.ts` to explicitly require `title`, `author`, and `email` (placeholder `author@jutge.org`) for original-language `.yml` files, or translation keys for translations. Re-tested `pedit create` → passed in 1 attempt.

## 2026-11-26 — LLM Echoing Protected `*.cor` Files on `pedit edit`

- **What happened:** Passing existing sample files in context caused small models to echo `sample-1.cor` back inside `files`, triggering `assertSafeRelativePath` protection.
- **Fix:** Kept `assertSafeRelativePath` strict in `pbm.ts` while stripping `*.cor` and `problem.yml` keys returned by the LLM inside `runClosedLoopAi()` (`ai.ts`) so `jtk make` regenerates `.cor` files from `solution.cc`. Re-tested `pedit edit` → passed cleanly.
