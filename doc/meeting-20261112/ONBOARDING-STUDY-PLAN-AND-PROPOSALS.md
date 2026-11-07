# Senior Developer Onboarding, 4-Hour Study Plan & Meeting Proposals

> **Context:** 4-month Jutge internship (UPC).  
> **Target Date:** Supervisor meeting on **November 12th** with Prof. Jordi Petit and Pau Fernández.  
> **Audience:** Senior Software Engineer with zero prior Jutge knowledge.

---

## 1. Executive Context (Domain & System Model)

*   **What is Jutge.org?**  
    An automated judge and learning platform used across Catalonia (primarily UPC) for university computer science courses and competitive programming. Students submit code (C++, Python, Haskell, etc.); backend workers compile and execute submissions inside isolated Docker containers and return verdicts (`AC` Accepted, `WA` Wrong Answer, `EE` Execution/Timeout Error).
*   **What is `jtk` (`@jutge.org/toolkit`)?**  
    The CLI authoring tool that professors use to create, compile, test (`make`, `verify`), generate LaTeX/PDF problem statements, and upload problems to the Jutge API. It was recently migrated from Python to Bun/TypeScript by Jutge creator Jordi Petit.
*   **What is the "Problem Editor" project?**  
    Writing robust problems by hand (LaTeX statements, YAML metadata, golden solutions, edge-case test generators, time-limit tuning) is slow and tedious for professors. Pau Fernández and Jordi Petit want a modern system:
    1. An **AI Agent** equipped with problem-creation skills and strict specifications.
    2. A **scriptable CLI / MCP interface** that executes commands and returns deterministic machine-readable feedback (JSON / exit codes) so the agent can self-correct when code or tests fail.
    3. A **Next.js SaaS web editor** where professors can visualize, edit, and prompt the agent.
*   **Your 4-Month Internship Mandate:**  
    Current `jtk` has severe technical debt: **zero automated tests**, business logic tightly coupled with interactive CLI/TUI prompts, open-loop AI generation (dumps raw LLM text into files without compiling or running tests), and no sandboxing or timeouts during local builds. Your core mission is to **re-architect `jtk` into a decoupled, testable engine with a scriptable CLI/MCP interface** that powers this AI-assisted Problem Editor.

---

## 2. Workspace Structure (Zero-Duplication Policy)

To avoid duplicating large external repositories while maintaining clean version control:

```
jutge-private/
├── README.md            # Root navigation guide: explains where to look
│
├── resources/           # [UPSTREAM / READ-ONLY REFERENCE - MANAGED ONLY BY SIMIN]
│   ├── jutge_repos/     # Git clones of jutge-toolkit, drivers, web apps, etc.
│   └── professor gave 2026-10-25/problem-editor/  # Pau's problem-editor upstream repo
│   (Simin updates this folder via git pull. AI NEVER touches this folder.)
│
├── doc/                 # [KNOWLEDGE BASE & MEETING DELIVERABLES]
│   ├── README.md                        # Documentation index
│   ├── SENIOR-DEV-BRIEF.md              # 15-minute senior dev onboarding brief
│   ├── meeting-20261112/                # This folder: meeting prep & study plans
│   │   └── ONBOARDING-STUDY-PLAN-AND-PROPOSALS.md
│   ├── ai-analysis-20261103/            # Verified technical deep-dive (specs, architecture, debt)
│   ├── task-01-problem-editor-analysis/ # Problem-editor audit
│   └── task-02-meeting-20261022-next-steps/ # Action registry & meeting prep
│
└── work/                # [ACTIVE DEVELOPMENT & CODE]
    ├── README.md        # Work log and branch tracking
    └── (poc / modules)  # Your clean code, prototypes, and PR staging candidates
```

---

## 3. Prioritized 4-Hour Study Plan

You have **4 hours** total to ramp up. Do not read the entire corpus; follow this exact high-yield path:

| Time | Topic | Files to Read / Inspect | Key Takeaway |
|---|---|---|---|
| **Hour 1** (60 min) | **Domain & Problem Anatomy (`.pbm`)** | 1. [`doc/SENIOR-DEV-BRIEF.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/SENIOR-DEV-BRIEF.md)<br>2. [`doc/ai-analysis-20261103/04-problem-format-and-grading.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/ai-analysis-20261103/04-problem-format-and-grading.md)<br>3. Inspect reference problem: [`spec/models/01-senar-o-parell.pbm`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/professor%20gave%202026-10-25/problem-editor/spec/models/01-senar-o-parell.pbm)<br>4. Skim lines 1–50 of [`spec/constitucio.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/professor%20gave%202026-10-25/problem-editor/spec/constitucio.md) | Understand the file contract of a problem (`handler.yml`, `problem.<lang>.tex`, `solution.cc`, `*.inp`, generated `*.cor`) and the C++17 pedagogical guidelines. |
| **Hour 2** (60 min) | **The Problem Editor Vision & Agent Skills** | 1. [`problem-editor/README.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/professor%20gave%202026-10-25/problem-editor/README.md)<br>2. [`doc/ai-analysis-20261103/05-ai-generation-and-problem-editor-vision.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/ai-analysis-20261103/05-ai-generation-and-problem-editor-vision.md)<br>3. [`skills/problemes-jutge/SKILL.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/professor%20gave%202026-10-25/problem-editor/skills/problemes-jutge/SKILL.md)<br>4. Skim [`generated-exam-sample/`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/professor%20gave%202026-10-25/problem-editor/generated-exam-sample/) | Understand Pau's 4-phase roadmap (Learn format → AI skills in CLI → Next.js SaaS scaffold → Release) and see how exam problems were generated with Claude Code. |
| **Hour 3** (60 min) | **Existing `jtk` Codebase & Architectural Debt** | 1. [`doc/ai-analysis-20261103/03-jtk-architecture.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/ai-analysis-20261103/03-jtk-architecture.md)<br>2. [`doc/ai-analysis-20261103/06-jtk-rewrite-observations.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/ai-analysis-20261103/06-jtk-rewrite-observations.md)<br>3. Inspect [`toolkit/maker.ts`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/jutge_repos/jutge-toolkit/toolkit/maker.ts) and [`toolkit/problem.ts`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/jutge_repos/jutge-toolkit/toolkit/problem.ts) | Identify the architectural flaws: zero unit tests, mixing TUI prompts directly inside compilation logic, open-loop LLM dumping, and lack of execution sandboxing. |
| **Hour 4** (60 min) | **Proposals Review & Meeting Preparation** | Review the 3 proposals below, pick the track you want to approve, and review the discussion points for Jordi and Pau. | Walk into the Nov 12 meeting with high authority, clear architectural boundaries, and a concrete roadmap. |

---

## 4. Concrete Proposals for the November 12th Meeting

To prove high seniority and tangible progress in your upcoming meeting, here are three concrete options:

### Proposal A: The Technical Architecture RFC & 4-Month Engineering Roadmap (Strategic Lead)
*   **What it is:** A comprehensive, formal 3-page engineering proposal titled *"jtk v5: Decoupled Core Architecture, Machine-Readable Agent Contract, and 4-Month Rebuild Roadmap"*.
*   **What it contains:**
    1. **Decoupling Proposal:** Splitting `jtk` into `@jutge/core` (pure headless business logic, returns typed result objects, zero console/inquirer dependencies) and `@jutge/cli` (thin TUI wrapper).
    2. **Scriptable Agent Contract:** Standardizing a `--json` output flag and deterministic exit codes across all commands (`lint`, `make`, `verify`) so AI agents and the future web app can reliably execute and self-correct.
    3. **Testing Harness Design:** A robust test runner with real `.pbm` test fixtures using Vitest/Bun (resolving the total absence of automated tests in `jtk`).
    4. **16-Week Milestone Schedule:**
       * *Month 1:* `@jutge/core` extraction & automated test harness.
       * *Month 2:* Closed-loop verification pipeline & scriptable CLI/MCP tool.
       * *Month 3:* Problem-Editor backend integration & AI skill alignment.
       * *Month 4:* Production migration, documentation, and web visualizer integration.
*   **Why it works:** Professors want to see that you can take ownership of a messy codebase, establish clean software boundaries, and lead the rebuild with a credible plan.

### Proposal B: Working Proof-of-Concept — Closed-Loop Problem Verifier (Tangible Engineering)
*   **What it is:** A clean TypeScript module written in `work/` that implements the single most critical capability Pau highlighted in `problem-editor/README.md`: **a deterministic validation runner that outputs machine-readable JSON**.
*   **What it does:**
    *   Takes a `.pbm` problem folder (or newly generated draft).
    *   Executes validation steps in a closed feedback loop: compiles the golden solution, runs the testcase generator, executes candidate inputs against limits, and emits structured JSON error diagnostics (`{ valid: boolean, errors: [...], benchmarks: {...} }`).
    *   Demonstrates how an AI agent or web SaaS can receive structured compiler/runtime error feedback and self-correct automatically.
*   **Why it works:** Gives you working code to demo live on screen during the meeting, proving immediate hands-on technical execution.

### Proposal C: Upstream `problem-editor` PR & Spec Audit (Direct Upstream Contribution)
*   **What it is:** A targeted pull request / commit series directly for Pau's `problem-editor` repo.
*   **What it does:**
    *   Fixes contradictory spec rules in `problema-jutge.md` (e.g. 5x vs 3x slow solution requirement).
    *   Supplies missing template files referenced in the spec (`spec/templates/*`).
    *   Adds an automated validation script that runs across all 7 model problems to ensure they pass `jtk lint`.
*   **Why it works:** Demonstrates that you've already audited their specific repository, caught defects in their documentation, and contributed immediate fixes.

---

## 5. Next Step: Implementation Upon Your Approval

When you review this document and select your preferred track:
- **Option 1 (Recommended Hybrid):** Architecture RFC & 4-Month Roadmap + Closed-Loop Verifier POC in `work/`.
- **Option 2:** Architecture RFC & 4-Month Roadmap only (strategic proposal).
- **Option 3:** Upstream PR / Commits to `problem-editor`.

Let me know which option you approve, and I will implement the complete deliverable in the next step so it is ready for your November 12th meeting.

