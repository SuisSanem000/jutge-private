# Meeting Prep, 5-Hour Study Plan & Architecture Roadmap (2026-11-12)

> **Meeting Date:** Tomorrow, November 12, 2026  
> **Audience:** Supervisors Prof. Jordi Petit (Jutge lead) and Pau Fernandez (Problem-editor maintainer)  
> **Simin's Prep Time:** 5 hours today

---

## 1. Executive Summary: What We Have Done So Far

1. **Audited the Full Technical Ecosystem:**
   * Examined `jutge-toolkit` (`jtk`), server judge (`jutge-driver-std`), and Pau's `problem-editor`.
   * Uncovered key technical debt: zero automated unit tests in `jtk`, coupling of console UI with compilation logic, open-loop AI problem generation (no local compile or test verification), and lack of sandboxing/timeouts during builds.
2. **Cleaned Workspace Boundaries (Zero Duplication):**
   * `resources/`: Pristine upstream clones (**managed solely by Simin**; AI never touches).
   * `doc/`: All documentation, AI analysis, understanding guides, and meeting plans.
   * `work/`: Where Simin's actual code, tasks, and presentations to professors live.
3. **Structured Knowledge Base:**
   * Decoupled AI settings (`doc/ai-analysis/`) from system understanding (`doc/understanding/`) and meeting prep (`doc/meetings-and-next-steps/`).

---

## 2. 5-Hour Study Plan (For Today)

Spend your 5 hours today following this exact reading path:

```
[Hour 1] Domain & Format  -->  [Hour 2] Pau's Vision & Skills  -->  [Hour 3] jtk Tech Debt  -->  [Hours 4-5] Pitch & Roadmap
```

| Block | Topic | Primary Files to Read | What to Take Away |
|---|---|---|---|
| **Hour 1** | **Domain & Problem Anatomy (`.pbm`)** | 1. [Senior Developer Brief](../understanding/01-senior-dev-brief.md)<br>2. [Problem Format & Grading Spec](../understanding/04-problem-format-and-grading.md)<br>3. Inspect reference problems: [Models Guide](../problem-editor-en-translate-20261111/spec/models-guide.md) | A problem is a strict `.pbm` folder: `handler.yml` (rules), `problem.<lang>.tex` (statement), `solution.cc` (golden code), `*.inp` (tests), and generated `*.cor` (correct output). |
| **Hour 2** | **The Problem-Editor Vision & Agent Skills** | 1. [Problem Editor Overview](../problem-editor-en-translate-20261111/README.md)<br>2. [AI Problem Generation Analysis](../understanding/05-ai-problem-generation-analysis.md)<br>3. [Problem Creation Skill](../problem-editor-en-translate-20261111/skills/jutge-problems/SKILL.md) | Pau's vision: Next.js SaaS + AI agent + CLI tool reporting deterministic success/failure so the AI can self-correct when test generation or compilation fails. |
| **Hour 3** | **Existing `jtk` Codebase & Architectural Debt** | 1. [jtk Architecture Guide](../understanding/03-jtk-architecture.md)<br>2. [jtk Rewrite Observations](../understanding/06-jtk-rewrite-observations.md) | Why `jtk` must be rebuilt: no unit tests, interactive UI mixed inside core compilation routines, no sandboxing, and no machine-readable output. |
| **Hours 4–5** | **Meeting Strategy & Pitch Alignment** | Review Sections 3 and 4 below and check [Meeting Presentation Document](../../work/03-meeting-presentation-20261112/PROPOSAL-PRESENTATION-20261112.md). | Finalize your speaking points and the 4-month milestone proposal for Jordi and Pau. |

---

## 3. What to Say in Tomorrow's Meeting (The Pitch)

### Part 1: The Credibility Opener & Phase 1/2 Live Demo
> *"Over the past week, I conducted an in-depth review of your roadmap in `problem-editor`:*
> 1. *For Phase 1, I mastered the `.pbm` file specifications, LaTeX statement structure, the C++17 Pedagogical Constitution, and the 7 reference models.*
> 2. *For Phase 2, I tested generating problems using Claude Code running directly inside your `problem-editor` repository loaded with your skills.*
> 3. *I generated `dominant-peaks.pbm`, compiled it with `jtk make`, and verified that the slow solution triggers time-limit exceeded (EE).*
> 4. *Let me show you the problem folder right inside `problem-editor` and run `jtk make` live right now.*
>
> *My key takeaway: The generative pipeline works, but current `jtk` was written as an interactive human CLI. It cannot give an AI agent structured JSON diagnostics to self-correct when code or tests fail."*

### Part 2: What You Propose to Implement (The 4-Month Architecture Plan)
Propose this clear, 4-phase delivery plan:

*   **Phase 1 (Month 1 — Foundational Engine & Testing):**
    *   Extract `@jutge/core`: A pure, headless TypeScript library (pure functions, zero console/inquirer imports, returns typed result objects).
    *   Build an automated test suite (Vitest/Bun) using real `.pbm` test fixtures.
    *   Add execution timeouts & sandboxing so runaway solutions never freeze builds.
*   **Phase 2 (Month 2 — The Scriptable Agent & Closed-Loop Pipeline):**
    *   Build the machine-readable CLI/MCP contract (`--json` output, strict exit codes) so AI agents can drive it reliably.
    *   Implement **closed-loop verification**: compile solution, run generator, verify tests, and return structured errors if anything fails.
*   **Phase 3 (Month 3 — Problem Editor Integration):**
    *   Integrate the core engine with Pau's Next.js web SaaS backend and AI skills.
*   **Phase 4 (Month 4 — Production Hardening & Release):**
    *   Documentation, migration path from legacy `jtk`, release package.

### Part 3: Three Decisions to Get from Jordi and Pau
1. **Repository & PRs:** *"Should we rebuild `jtk` in a new repository/branch (e.g. `jutge-toolkit-v5`), and who will be the primary reviewer for PRs?"*
2. **Agent Interface:** *"Do you prefer the AI agent to drive `jtk` via CLI flags (`--json`), or would you like an official MCP server package?"*
3. **Initial Scope:** *"For the first working milestone, should we focus exclusively on C++ (`G++17` and `PRO2`), or include Python as well?"*

