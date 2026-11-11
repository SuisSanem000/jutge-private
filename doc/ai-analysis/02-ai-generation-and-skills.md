# 05 — AI generation and the problem-editor vision

## A. `jtk generate` today (verified)

- All LLM calls go through the Jutge API; there is no direct provider SDK. `ChatBot` keeps a message history and retries 3 times; if all fail it returns the literal `'Failed to get response'`, which then gets written into files.
- **Open loop:** nothing generated is compiled, run or checked. The README that jtk writes even refers to the legacy command `jutge-make-problem`.
- Flags (`toolkit/generate.ts`): `-k/--kind io|funcs` (default io), `-i/--input` spec YAML, `-n/--do-not-ask` (only works with `-i`), `-d/--directory` (must end in `.pbm` and not exist), `-o`, `-m/--model`.
- **io pipeline** (`lib/create-io.ts`): statement → 2 sample tests → 2 private tests → solutions → translations → generators → README. Context is pruned with `bot.forgetLastInteraction()` (lines 153, 156, 160, 161, 163, 304, 325, 343) to keep the prompt small.
- **io spec keys:** `title`, `description`, `author`, `email`, `golden_proglang`, `more_proglangs`, `original_language`, `more_languages`, `generators`.
- **Files written:** `problem.<lang>.tex/.yml` for the original and each translation, `sample-1/2.inp`, `test-1/2.inp`, `solution.<ext>` per language, `generate-<type>.py` (random, hard, efficiency; Python only), `handler.yml`, `README.md`, `.gitignore`. **No `.cor`.**
- **funcs kind:** different spec (adds `specification`; no `more_proglangs` or `generators`). Writes `sample.inp`, `test-<func>.inp`, `sample.dt`, and `scores.yml` when there are several functions; sets `handler.compilers` to RunPython, RunHaskell or RunClojure.
- **Cost report in README:** from `jutgeai.getLlmUsage()`, euros with 21% VAT, plus estimates of energy, CO2 and water.
- **Models** (`docs/jutge-ai.md`): gemini-2.5-flash-lite, flash, pro; openai/gpt-6-luna (default), gpt-6-sol.
- Prompts: `assets/prompts/` (io, funcs, examples, ask). `creators/system-prompt.txt` is unused.

## B. problem-editor (from Pau Fernandez, 2026-10-22; Jordi Petit, 2026-10-27)

Repo `jutge-org/problem-editor`. Contents: `README.md`, `spec/` (constitution, problem spec, 7 model problems), `skills/` (8 Claude-Code style skills), `generated-exam-sample/`, `private-problems/` (about 162 real problems: eda 12, ap1 87, ap2 63; "not to be distributed").

**Vision (README):**
1. A SaaS web app "like Google Docs": sign in, list your problems, download and upload problem folders easily.
2. A graphical editor, increasing in detail: statement, solution, wrong submissions with verdicts, test cases, generators, settings.
3. A prompt box feeding an AI agent that has the skills and specs and edits the problem files.
4. The agent drives a **CLI that reports success or failure per command** so it can self-correct. Commands = aspects of a problem the user can change, plus test-case checks.
5. If something is easy in plain code, do it in code (remove the probabilistic part).

**Phases (README):** learn the format → generate problems with skills in Claude Code, opencode or pi → scaffold a Next.js site doing the same as the terminal → iterate to release.

**Problem skills:** The problem-creation skill (creates or modifies a problem from an optional `IDEA.md`, then runs `generate.ts` and `jtk make`) and the problem-review skill (review checklist). **Topic skills** (topic research, canonical examples, topic concepts, topic specification, review topic) are for course notes; the README says to ignore them. `__OLD__` is deprecated.

**Generated sample:** three PRO2 exam problems (trees, priority queue, map of heaps) made with Claude Code from `IDEA.md` files, then uploaded and turned into an exam PDF and a solutions PDF (Typst).

## C. How the two fit

| | `jtk generate` | problem-editor skills |
|---|---|---|
| Driver | One-shot LLM calls via Jutge API | Interactive agent in Claude Code with specs |
| Feedback | none | agent runs `jtk make`, `verify` |
| Languages | io/funcs, C++ and Python | C++ (G++17, PRO2) |
| Format knowledge | prompts in `assets/prompts/` | Problem specification document plus models |

The professors' target (agent + CLI with per-command success/failure + web UI) implies a `jtk` that is **scriptable**: stable machine-readable output, exit codes, no interactive prompts when not needed, and core logic separated from terminal UI. That is a design input for the rewrite, not yet a decision.

## D. Proposal carried over from the old docs (labelled as proposal)

Closed-loop generation: compile and run generated solution and inputs, and feed errors back to the model before saving. It fits the professors' "CLI reports success/failure" idea. It is **not** implemented.
