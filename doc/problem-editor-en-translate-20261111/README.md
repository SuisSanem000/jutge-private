# Problem Editor — Complete English Specification & Overview

> **Source:** Translated and structured from `resources/professor gave 2026-10-25/problem-editor/`  
> **Date:** November 11, 2026  
> **Target Audience:** Senior Software Engineer executing Phases 1 & 2.  
> **Navigation:** [Root Workspace](../../README.md) • [Phase 1 & 2 Execution Guide](../../work/01-claude-problem-generation-20261111/README.md) • [Constitution Spec](./spec/constitution.md) • [Problem Spec](./spec/problem-spec.md)

---

## 1. What Is `problem-editor`?

`problem-editor` is the repository provided by Pau Fernandez and Prof. Jordi Petit on October 25, 2026. It contains the official specifications, pedagogical rules, Claude Code skills, and sample reference models for creating Jutge.org programming problems using an AI agent.

### The Goal
Creating high-quality programming problems by hand (writing formal statements, LaTeX formulas, golden solutions, testcase generators, and YAML configurations) is tedious and difficult for university professors. The goal is to develop an application that makes it trivial for teachers to create, verify, and publish new problems on Jutge.org.

---

## 2. Proposed System Architecture (Pau's Vision)

Pau outlined the target product as a **SaaS Web Application** (like "Google Docs for Problems"):
1. **Teacher Web Interface (Next.js):** Teachers log in, see a list of their problems, and visually inspect each part (statement, solutions, wrong submissions with expected verdicts, test cases, generators).
2. **AI Agent Chat Box:** A bottom prompt box sends instructions to an AI agent (preloaded with problem specifications and skills) that operates directly on the problem files.
3. **Deterministic CLI / MCP Engine:** The AI agent does not blindly guess; it interacts with a command-line tool that returns explicit success/failure diagnostics per command so the agent can self-correct when code or tests fail.
4. **Code over Probability:** Where simple deterministic code can do the job (like linting, compiling, formatting), code is used instead of AI.

---

## 3. The 4 Proposed Phases

Pau structured the project into four sequential phases:

```
[Phase 1: Learn Problem Format]  ->  [Phase 2: Generate Problems via AI Skills]  ->  [Phase 3: Scaffold Next.js Site]  ->  [Phase 4: Release]
         (STUDY & SPECS)                          (CURRENT MILESTONE)                         (FUTURE WEB SaaS)                 (PRODUCTION)
```

1. **Phase 1: Learn the Problem Format (CURRENT)**  
   Master the strict file anatomy of a `.pbm` directory, the compiler modes (`G++17`, `PRO2`, `MakePRO2`), the YAML metadata schemas, and the pedagogical C++17 rules.
2. **Phase 2: Use Skills to Generate New Problems (CURRENT)**  
   Use an interactive AI tool (like Claude Code or the Claude VS Code extension) loaded with the problem skills to create problems from an `IDEA.md` file, run the test generator, compile with `jtk make`, and verify correctness.
3. **Phase 3: Scaffold a Website (Next.js)**  
   Build a modern Next.js web application that replicates the terminal workflow and displays a clean visual representation of the problem to the teacher.
4. **Phase 4: Iterate and Harden**  
   Refine the UI, expand commands, improve test validation, and harden the system for production release.

---

## 4. Translated Folder & Specification Map

Every file in the original repository has been translated into pure English with identical directory structure:

| Original Document in Repository | Translated English Document | Purpose |
|---|---|---|
| Original Constitution Specification | [**`spec/constitution.md`**](./spec/constitution.md) | Pedagogical rules, C++17 allowed/forbidden features, code elegance, concept DAGs. |
| Original Problem Specification | [**`spec/problem-spec.md`**](./spec/problem-spec.md) | Exhaustive `.pbm` file anatomy, `handler.yml`, `scores.yml`, limits, compiler modes. |
| Original Reference Models Directory | [**`spec/models-guide.md`**](./spec/models-guide.md) | Walkthrough of the 7 reference model problems. |
| Original Problem Creation Skill | [**`skills/jutge-problems/SKILL.md`**](./skills/jutge-problems/SKILL.md) | Claude Code skill instructions for creating/modifying problems from `IDEA.md`. |
| Original Problem Review Skill | [**`skills/review-jutge-problems/SKILL.md`**](./skills/review-jutge-problems/SKILL.md) | Claude Code skill instructions for reviewing problem quality and consistency. |

---

## 5. Other Repositories Included in `problem-editor`

*   **`generated-exam-sample/`:** Three real exam problems (binary trees, priority queues, map of heaps) generated using Claude Code from an `IDEA.md` draft, compiled with `jtk`, and rendered into exam and solution PDFs using Typst.
*   **`private-problems/`:** ~162 real private problems from past university courses (EDA, AP1, AP2) used for grading validation.
