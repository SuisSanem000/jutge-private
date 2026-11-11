# 03 — jtk architecture (verified against the code)

Repo: `resources/jutge_repos/jutge-toolkit`. Package `@jutge.org/toolkit` v4.4.50, Apache-2.0, ESM, Bun. 384 commits, 2026-01-08 to 2026-10-22 (Jordi Petit 354, Pau Fernández 29, one other).

## Entry and build

- `bin`: `jtk` and `jutge-toolkit` → `dist/index.js`; `jtk-dev` → `toolkit/index.ts` (run from source).
- `toolkit/index.ts` registers each command with `program.addCommand(...)` and calls `parseAsync()`. A global try/catch formats Zod errors and treats prompt cancel as a user cancel.
- Stack: commander + `@commander-js/extra-typings`, `@inquirer/prompts`, zod v4, yaml, handlebars, execa, chokidar, sharp.
- Quality tooling: ESLint (type-checked, but `no-explicit-any` and `no-unsafe-*` off), Prettier (4 spaces, no semicolons, width 120), strict TS. **No tests.**

## Commands (`toolkit/*.ts`)

| Command | Purpose |
|---|---|
| `make [tasks]` | Tasks `all\|info\|exe\|cor\|pdf\|txt\|md\|html`; `--watch` mode |
| `verify <programs>` | Run candidates against existing `.cor` files |
| `lint [-v]` | Static checks of a problem folder |
| `clean [-a] [-f\|-n]` | Delete disposable files (`-n` is parsed but unused) |
| `clone [template] [-d]` | Copy a template from `assets/problems/` |
| `generate problem\|translations\|statement\|solutions\|mains\|generators\|award.png\|award.html` | AI generation |
| `upload`, `remove`, `download`, `share` | Jutge.org API operations |
| `submit <programs>` | Submit to the judge; `-c` compiler, `-l` human language, `--no-wait`, `--no-browser`, `-a` |
| `stage` | Build a staged view of the problem |
| `metrics`, `quiz`, `convert`, `doctor`, `config`, `upgrade`, `completion`, `about` | Support |
| `ask [question]` | Sends `docs/*.md` and `toolkit/*.ts` plus the question to the LLM |
| `for-dummies` (alias `interactive`) | Menu-driven walk of the command tree |
| `compilers` | Developer mode only |

## lib/ modules

- `problem.ts`: the `Problem` model. Layouts: `.pbm` root ("multi") or a `<lang>/` subfolder ("single").
- `maker.ts`: compile, `.cor` generation, verify, PDF and text statements, games.
- `types.ts`: zod schemas (Handler, Scores, ProblemInfo, Settings, Quiz, Credentials).
- `lint.ts`, `stager.ts`, `upload.ts`, `submit.ts`, `download.ts`, `remove.ts`, `share.ts`, `cleaner.ts`, `doctor.ts`.
- `login.ts`, `settings.ts`, `versions.ts`, `tui.ts`.
- `aiclient.ts` (ChatBot, cost and energy estimates), `create-io.ts`, `create-funcs.ts`, `generate.ts`, `create-with-template.ts`.
- `quiz.ts`, `play-quiz.ts`, `order-prompt.ts`, `metrics.ts`, `zip-creation.ts`, `data.ts`, `helpers.ts`, `utils.ts`.
- Compilers live in the **top-level `compilers/` directory** (not `lib/`): `base.ts`, `index.ts` and one file each for gcc, gxx, python3, ghc, clojure, java, rust, r, verilog, pro2, make-pro2, run-python, run-haskell, run-clojure.

## Main flows

**`make all`:** load problem → `makeTarFiles` (PRO2 only) → compile golden solution → run it on every `.inp` to write `.cor` → verify each other `solution.*` → PDF statements (xelatex + Handlebars template) → text statements (pandoc + Lua filter). Work happens in `jtk-*` temp files. **No timeout or sandbox** (an infinite loop hangs `make`).

**`verify`:** picks the compiler from each program's own extension, runs all tests, compares byte for byte with `.cor`. Verdicts OK / WA / EE.

**`upload`:** zips the folder (excluding `jtk-*` and dotfiles, but keeping `public/.vscode` and `public/.clang-format`). If `problem.yml` exists, call `instructor.problems.update`, else `create` with a generated passcode. It streams the server output, matches `Problem X12345 created.`, and writes `problem.yml`.

**`submit`:** needs `problem.yml`; `problem_id = <problem_nm>_<language>`; checks the logged-in email matches `problem.yml`; polls every second for verdicts.

**`stage`:** copies files into `jtk-stage/`, **calls `jtk` recursively as a subprocess**, calls external `jutge-code-metrics`.

## Config and login

- jtk config: `envPaths('jutge', {suffix:'toolkit'})/config.yml` (`lib/settings.ts:7`), loaded by a top-level `await` on import.
- Credentials: `envPaths('jutge', {suffix:'cli'})` + `credentials.json` (`lib/login.ts:149`). This is **jutge-cli's file**, shared with jtk. On macOS it resolves under `~/Library/Preferences/jutge-cli/`.
- Order depends on the field: token = `JUTGE_TOKEN` env, then file. Email = `JUTGE_EMAIL` env, then file, then prompt. Password = file's saved password, then `JUTGE_PASSWORD`, then prompt.

## AI backend

There is no direct OpenAI or Gemini SDK. Every call goes through the Jutge.org API (`instructor.jutgeai.chat`), and the answer is streamed from `/webstreams/<id>`. Default model `openai/gpt-6-luna` (`lib/types.ts:201`). Images via `jutgeai.createImage`. Details in file 05.

## Compilers

`compilers/base.ts` defines `compileNormal`, `compileWithMain` (concatenate `main.<ext>` onto the source) and `execute`. Lookup by id and by extension in `compilers/index.ts`. Supported: C, C++, Python, Haskell, Clojure, Java, Rust, R, Verilog, PRO2, MakePRO2, and the Run* variants.
