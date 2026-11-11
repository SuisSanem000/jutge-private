# Ready-to-Copy Master Prompt for Claude Code (VS Code)

> **How to use:** Copy the prompt below and paste it directly into your Claude extension chat in VS Code.

```text
You are an expert AI problem creator for Jutge.org. 
Your task is to create a complete, production-grade Jutge problem directory named `dominant-peaks.pbm/` based on the idea file provided at `work/problem-generation-claude-20261111/sample-problem-idea/IDEA.md`.

Before writing any code, strictly review the official specifications in this repository:
1. Pedagogical Guidelines: `doc/problem-editor-en-translate-20261111/spec/constitution.md`
2. Problem Specification: `doc/problem-editor-en-translate-20261111/spec/problem-spec.md`
3. Skill Instructions: `doc/problem-editor-en-translate-20261111/skills/jutge-problems/SKILL.md`

Generate all required files inside `work/problem-generation-claude-20261111/dominant-peaks.pbm/`:

1. `handler.yml`:
   - Set `compilers: G++17`
   - Set `source_modifier: none`
   - Configure reasonable time factors and standard checker.

2. `problem.en.yml`:
   - Title: "Dominant Mountain Peaks"
   - Author: "Simin Shoeibi"
   - Email: "simin.shoeibi@estudiantat.upc.edu"

3. `problem.en.tex`:
   - Formal LaTeX problem statement using `\Problem{...}` and `\Statement{...}`.
   - Include sections for Description, Input, Output, and formatted sample tables.

4. `solution.cc`:
   - The optimal $O(N)$ Golden Solution in C++17.
   - Must adhere to the Pedagogical Constitution (no `unordered_map`, no lambdas, early termination where applicable).
   - Format cleanly with standard naming conventions.

5. `solution-slow.cc`:
   - A naive $O(N^2)$ alternative solution to verify that efficiency testcases properly trigger a time-limit exceeded verdict.

6. `sample-1.inp` and `sample-2.inp`:
   - Public sample inputs exactly matching the examples provided in the LaTeX statement.

7. `generate.ts`:
   - Executable TypeScript generator with shebang: `#!/usr/bin/env bun`
   - Generates private correctness tests (`private-correctness-1.inp`, `private-correctness-2.inp`) for edge cases (single elements, identical heights, negative numbers).
   - Generates private efficiency tests (`private-efficiency-1.inp`, `private-efficiency-2.inp`) with $N = 100,000$ to challenge algorithmic complexity.

8. `scores.yml`:
   - Define partial grading: 40% for `correctness` prefix and 60% for `efficiency` prefix.

After creating these files, provide the exact terminal commands to:
1. Run `bun run generate.ts` to generate the test cases.
2. Run `jtk make` inside `dominant-peaks.pbm/` to compile the golden solution, generate expected `.cor` outputs, and build the LaTeX PDF.
3. Run `jtk verify solution-slow.cc` to confirm that the slow solution fails on the efficiency tests as expected.
```

