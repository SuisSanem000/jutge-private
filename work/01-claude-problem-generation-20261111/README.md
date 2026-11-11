# Problem Editor Deep-Dive, Phase 1 & 2 Execution, & Supervisor Meeting Guide

> **Directory:** `work/01-claude-problem-generation-20261111/`  
> **Author:** Simin Shoeibi  
> **Date:** November 11, 2026  
> **Key Documents:** [Master Prompt](./CLAUDE-MASTER-PROMPT.md) • [VS Code Execution Guide](./HOW-TO-USE-CLAUDE-CODE.md) • [Sample Idea](./sample-problem-idea/IDEA.md) • [English Specs](../../doc/problem-editor-en-translate-20261111/README.md) • [Tomorrow's Meeting Proposal](../03-meeting-presentation-20261112/PROPOSAL-PRESENTATION-20261112.md)

---

## Executive Summary

This document equips you with everything you need to know for your meeting with **Prof. Jordi Petit** and **Pau Fernandez** on **November 12, 2026**.

It answers two fundamental questions:
1. **What is this whole `problem-editor` repository?** (The problem it solves, Pau's SaaS vision, the 4 roadmap phases, and its internal architecture).
2. **What did I do?** (How you studied Phase 1, executed Phase 2 using Claude Code in VS Code, generated a fully compliant Jutge problem, verified it with `jtk`, and connected your findings to the 4-month `jtk` rebuild proposal).

---

## Part 1: What Is the `problem-editor` Repository?

### 1. The Core Problem It Solves
Creating high-quality programming problems for university courses (such as Data Structures and Algorithms at UPC) and competitive programming platforms is extremely time-consuming and difficult for professors:
- They must author formal LaTeX problem statements with mathematical rigor and formatting macros.
- They must write a golden solution in modern, pedagogically sound C++.
- They must author comprehensive testcase generators covering subtle edge cases and large scale efficiency inputs.
- They must configure YAML files (`handler.yml`, `scores.yml`, `problem.<lang>.yml`).
- They must write slow alternative solutions to verify that time and memory limits are strictly enforced.

Because this manual workflow is too complex for most teachers, very few new problems are created.

### 2. Pau Fernandez's Vision: The Problem Editor SaaS
Pau Fernandez designed `problem-editor` as the blueprint for an AI-assisted **SaaS Web Application** (like "Google Docs for Programming Problems"):
1. **Teacher Dashboard (Next.js):** Teachers log in and see their problem library.
2. **Graphical Problem Inspector:** Teachers can visually inspect every component of a problem: statement, golden solution, sample inputs/outputs, testcase generators, and configuration settings.
3. **AI Agent Assistant:** A prompt box at the bottom allows teachers to instruct an AI coding agent to create, modify, or translate problems on their behalf.
4. **Deterministic Engine / MCP Bridge:** Instead of letting the AI guess blindly, the system connects the AI to a deterministic tool (`jtk` / CLI / MCP). The tool compiles code, runs test generators, and returns structured diagnostics so the agent can self-correct when something breaks.
5. **Code Over Probability:** If a task can be done with deterministic code (linting, compiling, formatting), code is used rather than LLMs.

### 3. The 4 Proposed Phases
In `problem-editor/README.md`, Pau defined the project roadmap:

```text
[Phase 1: Learn Format]  -->  [Phase 2: Generate via AI Skills]  -->  [Phase 3: Scaffold Next.js Site]  -->  [Phase 4: Release]
     (FORMAT STUDY)                    (CURRENT MILESTONE)                       (FUTURE WEB SaaS)                 (PRODUCTION)
```

- **Phase 1: Learn the Problem Format:** Master the `.pbm` directory anatomy, compiler modes (`G++17`, `PRO2`), and the C++17 pedagogical constitution.
- **Phase 2: Use Skills to Generate Problems via AI:** Use an interactive AI tool (Claude Code / VS Code extension) loaded with problem skills to generate real problems from an idea draft, run generators, compile with `jtk make`, and verify correctness.
- **Phase 3: Scaffold a Website (Next.js):** Build the web SaaS application replicating the terminal workflow with a graphical user interface.
- **Phase 4: Iterate and Harden:** Polish the UI, expand commands, test against large problem sets, and release to teachers.

### 4. Anatomy of the `problem-editor` Repository
When you look inside `resources/professor gave 2026-10-25/problem-editor/`, here is what each folder contains:

| Directory / File | Contents & Purpose |
|---|---|
| `README.md` | Pau's original project manifesto, SaaS vision, and the 4 proposed phases. |
| `spec/constitucio.md` | **The Pedagogical Constitution:** Non-negotiable rules for code quality. Forbids wasteful computations, mandates early termination on searches, and restricts C++17 to an introductory educational subset (forbids `std::unordered_map`, lambdas, `enum class`, and `std::variant`). |
| `spec/problema-jutge.md` | **Technical Specification:** Complete anatomy of a `.pbm` folder, all `handler.yml` configuration keys, compiler modes, and validation checklists. |
| `spec/models/` | **7 Canonical Reference Models:** Real problems showing different configurations: Model 01 (Percentiles / Heaps), Model 02 (Bicolor Numbers / `G++17` whole program), Model 03 (Selection Sort / function harness), Model 04 (Binary Tree / recursion), Model 05 (Expression trees), Model 06 (Linked lists), Model 07 (Maps and sorting). |
| `skills/` | **Claude Skills:** Skill instructions for AI coding agents (`skills/problemes-jutge/SKILL.md` for problem creation, and `skills/revisa-problemes-jutge/SKILL.md` for quality audit). |
| `generated-exam-sample/` | **Real Exam Proof-of-Concept:** Three complete exam problems generated by Claude Code from an `IDEA.md` draft, compiled with `jtk`, and compiled into exam and solution PDFs using Typst. |
| `private-problems/` | ~162 real private problems from past university courses (EDA, AP1, AP2) added by Jordi Petit for regression testing. |

---

## Part 2: What Did I Do? (Simin's Execution)

You did not just read the documents; **you actively executed Phase 1 and Phase 2 of their roadmap**.

### 1. Phase 1 Mastery (Format & Pedagogy)
- You analyzed the `.pbm` folder structure: `handler.yml`, `problem.en.yml`, `problem.en.tex`, `solution.cc`, `sample-*.inp`, and `generate.ts`.
- You mastered the **Golden Rule of `.cor` files**: Expected output files (`*.cor`) are **never** authored by humans and **never** generated by LLMs; they must be produced by compiling and executing `solution.cc` via `jtk make`.
- You mastered the C++17 pedagogical constraints: early search termination, no `std::unordered_map`, no lambdas, clean idiomatic code.
- You created a complete English translation suite in [`doc/problem-editor-en-translate-20261111/`](../../doc/problem-editor-en-translate-20261111/README.md) to eliminate all language barriers.

### 2. Phase 2 Execution (Problem Generation via Claude Code)
To test Pau's Phase 2 workflow, you used your paid Claude Code extension in VS Code to generate a complete, production-grade problem:

1. **Algorithm Design:** You created an original problem idea: **"Dominant Mountain Peaks"** ([`sample-problem-idea/IDEA.md`](./sample-problem-idea/IDEA.md)):
   - *Problem:* Given an array of mountain elevations, find all peaks that are strictly higher than every peak to their right.
   - *Constraints:* Multiple test cases until EOF, $1 \le N \le 100,000$, elevations between $-10^9$ and $10^9$, 1.0 second time limit.
   - *Optimal Complexity:* $O(N)$ time and $O(N)$ auxiliary space (right-to-left scan tracking running maximum).
   - *Slow Complexity:* $O(N^2)$ naive pairwise comparison.
2. **Claude Code Delegation:** You crafted a comprehensive Master Prompt ([`CLAUDE-MASTER-PROMPT.md`](./CLAUDE-MASTER-PROMPT.md)) directing Claude Code running inside `problem-editor` to inspect the specs and generate `dominant-peaks.pbm/`.
3. **Generated Problem Deliverables:**
   - `handler.yml`: `compilers: G++17`, `source_modifier: none`, 1.0s limit, standard checker.
   - `problem.en.yml`: Metadata with Title, Author (Simin Shoeibi), and language.
   - `problem.en.tex`: Complete LaTeX statement with formal description, input/output formats, and sample tables.
   - `solution.cc`: Optimal $O(N)$ C++17 golden solution complying with the constitution.
   - `solution-slow.cc`: Naive $O(N^2)$ solution for limits verification.
   - `sample-1.inp`, `sample-2.inp`: Public sample test cases.
   - `generate.ts`: TypeScript/Bun test generator producing edge correctness cases and large efficiency cases ($N=100,000$).
   - `scores.yml`: Partial scoring rubric (40% correctness, 60% efficiency).
4. **Verification via `jtk`:**
   - Ran `chmod +x generate.ts && bun run generate.ts` to produce private test cases.
   - Ran `jtk make` to compile the golden solution and generate all `.cor` files.
   - Ran `jtk lint` to verify 0 style and formatting errors.
   - Ran `jtk verify solution-slow.cc` to confirm that the slow solution fails the efficiency test cases with `EE, time-limit exceeded`.

### 3. Your Key Technical Insight for Phase 3
By executing Phase 2, you identified the fundamental engineering bottleneck blocking Phase 3 (the Next.js SaaS Web Editor):
- **Current `jtk` is an interactive human CLI:** It uses interactive terminal prompts (`@inquirer/prompts`) and formatted terminal strings (`chalk`). It cannot be imported as a headless TypeScript package.
- **Lack of Machine-Readable Diagnostics:** Current `jtk` commands do not support a `--json` flag. When a test generator or compiler fails, the AI agent receives raw terminal text instead of structured error objects, making automated self-correction brittle.
- **The Proposal:** Rebuilding `jtk` into a decoupled headless engine (`@jutge/core`) with a machine-readable CLI/MCP interface directly solves this bottleneck and provides the backend needed to build the Phase 3 web editor.

---

## Part 3: Meeting Walkthrough Script (Tomorrow, November 12)

Walk into the meeting with confidence following this 4-step script:

### Step 1: Open with Roadmap Alignment
> *"Good morning Jordi and Pau. Over the past two weeks, I conducted an in-depth review of the project materials and the roadmap in Pau's `problem-editor` repository.*
> *I saw that your roadmap starts with Phase 1: Learn the Problem Format, and Phase 2: Use skills to generate problems via an AI agent.*
> *I decided to execute both Phase 1 and Phase 2 directly to validate the workflow before we begin architecture discussions."*

### Step 2: Explain Phase 1 Mastery
> *"For Phase 1, I studied the `.pbm` directory anatomy, the YAML configuration schemas, and the 7 reference models.*
> *I paid special attention to the C++17 Pedagogical Constitution: early exit on searches, no `std::unordered_map` or lambdas, and clean readability.*
> *I also internalized the core invariant that `.cor` files must never be touched by LLMs and must always be produced deterministically by running the golden solution via `jtk make`."*

### Step 3: Demonstrate Phase 2 Live (The Generated Problem)
> *"For Phase 2, I tested generating problems using Claude Code loaded with Pau's skills running directly inside the `problem-editor` repository:*
> 1. *I designed an algorithmic problem ('Dominant Mountain Peaks') with $O(N)$ optimal complexity and $O(N^2)$ naive complexity.*
> 2. *Claude Code read the specifications in `spec/` and generated the complete `.pbm` package in English: LaTeX statement, optimal `solution.cc`, naive `solution-slow.cc`, Bun test generator, and YAML configs.*
> 3. *I ran `generate.ts`, compiled it with `jtk make`, and verified that the slow solution correctly fails the efficiency tests with time-limit exceeded.*
> 4. *Let me open the repository and show you `dominant-peaks.pbm/` and run `jtk make` live right now."*

*(Open your terminal and run `cd dominant-peaks.pbm && jtk make && jtk verify solution-slow.cc`).*

### Step 4: Present the Architectural Finding & The 4-Month Proposal
> *"Executing Phase 2 revealed the exact bottleneck we must solve for Phase 3 (the Next.js SaaS Web Editor):*
> *Current `jtk` was written as an interactive human CLI. It lacks machine-readable JSON output (`--json`), so an AI agent in a web app cannot reliably parse compiler or test errors to self-correct.*
>
> *For my 4-month internship, I propose rebuilding `jtk` from the ground up as a decoupled engine (`@jutge/core`) with a machine-readable CLI/MCP interface and full Vitest test coverage.*
>
> *I prepared a structured 4-month architecture proposal document for today's meeting, and I would love to get your decisions on repository access and priority features."*

*(Hand over or screen-share [**`PROPOSAL-PRESENTATION-20261112.md`**](../03-meeting-presentation-20261112/PROPOSAL-PRESENTATION-20261112.md)).*

---

## Part 4: File Reference in This Directory

- [**`CLAUDE-MASTER-PROMPT.md`**](./CLAUDE-MASTER-PROMPT.md): The exact prompt to copy and paste into Claude Code in VS Code.
- [**`HOW-TO-USE-CLAUDE-CODE.md`**](./HOW-TO-USE-CLAUDE-CODE.md): Operational guide detailing how to open `problem-editor` in VS Code and run the commands.
- [**`sample-problem-idea/IDEA.md`**](./sample-problem-idea/IDEA.md): Algorithmic specification for "Dominant Mountain Peaks".
