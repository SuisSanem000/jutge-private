# How to Work with Claude Code in VS Code & Tomorrow's Meeting Guide

> **Location:** `doc/ai-analysis/delegate-to-claude/HOW-TO-USE-CLAUDE-CODE.md`  
> **Master Prompt:** [CLAUDE-MASTER-PROMPT.md](./CLAUDE-MASTER-PROMPT.md)  
> **Target Problem Folder:** [`work/problem-generation-claude-20261111/`](../../../work/problem-generation-claude-20261111/README.md)  
> **Meeting Proposal Document:** [`work/03-meeting-presentation-20261112/`](../../../work/03-meeting-presentation-20261112/PROPOSAL-PRESENTATION-20261112.md)

---

## 1. What Are We Doing & Why?

In `problem-editor/README.md`, your supervisor Pau Fernandez outlined the 4 project phases:

```text
Phase 1: Learn the problem format (spec/models, problem specifications)
Phase 2: Use the skills to generate new problems using an AI agent (Claude Code / VS Code)
Phase 3: Scaffold a website (Next.js)
Phase 4: Iterate and harden
```

You are executing **Phase 1 and Phase 2**. You have Claude Code installed as an active extension in your separate VS Code IDE with a paid plan. By delegating the problem generation to Claude Code using the master prompt, you will produce a complete, real Jutge problem (`dominant-peaks.pbm`) that compiles, runs, and passes grading checks via `jtk`.

---

## 2. Step-by-Step Instructions: Running Claude Code in VS Code

### Step 1: Open the Repository in VS Code
Open the root directory `jutge-private` in VS Code so that Claude has access to the full repository context.

### Step 2: Open the Claude Code Extension
1. Click the Claude icon in the VS Code Activity Bar (or open the Claude Code panel).
2. Ensure Claude is logged into your paid Anthropic account and ready to receive prompts.

### Step 3: Copy and Paste the Master Prompt
1. Open [**`CLAUDE-MASTER-PROMPT.md`**](./CLAUDE-MASTER-PROMPT.md).
2. Copy the entire prompt text inside the fenced code block.
3. Paste it into the Claude Code input box and press Enter.

### Step 4: Grant Workspace Tool Permissions
As Claude begins working, it will ask for permission to:
- Read workspace files (the translated specs in `doc/problem-editor-en-translate-20261111/` and the idea in `work/problem-generation-claude-20261111/`).
- Create directories and write files in `work/problem-generation-claude-20261111/dominant-peaks.pbm/`.
- Run terminal commands (if Claude Code command execution is enabled).

**Click "Allow" / "Approve"** for these actions.

### Step 5: What Claude Code Will Produce
Claude Code will scaffold the complete `.pbm` directory:

```text
work/problem-generation-claude-20261111/dominant-peaks.pbm/
├── handler.yml        # G++17 mode, 1.0s limit, source_modifier: none
├── problem.en.yml     # Metadata, title, author info
├── problem.en.tex     # LaTeX statement with formal description, input, output, sample tables
├── solution.cc        # Optimal O(N) Golden Solution adhering to C++17 constitution
├── solution-slow.cc   # Naive O(N^2) solution for limit verification
├── sample-1.inp       # Public test case 1 (from LaTeX statement)
├── sample-2.inp       # Public test case 2
├── generate.ts        # TypeScript testcase generator (correctness & efficiency)
└── scores.yml         # Grading schema (40% correctness, 60% efficiency)
```

---

## 3. Terminal Compilation & Verification

Once Claude Code finishes creating the files (or if you run the commands yourself in the VS Code terminal):

```bash
# 1. Navigate to the generated problem directory
cd work/problem-generation-claude-20261111/dominant-peaks.pbm

# 2. Make the test generator executable and run it to produce private test cases
chmod +x generate.ts
bun run generate.ts

# 3. Run jtk make to compile the golden solution and generate all .cor expected outputs
jtk make

# 4. Lint the problem folder to verify 0 style and formatting errors
jtk lint

# 5. Verify that the naive O(N^2) solution correctly fails with time-limit exceeded (EE)
jtk verify solution-slow.cc
```

### What If There Is a Compilation or Lint Error?
If `jtk make` or `jtk lint` outputs an error:
1. Copy the error message from your terminal.
2. Paste it back to Claude in the chat:  
   *"Running `jtk make` failed with this error: `[paste error]`. Fix the code while maintaining the C++17 pedagogical constitution."*
3. Claude will self-correct the file.
4. Re-run `jtk make`.

---

## 4. What to Tell Your Professors Tomorrow (November 12)

You are walking into the meeting with concrete results. Follow this 3-part presentation structure:

### Part 1: "What Did I Study?" (Phase 1)
> *"I studied the problem-editor repository and the Jutge problem creation ecosystem:*
> 1. *I analyzed the `.pbm` directory anatomy, `handler.yml` options, and compiler pipelines.*
> 2. *I mastered the C++17 Pedagogical Constitution: early exit on searches, no `std::unordered_map` or lambdas, and high-readability code.*
> 3. *I reviewed the 7 reference models to understand how `PRO2` and `G++17` problems differ in test generation and harnesses."*

### Part 2: "What Did I Implement?" (Phase 2 Demo)
> *"To validate Pau's Phase 2, I tested generating problems using Claude Code loaded with Pau's skill specifications:*
> 1. *I drafted an algorithm idea with $O(N)$ optimal complexity and $O(N^2)$ naive complexity.*
> 2. *Claude Code generated the full `.pbm` package: LaTeX statement, optimal `solution.cc`, naive `solution-slow.cc`, Bun test generator, and YAML configs.*
> 3. *I ran `generate.ts`, compiled it with `jtk make`, and verified that the slow solution fails the efficiency tests with time-limit exceeded.*
> 4. *Let me show you the generated files and run `jtk make` live right now."*

### Part 3: "Key Architectural Insight & The Proposal for Phase 3"
> *"My main engineering takeaway from executing Phase 2:*
> *Current `jtk` was built as a human CLI with interactive spinners and console output. When an agent or automated script runs it, error parsing is brittle because there is no machine-readable output (`--json`).*
>
> *For Phase 3 (the Next.js SaaS Web Editor), we need a decoupled core engine (`@jutge/core`) with a structured CLI / MCP API that returns machine-readable JSON diagnostics. This will allow the AI agent inside the web editor to self-correct automatically.*
>
> *I have prepared a 4-month architecture roadmap to build this engine, and I want to align with you today on git repository access and your priority features."*

---

## 5. Quick Links & Workspace Reference

- Master Prompt to Copy: [CLAUDE-MASTER-PROMPT.md](./CLAUDE-MASTER-PROMPT.md)
- Problem Idea: [`sample-problem-idea/IDEA.md`](../../../work/problem-generation-claude-20261111/sample-problem-idea/IDEA.md)
- Translated Constitution: [`spec/constitution.md`](../../problem-editor-en-translate-20261111/spec/constitution.md)
- Translated Problem Spec: [`spec/problem-spec.md`](../../problem-editor-en-translate-20261111/spec/problem-spec.md)
- Tomorrow's Presentation Proposal: [`PROPOSAL-PRESENTATION-20261112.md`](../../../work/03-meeting-presentation-20261112/PROPOSAL-PRESENTATION-20261112.md)
