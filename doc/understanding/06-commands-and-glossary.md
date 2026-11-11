# 07 — Commands cheat sheet and glossary

Commands were checked against `toolkit/*.ts`. Terminal output is **not** shown here because it was never verified.

## Normal flow

```bash
jtk doctor                                   # check compilers, xelatex, pandoc
jtk config show                              # view config
jtk generate problem -k io -d my-problem.pbm # AI draft (asks interactively)
cd my-problem.pbm
jtk make                                     # compile golden, write .cor, build statements
jtk lint                                     # structure checks
jtk verify solution.py                       # check an alternative solution
jtk clean
jtk upload                                   # creates or updates the problem, writes problem.yml
jtk submit -l en solution.cc                 # submit to the judge
```

## Headless generation

```yaml
# spec.yml (io kind)
title: Lily and the Prime Flowers
description: ...
golden_proglang: cc
original_language: en
more_proglangs: [py]
more_languages: [fr, de]
generators: [hard, random, efficiency]
```

```bash
jtk generate problem -k io -i spec.yml -n -d lily-primes.pbm
```

`-n` only works together with `-i`. The directory must end in `.pbm` and must not exist.

## Corrections to old commands

| Old doc | Correct |
|---|---|
| `jtk submit -l cc solution.cc` | `-l` is the human language (default `en`). Use `-c <compiler>` for the compiler, else it auto-detects from the extension. |
| `jtk clone demo -d x.pbm` | `jtk clone demo/demo.pbm -d x.pbm` (`demo` is a category folder; templates live in `assets/problems/<category>/<name>.pbm`). |
| Credentials in `~/.config/jutge/credentials.json` | Shared jutge-cli file under `envPaths('jutge',{suffix:'cli'})`. |

Template categories: circuits, demo, function, games, graphic, quizzes, standard.

## Glossary

| Term | Meaning |
|---|---|
| `.pbm` | Problem folder |
| golden solution | The reference solution that defines correct output |
| `.inp` / `.cor` | Test input / expected output (generated, never hand-written) |
| sample | Public test shown in the statement |
| `handler.yml` | Problem type and checker settings |
| `problem.yml` | Server-assigned identity (`problem_nm`, passcode); written by upload |
| `scores.yml` | Partial scoring by test-name prefix |
| `.ops` | Per-test limits |
| PRO2 | Compiler mode for multi-file C++ problems (`public/`, `private/`) |
| `no_main` | The student writes functions; a `main` is merged in |
| AC / WA / EE / PE | Accepted / Wrong answer / Execution error (including time limit) / Presentation error |
| JutgeAI | The LLM service behind the Jutge API |
| IDEA.md | Free-form problem idea used by the problem-editor skills |
| skill | A Claude-Code style instruction file (`SKILL.md`) |
