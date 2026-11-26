# `pedit` CLI

> Implemented in `projects/02/problem-editor/pedit/` wrapping unmodified `jtk` (`4.4.50`).

## Table of Contents

- [Overview & Architecture](#overview--architecture)
- [Commands](#commands)
- [OpenRouter & Skills Integration](#openrouter--skills-integration)
- [Verification Results](#verification-results)
- [Related Docs](#related-docs)

---

## Overview & Architecture

- `src/index.ts` — CLI router (`--json`, `--dir`, `--model`, `--preset`, `--lang`, `--include-private`).
- `src/jtk.ts` — Subprocess wrapper for `jtk make`, `jtk make pdf`, `jtk lint`, `jtk verify`, `jtk clean`, and `bun run generate.ts`.
- `src/pbm.ts` — `.pbm` discovery/inspection, deterministic `meta`/`handler` editors, and guarded writes (never writes `*.cor` or `problem.yml`).
- `src/pdf.ts` — Runs `jtk make pdf`, detects BasicTeX `Error in LaTeX` silently exiting `0`, and renders missing PDFs via Chrome headless fallback.
- `src/ai.ts` — `@openrouter/sdk` integration with hidden skills/specs and up to 2 automatic closed-loop self-correction retries.

---

## Commands

```bash
cd projects/02/problem-editor/pedit && bun install

bun run src/index.ts list [--dir ..] [--json]
bun run src/index.ts status <problem.pbm> [--json]
bun run src/index.ts show <problem.pbm> [file] [--json]

bun run src/index.ts build <problem.pbm> [--json]
bun run src/index.ts pdf <problem.pbm> [--json]
bun run src/index.ts lint <problem.pbm> [--json]
bun run src/index.ts verify <problem.pbm>
bun run src/index.ts clean <problem.pbm>

bun run src/index.ts meta <problem.pbm> --lang en --title "..." --author "..." --email "..."
bun run src/index.ts handler <problem.pbm> --compilers G++17

bun run src/index.ts models [--json]
bun run src/index.ts presets [--json]
bun run src/index.ts create <dir.pbm> "<idea>" [--model openai/gpt-4o-mini] [--json]
bun run src/index.ts edit <dir.pbm> ["<instruction>"] [--preset add-edge-tests] [--json]
bun run src/index.ts chat <dir.pbm>
```

---

## OpenRouter & Skills Integration

- Reads `OPENROUTER_API_KEY` from environment or `.env`, with automatic fallback to `ANTHROPIC_AUTH_TOKEN` when `ANTHROPIC_BASE_URL` targets OpenRouter.
- Low-cost models listed in `CHEAP_MODELS`: `openai/gpt-4o-mini` (default), `google/gemini-2.5-flash-lite`, and `deepseek/deepseek-chat-v3-0324`.
- Preloads `spec/constitucio.md`, `spec/problema-jutge.md`, and `skills/problemes-jutge/SKILL.md` behind the scenes so prompts stay short.

---

## Verification Results

- `bun test` (`tests/pedit.test.ts`): **2 passed, 0 failed** (13 assertions covering write guards, metadata/handler updates, and `.pbm` discovery).
- Live OpenRouter `pedit create` (`openai/gpt-4o-mini`): Created `projects/02/problem-editor/generated-demo/sum-evens.pbm` cleanly (`jtk make` + `jtk lint` + PDF build passed in 1 attempt).
- Live OpenRouter `pedit edit`: Added `sample-3.inp` with negative integers (`jtk make` generated `sample-3.cor` and `jtk lint` passed with 0 issues).

---

## Related Docs

- [How `pedit` Differs from `jtk`](./jtk-vs-pedit.md)
- [CLI Issues Log](./issues.md)
