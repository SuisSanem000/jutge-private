# Guide to Reference Model Problems

> **Source:** Translated and analyzed from `resources/professor gave 2026-10-25/problem-editor/spec/models/`  
> **Purpose:** Reference implementations demonstrating exact file structures for different problem categories.  
> **Navigation:** [Problem Editor Master README](../README.md) • [Constitution Spec](./constitution.md) • [Problem Spec](./problem-spec.md)

---

## The 7 Reference Models

The `problem-editor/spec/models/` directory provides seven canonical reference problems created by the professors to illustrate different compiler modes, data structures, and grading setups:

| Model | English Title | Problem Type | Core Concept Demonstrated |
|---|---|---|---|
| `Model 01` (Percentiles) | **Percentile Queries** | `PRO2` (Function) | Multi-file problem using `public/` harness, heaps/priority queues, and Doxygen function specifications. |
| `Model 02` (Bicolor) | **Bicolor Numbers** | `G++17` (Whole Program) | Standard input/output algorithm problem with `source_modifier: none`. |
| `Model 03` (Selection Sort) | **Selection Sort Step** | `G++17` (Function) | `source_modifier: no_main`, function merged with teacher's `main.cc`. |
| `Model 04` (Binary Tree) | **Longest Path in Binary Tree** | `PRO2` (Tree Structure) | Binary trees (`BinTree<T>`), recursion, early termination, and complex test generation. |
| `Model 05` (Expressions) | **Print Arithmetic Expressions** | `PRO2` (Parsing & Trees) | Expression trees, formatting, precedence handling, and `.ops` limit overrides. |
| `Model 06` (Pairs List) | **List of Pairs** | `PRO2` (Linked Lists) | Linked list manipulation, pointer safety, and invariant preservation. |
| `Model 07` (Winners) | **Tournament Winners** | `G++17` (Simulation & Maps) | Standard library containers (`std::map`, `std::vector`), sorting, and tie-breaking. |

---

## Key Lessons from Inspecting the Models

1. **How `public/` Works in `PRO2`:**  
   In models 01, 04, 05, and 06, notice the `public/` directory contains `main.cc`, `Makefile`, `.clang-format`, and `.vscode/` so students can test their code locally before submitting.
2. **How `generate.ts` is Structured:**  
   Each model contains a clean TypeScript script with functions:
   * `generatePublic()`: Small sample tests for statement examples.
   * `generateCorrectness()`: Boundary tests (empty, single element, negative numbers).
   * `generateEfficiency()`: High-volume tests ($N = 10^5$) that cause naive solutions to timeout.
3. **How `scores.yml` is Configured:**  
   Models divide scores by test prefix (e.g. `correctness` vs `efficiency`), ensuring students get partial points for working logic even if their algorithm is slow.
