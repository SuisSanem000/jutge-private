# 04 — Problem format (.pbm) and grading

Sources: jtk code (`lib/types.ts`, `lib/problem.ts`, `lib/lint.ts`), jtk `docs/problem-anatomy.md`, `problem-editor/spec/problema-jutge.md`, `jutge-driver-std/std/judge.py`.

## Folder anatomy

A problem is a folder ending in `.pbm`. Two layouts exist: **flat** (preferred, all languages in one folder) and **per-language subfolders** (`ca/`, `en/`, legacy, discouraged). Many old problems in `private-problems/` use the legacy layout.

| File | Required | Meaning |
|---|---|---|
| `handler.yml` | yes | Problem type and checker options (below) |
| `problem.<lang>.yml` | yes, one per language | Original: `title`, `author`, `email`. Translation: `title`, `translator`, `translator_email`, `original_language`. Languages: en, ca, es, fr, de |
| `problem.<lang>.tex` | yes | Statement; lint requires `\Problem{` and `\Statement` |
| `solution.<ext>` | yes | Golden solution (chosen by `handler.solution` or `compilers`); other `solution-*` files are alternatives or wrong solutions |
| `*.inp` | yes | Test inputs. Name with `sample` = shown in the statement; names starting `public`, `hint`, `distilled` are public |
| `*.cor` | generated | Expected output. Made by `jtk make` from the golden solution. Never by hand or LLM |
| `problem.yml` | written by upload | `problem_nm`, `email`, `passcode`, sharing, timestamps. Never create by hand |
| `scores.yml` | optional | List of `{part, prefix, points}`; each part scores the tests whose name starts with `prefix` |
| `<test>.ops` | optional | `--maxtime`, `--maxmem`, `--maxfiles`, `--maxprocs`, `--maxoutput`, `--maxcore`. Lint demands one when a `.cor` is 2 MB or more |
| `main.<ext>`, `public/`, `private/`, `solution/` | optional | Code templates and PRO2 trees (become `.tar`) |
| `award.png`, `award.html`, `sample.dt`, `checker.*` | optional | Awards, function-call samples, external checker |
| `tags.yml` | ignored | Deprecated; jtk never reads it (problem-editor still creates it) |
| generator files | not run by `make` | e.g. `generate-*.py`, `generate.ts` must be run by hand before `make` |

## handler.yml keys (zod `Handler`)

`handler` (std, graphic, quiz, circuits, game), `solution` (default `C++`), `source_modifier` (none, no_main, structs; structs deprecated and mapped to no_main), `compilers` (single word), `func_name`, `hide_html`, `invisible_main`, `time_factor[1..3]`, `time_constant[1..3]`, `checker` (std, loosy, epsilon, elastic, elastic2, external) with `epsilon`, `relative`, `separator*`, `starting`, `ending`, `external_program`, `presentation_error`, `tolerance`, `pylibs`, `inspector`, `game.hide`.

Note: docs mention `external_timeout`, which the zod schema lacks.

## Problem types (problem-editor view, C++ focus)

| `compilers` | Student sends | Notes |
|---|---|---|
| `G++17` | One `.cc` | `source_modifier`: `none` (whole program), `no_main` (function merged with `main.cc`), `structs` |
| `PRO2` | One `.cc` or `.hh` | Build: copy `public/`, add the submission, let `private/` overwrite, run `make` |
| `MakePRO2` | A `.tar` with its own Makefile | No model problem exists yet |

The private corpus is mostly Python (`solution: Python3`, `RunPython`) plus quiz and graphic types. No Haskell was found in it. Codon appears.

## Lint rules (`lib/lint.ts`)

Valid `handler.yml` and `problem.yml`; at least one language; a `.tex` per language; one original language with an author; consistent `original_language`; at least one `solution.*` and one `.inp`; each `.inp` has a `.cor`; no orphan `.cor`; test name regex; `.ops` syntax and the 2 MB rule; sample/`\Sample` consistency (`lib/lint.ts:431-457`, triggered by any `.inp` whose name contains `sample`).

## Grading on the server

1. The queue runs `docker run --rm -i --network none --cpus=1 --memory=1g jutgeorg/<image> jutge-submit <name>` on a worker over SSH.
2. `jutge-submit` reads a tar from stdin, runs `jutge-start` (timeout 320 s), sanitizes `correction/`, returns it as a tgz.
3. `jutge-start` unpacks `submission.tgz`, `problem.tgz`, `driver.tgz` and runs `driver/judge.py`.
4. `judge.py` reads `problem.yml`, `handler.yml`, optional `scores.yml`, `submission.yml`, `driver.yml`. Option lookup order: submission, problem, driver, handler. Phases: init, pylibs, solution (runs the reference to measure time), correction. Each phase does preprocess, compile, execute, check, evaluate, postprocess.
5. It uses every `*.inp` (public first) with its `*.cor`, optional `.ops`, `solution.tar`, `checker.cc`. The time limit is the solution's CPU time times `time_factor` plus `time_constant`.
6. Verdicts go to `correction/correction.yml`.

**Consequence for a rewrite:** the driver defines what a valid problem is. Any new tool must keep emitting exactly these files and keys.

## Known inconsistencies in the spec material

- problem-editor says the slow solution must be 5x slower in the body but 3x in its checklist.
- It says "3 languages" but lists two; the model tables say `driver` where the YAML key is `handler`.
- `.ops` examples mix units (`--maxoutput=4` and `=5MB`).
- Missing referenced files: `spec/templates/*.md`, `spec/SPEC.md`.
