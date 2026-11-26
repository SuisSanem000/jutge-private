---
name: review-jutge-problems
description: |
    Skill for reviewing and validating one or more Jutge.org programming problems 
    for consistency, pedagogical standards, correctness, and completeness.
---

First, read the [Pedagogical Constitution & Guidelines](../../spec/constitution.md) and the [Problem Specification](../../spec/problem-spec.md).

## Problem Review Checklist

A Jutge problem consists of many tightly coupled components. Review every section carefully:

### 1. Problem Type & Configuration
* Verify that `handler.yml` settings (`compilers`, `source_modifier`) match the actual files present.
* For `PRO2` problems, verify that the `public/` directory contains `main.cc`, `Makefile`, `.clang-format`, and `.vscode/` (`tasks.json`, `launch.json`).
* Run `jtk make` to check for configuration incompatibilities.

### 2. Problem Statement Review
* **Clarity:** Verify that input and output formats are unambiguous (e.g. tie-breaking rules when sorting).
* **Mathematics & Formulas:** Check that mathematical formulas and LaTeX syntax render cleanly.
* **Code Fragments:** Ensure all code examples in LaTeX match the actual golden solution code.
* **Sample Consistency:** Verify that `sample-1.inp` and sample tables in `problem.en.tex` match exactly.

### 3. Solution Code Review
* **Elegance:** Verify variable and function names are clean, intuitive, and readable.
* **Pedagogical Constraints:** Confirm that forbidden C++ features (lambdas, `unordered_map`, `string_view`, destructuring, exceptions) are NOT used.
* **Early Termination:** Confirm that all loops and searches abort immediately once the result is known.
* **Formatting:** Run `clang-format -i solution.cc` if formatting is not clean.

### 4. Generator Review (`generate.ts`)
* Verify the file has `#!/usr/bin/env bun` and executable permissions.
* Verify test sizes are controlled via named constants at the top, not magic numbers.
* Verify tests are split into correctness (edge cases, small sizes) and efficiency ($N = 10^5$).

### 5. Limits & Scoring (`scores.yml`, `.ops`)
* If any output exceeds 2 MB, verify a `<test>.ops` file exists with `--maxoutput=XMB`.
* Verify `scores.yml` contains prefixes that match the generated private tests.
* Ensure test descriptions in `scores.yml` do NOT give away hints that make the problem trivial.

