# TASK 01 — Analyse everything in the problem-editor folder

**Status:** NOT STARTED
**Created:** 2026-11-03

## Goal
Analyse everything in the problem-editor material that the professors gave Simin, and produce:
1. Study files Simin can learn from (`study/`).
2. Files Simin can send to the professor about the study (`for-professor/`).

## Input (read only; never modify `resources/`)
`resources/professor gave 2026-10-25/problem-editor/`
- `README.md` (vision and phases), `spec/` (`constitucio.md`, `problema-jutge.md`, `models/` 7 reference problems)
- `skills/` (8 skills; topic skills are marked "ignore" by the README; `__OLD__` is deprecated)
- `generated-exam-sample/` (3 PRO2 problems, exam PDFs, Typst solutions)
- `private-problems/` (eda 12, ap1 87, ap2 63; "not to be distributed")
- Context: `doc/ai-analysis-20261103/` files 04, 05 and 06 (a first pass already exists; go deeper and verify).

## Scope
- Understand every file type and convention. Read the real files, do not rely only on the summary in file 05.
- Compare the spec with the real problems and with what jtk and the grading driver accept (jtk `lib/lint.ts`, `lib/types.ts`; `jutge-driver-std/std/judge.py`).
- Evaluate the skills and the vision (agent + CLI + web editor) and what it means for the jtk rewrite.
- Do **not** redistribute private-problems content in `for-professor/` beyond short quoted excerpts needed as evidence. Passcodes found in `problem.yml` files must not be copied.

## Deliverables
`study/` (for Simin, plain B2 English): overview map, format guide with examples from real problems, skills explained, what the sample exam shows, glossary of Catalan terms used, how it relates to jtk.
`for-professor/` (formal): report with findings, inconsistencies in the spec (with file references), coverage gaps (Python, quiz, graphic, MakePRO2), security note about committed passcodes, proposals for the jtk rewrite, and open questions. See `for-professor/README.md` for the outline.

## Known starting points (from the first pass, to verify)
- Spec inconsistencies: 5x vs 3x slow solution; "3 languages" lists two; `driver` vs `handler`; `generator.ts` vs `generate.ts`; missing `spec/templates/*` and `spec/SPEC.md`.
- Sample exam: P3 `scores.yml` does not nest correctness tests in the efficiency group; P2 has no `scores.yml`.
- Five `problem.yml` files contain non-empty `passcode:` values.
- No MakePRO2 model; no Haskell in the corpus.

## How to execute
Follow the protocol in `doc/README.md`. Write only in this folder. When done, set the status above to DONE and update `doc/ai-analysis-20261103/01-project-state.md`.
