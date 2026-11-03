# 06 — Observations for the jtk rewrite

Observations only. Not a design. Each item was read in the code of `resources/jutge_repos/jutge-toolkit` (v4.4.50). Items marked *not tested* were not run.

## Structural problems

- **No tests at all.** `.gitignore` mentions `tests/problems`, which does not exist.
- **No core/UI separation.** `tui` calls are mixed into the logic, which makes it hard to test and to drive from an agent.
- **Import side effects.** `lib/settings.ts` does file I/O through a top-level `await` on import.
- **`stage` shells out to `jtk`** recursively and to external `jutge-code-metrics`.
- **No timeout or sandbox** when running compiled solutions.
- `eslint` and `bun-types` are in runtime `dependencies`; `no-explicit-any` and `no-unsafe-*` are disabled.
- `lib/jutge_api_client.ts` is about 6k lines of generated code.

## Duplication

- Golden-solution lookup: `problem.load`, `problem.reloadSolutions`, `stager.findGoldenSolution`.
- `proglangNames` exists twice and disagrees (`hs: 'GHC'` in `data.ts`, `'Haskell'` in `stager.ts`). So `handler.solution: Haskell`, which the docs list as valid, throws in `problem.ts`.
- `getDefinedCompilerIds` twice (copy in `types.ts` is dead).
- Compile block copy-pasted in `makeExecutable` and `verifyCandidate`; PDF and text statement builders are mostly the same.
- `loadSpecificationCore` and `generateReadme` nearly identical in `create-io.ts` and `create-funcs.ts`.
- `ensureProblemYml` in both `submit.ts` and `share.ts`.

## Bugs and inconsistencies

| Where | Issue |
|---|---|
| `lib/maker.ts:278` | `selectCompiler()` uses the golden solution's extension. `makeExecutable` calls it for every solution, so `jtk make exe` with golden `solution.cc` and an alternative `solution.py` compiles the `.py` with g++. `make all` is not affected (alternatives go through `verifyCandidate`, which uses each program's own extension). |
| `generate statement` | Reads `assets/prompts/examples/statement.tex` and `io/examples/io-statement-coda.tex`; neither exists, so it should crash. Help text says `statement.<lang>.tex`, code writes `problem.<lang>.tex`. |
| `getIOPromptForProglang` (`helpers.ts`) | Looks for `io-${proglangName}.md`, which never exists; `generate solutions` and `generate mains` get an empty language prompt. |
| `generateTestCasesGenerator` | Passes the same prompt as system and user message. |
| `addStatementTranslation` | Does not write `original_language`, so lint then warns about its own output. |
| `stageAwards` | Copies `award.txt` instead of `award.html`. |
| `clean -n` | Parsed but unused. |
| Text statements | Author read from the translation yml ("Unknown"); PDFs read it from the original. |
| `submit` compiler ids | Compiler `id()` values like `GXX` and `Java` differ from Jutge's ids; only `GXX`→`G++17` is remapped, so `.java` likely submits as `Java` instead of `JDK` (*not tested*). |
| ChatBot failure | Returns `'Failed to get response'` and the text is saved into generated files. |
| `settings.notifications`, `code-metrics/index.ts` | Unused / dummy stub. |
| `create-io` | Sets `doNotAsk = true` in a path where it has no effect. |
| Docs vs code | `quiz` is documented as developer-only but always registered; `external_timeout` documented, absent from the schema. |

## Things worth preserving

- The `.pbm` format and the lint rules (they encode driver expectations).
- The `make` pipeline order and temp-file approach (`jtk-*`).
- zod schemas as the single source of truth for YAML files.
- `forgetLastInteraction` style context pruning for long generation chains.
- Cost, energy and water reporting for AI use.
- Shell completion, `doctor`, `for-dummies`.
- Watch mode in `make`.

## Gaps relative to the professors' goals (from the 2026-10-22 meeting and problem-editor README)

- No machine-readable output or per-command success/failure contract for an agent.
- No closed-loop generation.
- No notion of wrong submissions with expected verdicts (EDA problems have an `ac*/wa*/ee*` naming pattern that could be used).
- Generators are not run by `make` (problem-editor runs `generate.ts` by hand first).
- No support in the spec material for Python, quiz, graphic problem types, though most private problems use them.
