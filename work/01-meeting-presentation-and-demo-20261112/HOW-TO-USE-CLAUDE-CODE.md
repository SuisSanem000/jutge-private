# How to Run Claude Code Inside `problem-editor` & Meeting Guide

> **Location:** `work/01-meeting-presentation-and-demo-20261112/HOW-TO-USE-CLAUDE-CODE.md`  
> **Master Prompt:** [CLAUDE-MASTER-PROMPT.md](./CLAUDE-MASTER-PROMPT.md)  
> **Master README:** [README.md](./README.md)  
> **Original Problem Editor Path:** `resources/professor gave 2026-10-25/problem-editor/`  
> **Meeting Proposal Document:** [PROPOSAL-PRESENTATION-20261112.md](./PROPOSAL-PRESENTATION-20261112.md)

---

## 1. Why Running Claude Inside `problem-editor` Is the Best Strategy

You are running Claude Code with the **`problem-editor`** folder opened as your VS Code workspace root.

This gives you three huge advantages:
1. **Clean Context Window:** Claude Code sees only the problem specifications (`spec/`), reference models (`spec/models/`), and authoring skills (`skills/`). There is zero noise or distraction from other Jutge repositories or workspace notes.
2. **Exact Skill Alignment:** Pau Fernandez authored the skill files using paths relative to the `problem-editor` root (e.g. `/spec/constitucio.md`). Running Claude directly inside `problem-editor` matches Pau's intended execution environment 100%.
3. **Direct Supervisor Demonstration:** Tomorrow, you can open Pau's own repository and show `dominant-peaks.pbm/` living directly inside `problem-editor`, demonstrating Phase 1 & 2 completion in its native environment.

---

## 2. Step-by-Step Instructions in VS Code

### Step 1: Open `problem-editor` in VS Code
Open a new VS Code window and choose **File > Open Folder...**, then select:
```text
resources/professor gave 2026-10-25/problem-editor/
```

### Step 2: Open the Claude Code Extension
1. Open the Claude Code panel or chat window in VS Code.
2. Confirm you are logged into your paid Claude subscription.

### Step 3: Copy and Paste the Master Prompt
1. Open [**`CLAUDE-MASTER-PROMPT.md`**](./CLAUDE-MASTER-PROMPT.md).
2. Copy the entire prompt text inside the fenced code block.
3. Paste it into the Claude Code chat window in your `problem-editor` VS Code session and press Enter.

### Step 4: Approve File Creation Permissions
Claude Code will:
- Read `spec/constitucio.md` and `spec/problema-jutge.md` (and translate the Catalan specifications).
- Inspect the reference models in `spec/models/`.
- Consult the authoring instructions in `skills/problemes-jutge/SKILL.md`.
- Ask for permission to create the directory `dominant-peaks.pbm/` and write the problem files.

Click **"Allow" / "Approve"** for each file.

### Step 5: What Gets Created Inside `problem-editor/dominant-peaks.pbm/`
```text
dominant-peaks.pbm/
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

Open your terminal inside VS Code (or your system terminal) and run:

```bash
# 1. Enter the generated problem directory
cd dominant-peaks.pbm

# 2. Make the test generator executable and run it to produce private test cases
chmod +x generate.ts
bun run generate.ts

# 3. Run jtk make to compile the golden solution, generate .cor files, and build the PDF
jtk make

# 4. Lint the problem folder to verify 0 style and formatting errors
jtk lint

# 5. Verify that the naive O(N^2) solution correctly fails with time-limit exceeded (EE)
jtk verify solution-slow.cc
```

### Self-Correction Loop (If Errors Occur)
If `jtk make` or `jtk lint` outputs a compilation warning or error:
1. Copy the terminal error output.
2. Paste it back into Claude Code:  
   *"Running `jtk make` gave this error: `[paste error]`. Please fix the issue while maintaining the C++17 pedagogical constitution."*
3. Claude Code will edit the code, and you can re-run `jtk make`.

---

## 4. What to Tell Your Supervisors Tomorrow (November 12)

Present your work in the meeting using this crisp 3-part script:

### Part 1: "What Did I Study?" (Phase 1)
> *"I reviewed your roadmap in the `problem-editor` repository. For Phase 1:*
> 1. *I studied the `.pbm` directory anatomy, `handler.yml` options, and compiler pipelines.*
> 2. *I mastered the C++17 Pedagogical Constitution: early exit on searches, no `std::unordered_map` or lambdas, and high-readability code.*
> 3. *I reviewed the 7 reference models in `spec/models/` to understand how `PRO2` and `G++17` problems differ in test generation and harnesses."*

### Part 2: "What Did I Implement?" (Phase 2 Demo)
> *"For Phase 2, I tested generating problems using Claude Code running directly inside your `problem-editor` repository loaded with your skills:*
> 1. *I designed an algorithmic problem ('Dominant Mountain Peaks') with $O(N)$ optimal complexity and $O(N^2)$ naive complexity.*
> 2. *Claude Code read your Catalan specifications in `spec/` and generated the complete package in English: LaTeX statement, optimal `solution.cc`, naive `solution-slow.cc`, Bun test generator, and YAML configs.*
> 3. *I ran `generate.ts`, compiled it with `jtk make`, and verified that the slow solution fails the efficiency tests with time-limit exceeded.*
> 4. *Let me show you `dominant-peaks.pbm/` right here in your repository and run `jtk make` live."*

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
- Problem Idea Specification: [`sample-problem-idea/IDEA.md`](./sample-problem-idea/IDEA.md)
- Translated Constitution Spec: [constitution.md](../../doc/problem-editor-en-translate-20261111/spec/constitution.md)
- Translated Problem Spec: [problem-spec.md](../../doc/problem-editor-en-translate-20261111/spec/problem-spec.md)
- Tomorrow's Presentation Proposal: [PROPOSAL-PRESENTATION-20261112.md](./PROPOSAL-PRESENTATION-20261112.md)
