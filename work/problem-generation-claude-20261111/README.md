# Phase 1 & Phase 2 Execution Guide (Claude Code in VS Code)

> **Date:** November 11, 2026  
> **Objective:** Execute Phase 1 (Format Mastery) and Phase 2 (Problem Generation with Claude Code) from the professors' roadmap.  
> **Navigation:** [Root Workspace](../../README.md) • [Claude Master Prompt](../../doc/ai-analysis/delegate-to-claude/CLAUDE-MASTER-PROMPT.md) • [Claude Execution Guide](../../doc/ai-analysis/delegate-to-claude/HOW-TO-USE-CLAUDE-CODE.md) • [Sample Idea](./sample-problem-idea/IDEA.md) • [Problem Editor English Specs](../../doc/problem-editor-en-translate-20261111/README.md)

---

## 1. Why This Is the Perfect Agenda for Tomorrow's Meeting

In the `problem-editor/README.md`, Pau Fernandez explicitly defined the project roadmap:

```
Phase 1: Learn the problem format (spec/models, problem specifications)
Phase 2: Use the skills to generate new problems using an AI agent (Claude Code / VS Code)
Phase 3: Scaffold a website (Next.js)
Phase 4: Iterate and harden
```

By focusing on **Phase 1 and Phase 2**, you are executing **exactly what the professors asked for in their own repository**. Tomorrow, you can walk into the meeting and say:

> *"I reviewed your roadmap. I mastered Phase 1 by studying the `.pbm` specifications and reference models, and for Phase 2, I tested generating problems using Claude Code with your skill instructions. Here is a real problem I generated, compiled, and verified using `jtk`."*

---

## 2. How to Run Phase 2 in VS Code (Step-by-Step)

You have the Claude extension installed in VS Code with a paid plan. Follow these steps:

### Step 1: Open the Project in VS Code
Open the root `jutge-private` directory in VS Code.

### Step 2: Open the Claude Extension Chat
1. Open the Claude extension sidebar in VS Code.
2. Ensure Claude has access to the workspace files.

### Step 3: Copy and Paste the Master Prompt
1. Open [**`CLAUDE-MASTER-PROMPT.md`**](../../doc/ai-analysis/delegate-to-claude/CLAUDE-MASTER-PROMPT.md) (or [**`CLAUDE-CODE-PROMPT.md`**](./CLAUDE-CODE-PROMPT.md)).
2. Copy the entire prompt block.
3. Paste it into the Claude chat window and press Enter.

### Step 4: What Claude Will Do Automatically
Claude will:
1. Read the translated specifications in `doc/problem-editor-en-translate-20261111/`.
2. Read the sample problem idea in `work/problem-generation-claude-20261111/sample-problem-idea/IDEA.md`.
3. Scaffold the complete problem folder at `work/problem-generation-claude-20261111/dominant-peaks.pbm/`:
   - `handler.yml` (G++17 configuration)
   - `problem.en.yml` (metadata)
   - `problem.en.tex` (LaTeX statement with preconditions and sample tables)
   - `solution.cc` (optimal C++17 solution)
   - `solution-slow.cc` (naive $O(N^2)$ solution for limit verification)
   - `sample-1.inp`, `sample-2.inp` (public sample test cases)
   - `generate.ts` (testcase generator script)
   - `scores.yml` (grading schema)

### Step 5: Compile and Verify with `jtk`
Open your VS Code terminal and run:

```bash
# 1. Navigate to the generated problem folder
cd work/problem-generation-claude-20261111/dominant-peaks.pbm

# 2. Make the generator executable and generate private test cases
chmod +x generate.ts
bun run generate.ts

# 3. Compile the golden solution and generate all .cor expected output files
jtk make

# 4. Lint the problem folder to ensure 0 errors
jtk lint

# 5. Verify that the slow solution fails the efficiency tests (EE, time-limit exceeded)
jtk verify solution-slow.cc
```

---

## 3. What You Show to Professors Tomorrow

During the meeting on November 12th:
1. **Show the generated folder:** Show `dominant-peaks.pbm/` with clean LaTeX statements and working C++ code.
2. **Demonstrate `jtk make`:** Run `jtk make` live to show that the code compiles, generates `.cor` files, and passes `jtk lint`.
3. **Discuss Phase 3 (Next Steps):** Ask Jordi and Pau how they want to structure the Next.js SaaS scaffold for Phase 3!

