---
name: jutge-problems
description: |
    Skill for when the user wants to create, draft, or modify Jutge.org 
    programming problems according to official specifications and pedagogical guidelines.
---

First, read the [Pedagogical Constitution & Guidelines](../../spec/constitution.md), which must always be complied with under all circumstances with maximum priority.

Next, read the [Jutge Problem Specification](../../spec/problem-spec.md) to understand the strict directory anatomy and required files.

## 1. Problem Creation Workflow

If the problem directory already exists, check whether the user has provided an `IDEA.md` file (`<problem-folder>/IDEA.md`). This file explains the problem idea, a sketch of the solution, the problem type, and the intended test cases.

Follow these steps:

1. **Create Problem Files:** Create all required files specified in the problem format document, following the exact structure:
   - `handler.yml`: Define compiler type (`G++17` or `PRO2`) and settings.
   - `problem.en.yml`: Title and author metadata.
   - `problem.en.tex`: Problem statement in LaTeX with preconditions, postconditions, and sample tables.
   - `solution.cc`: Golden solution adhering strictly to C++17 pedagogical rules (no forbidden features, early termination on searches).
   - `sample-1.inp`, `sample-2.inp`: Manual public test cases matching statement examples.
   - `public/`: (If `PRO2`) include `main.cc`, `Makefile`, `.clang-format`, and `.vscode/` configurations.
   - `scores.yml`: Define score distribution across test prefixes.

2. **Generate Private Test Cases:**
   - Create `generate.ts` with `#!/usr/bin/env bun` and executable permissions.
   - Run `bun run generate.ts` to produce `private-correctness-*.inp` and `private-efficiency-*.inp`.

3. **Validate with `jtk make`:**
   - Run `jtk make` to compile the solution, produce all `.cor` files, and build the LaTeX statement.
   - Inspect the command output to ensure there are zero compilation warnings, time limits are respected, and test outputs are generated.

## 2. Problem Modification Workflow

When modifying an existing problem:
1. Follow the user's specific instructions.
2. Ensure changes remain consistent with the problem specification.
3. Re-run `jtk make` to regenerate `.cor` files and ensure all tests continue to pass.

