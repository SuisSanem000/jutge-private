# AI Problem Generation: Current CLI vs. Future Problem Editor

> **Document Role:** Architectural and technical analysis of how AI is used in Jutge.  
> **Audience:** Senior Software Engineer onboarding to the project.  
> **Navigation:** [Root Workspace](../../README.md) • [Senior Developer Brief](./01-senior-dev-brief.md) • [jtk Architecture](./03-jtk-architecture.md) • [Problem Format](./04-problem-format-and-grading.md)

---

## 1. What Is This Document & Why Does It Exist?

To understand your 4-month internship mandate, you need to understand the **core conflict** between how Jutge generates problems with AI today, and how the professors want it to work in the future:

1. **Today's Tool (`jtk generate`):** A rigid, command-line tool built into the existing `jutge-toolkit` that asks an LLM for code, never compiles it, and dumps raw text files directly onto your hard drive.
2. **Tomorrow's Vision (`problem-editor`):** An interactive SaaS web application where teachers talk to an AI Coding Agent that drafts problems, runs compilers and test generators in the background, catches errors, and self-corrects automatically.

The purpose of this document is to analyze both approaches, expose why the current tool fails, and define the engineering bridge you will build during your internship.

---

## 2. Approach 1: How `jtk generate` Works Today (The Legacy Tool)

In the existing TypeScript codebase (`resources/jutge_repos/jutge-toolkit/`), there is a command called `jtk generate problem`.

### The Execution Pipeline
When a teacher runs this command:
1. **Interactive Prompt:** The CLI asks the teacher for a title, description, programming languages (e.g. C++, Python), and human languages.
2. **LLM Calls via Jutge API:** The CLI does not use direct OpenAI or Anthropic SDKs. Instead, it sends requests through Jutge's backend API (`api.jutge.org/api/instructor/jutgeai/chat`).
3. **Sequential Generation Chain:**
   * It asks the LLM to write the formal statement in LaTeX (`problem.<lang>.tex`).
   * It asks for 2 public sample test inputs (`sample-1.inp`, `sample-2.inp`).
   * It asks for 2 private test inputs (`test-1.inp`, `test-2.inp`).
   * It asks for reference solutions (`solution.cc`, `solution.py`).
   * It asks for Python test generator scripts (`generate-random.py`, `generate-hard.py`).
4. **Writes Files to Disk:** It writes all these files into a new `.pbm` directory and prints an estimated carbon/energy/token cost report.

### Why the Current Tool Is Broken ("Open-Loop")
* **Zero Compilation or Verification:** The CLI never compiles the generated C++ code. It never executes the test generators. It never checks if the sample inputs match the problem description.
* **Garbage In, Files Out:** If the LLM produces a syntax error or hallucinated library, the CLI writes it straight to disk anyway. If an API call times out, it literally writes the raw string `'Failed to get response'` into the code file.
* **No Correct Output (`.cor`):** It does not generate `.cor` files because it never executes the golden solution. The teacher is left to manually debug and fix whatever broken files the LLM generated.

---

## 3. Approach 2: The Future Vision (Pau's Problem Editor & Agent Skills)

Professor Jordi Petit and Pau Fernandez realized that rigid, one-shot CLI commands do not produce reliable educational problems. In late October 2026, Pau launched the `problem-editor` initiative (`resources/professor gave 2026-10-25/problem-editor/`).

### How Pau Tested the Concept
Instead of hardcoding generation logic in TypeScript, Pau tested using an **interactive AI coding agent** (such as Claude Code or Antigravity):
1. **Specification Preloading:** The agent is given strict domain rules:
   * Pedagogical guidelines and C++17 rules (efficiency, no cryptic code, restricted standard library subset).
   * Exact file anatomy and YAML schemas of a `.pbm` folder.
2. **Skill Instructions (`SKILL.md`):** Pau wrote markdown instructions that teach the agent how to:
   * Read an idea sketch (`IDEA.md`).
   * Draft the LaTeX statement, golden solution, and test generator scripts.
   * Run terminal commands (`generate.ts` and `jtk make`) to compile the code and build `.cor` files.
3. **Proof of Concept:** Pau successfully generated three real exam problems (covering binary trees, priority queues, and heaps) using this workflow.

### The Long-Term Vision (The SaaS Problem Editor)
As described in Pau's README:
* A modern SaaS web app (built with Next.js) where teachers log in, view their problems, and edit them visually.
* A bottom chat box where teachers prompt an AI agent to adjust the problem (e.g., *"Make the constraints tighter and add tests with empty arrays"*).
* The AI agent performs the file edits on behalf of the user.

---

## 4. The Architectural Gap: Why Your Internship Exists

Pau's vision hits a major roadblock: **The current `jtk` CLI cannot support an AI agent or web SaaS.**

In the `problem-editor` README, Pau wrote:
> *"The system will be much more robust and trustworthy if the AI interacts with a CLI that will report on the success or failure of each command, so that the AI can correct mistakes and get feedback on each step."*

### Why Current `jtk` Fails as an Agent Backend
1. **No Machine-Readable Output:** `jtk` prints colored human terminal text. It does not provide a `--json` flag with structured error diagnostics (e.g. `{ error_type: "compile_error", line: 42, message: "..." }`).
2. **Interactive Prompts Block Headless Execution:** If a setting is missing, `jtk` prompts the terminal for input (`@inquirer/prompts`), hanging automated agent processes.
3. **No Execution Sandboxing:** Running `jtk make` executes student/reference binaries directly on the host with no timeouts; an infinite loop locks the entire process.

---

## 5. Architectural Comparison: Current vs. Target

| Architectural Dimension | Current Tool (`jtk generate`) | Future Target (`problem-editor` + `jtk v5`) |
|---|---|---|
| **Driver / Controller** | Monolithic TypeScript CLI script | Interactive AI Agent + Next.js SaaS Web UI |
| **Execution Loop** | **Open-Loop:** Dumps raw LLM output to disk without compiling or testing. | **Closed-Loop:** Automatically compiles code, runs generators, and verifies outputs before saving. |
| **Feedback & Self-Correction** | None. Teacher must manually fix errors. | Immediate structured JSON feedback allows the AI agent to fix its own bugs in a retry loop. |
| **Supported Problem Types** | Basic C++ and Python I/O programs only. | C++ (standard and multi-file), Python, quizzes, graphics. |
| **CLI / Engine Contract** | Interactive human terminal UI only. | Headless core library (`@jutge/core`) + scriptable CLI (`--json`) + optional MCP server. |

---

## 6. What This Means for Your Implementation Work

Your primary internship mandate—**rebuilding `jtk` into a decoupled, testable engine**—directly provides the missing foundation:
* By extracting pure authoring logic into `@jutge/core`, you allow both the CLI and the future Next.js web app to share the exact same problem validation logic.
* By adding a standardized `--json` output flag and deterministic exit codes, you give Pau's AI agent the exact feedback loop it needs to draft, compile, test, and package problems without human intervention.
