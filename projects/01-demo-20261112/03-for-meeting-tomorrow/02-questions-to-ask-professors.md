# Key Questions to Ask Supervisors (Jordi Petit & Pau Fernandez)

> **Location:** `work/01-meeting-presentation-and-demo-20261112/03-for-meeting-tomorrow/02-questions-to-ask-professors.md`  
> **Parent Navigation:** [Meeting Materials Overview](./README.md) • [Engineering Proposal](./PROPOSAL-PRESENTATION-20261112.md) • [Speaking Script](./01-meeting-speaking-script.md) • [Task 01 Root](../README.md)

## Table of Contents

- [1. Problem Editor Storage & Organization Questions (For Pau Fernandez)](#1-problem-editor-storage--organization-questions-for-pau-fernandez)
  - [Question 1: Where should generated problems live in `problem-editor`?](#question-1-where-should-generated-problems-live-in-problem-editor)
  - [Question 2: Typst PDF Statement Compilation](#question-2-typst-pdf-statement-compilation)
- [2. Architecture & Engine Rebuild Questions (For Jordi Petit & Pau Fernandez)](#2-architecture--engine-rebuild-questions-for-jordi-petit--pau-fernandez)
  - [Question 3: Git Repository & PR Review Workflow](#question-3-git-repository--pr-review-workflow)
  - [Question 4: Agent Interface Priority (CLI `--json` vs MCP Server)](#question-4-agent-interface-priority-cli---json-vs-mcp-server)
  - [Question 5: Language Scope for Month 1 Test Fixtures](#question-5-language-scope-for-month-1-test-fixtures)
  - [Question 6: Jutge AI Token / LLM Endpoint](#question-6-jutge-ai-token--llm-endpoint)
  - [Question 7: Code Comments & Statement Languages (English vs Catalan)](#question-7-code-comments--statement-languages-english-vs-catalan)

---

## 1. Problem Editor Storage & Organization Questions (For Pau Fernandez)

### Question 1: Where should generated problems live in `problem-editor`?
- **How to ask:**  
  *"For today's demonstration, I generated `dominant-peaks.pbm/` directly at the root of `problem-editor`. Going forward, would you prefer us to keep new problems at the root, or organize them into a dedicated folder like `generated-problems/` or alongside `generated-exam-sample/`?"*
- **Why this helps:** Shows respect for repository structure and establishes clean git organization.

### Question 2: Typst PDF Statement Compilation
- **How to ask:**  
  *"In `generated-exam-sample/`, you compiled exams and solutions using Typst rather than Pandoc LaTeX. For the web editor in Phase 3, should we transition from `.tex` to Typst for statements, or continue supporting both?"*
- **Why this helps:** Proves you examined the `generated-exam-sample/` folder deeply and spotted the modern Typst integration.

---

## 2. Architecture & Engine Rebuild Questions (For Jordi Petit & Pau Fernandez)

### Question 3: Git Repository & PR Review Workflow
- **How to ask:**  
  *"For the rebuild of `jtk` into `@jutge/core`, what repository structure do you prefer? Should we start fresh in a new repository (e.g. `jutge-toolkit-v5`) or work on a feature branch on the existing `jutge-toolkit` repo? And who will be the primary reviewer for my pull requests?"*
- **Why this helps:** Establishes clear development logistics and review expectations from day one.

### Question 4: Agent Interface Priority (CLI `--json` vs MCP Server)
- **How to ask:**  
  *"For enabling the AI agent in Phase 3, which interface should we prioritize first: a standardized CLI flag (`jtk make --json`) with structured exit codes, or an official Model Context Protocol (MCP) server package?"*
- **Why this helps:** Guides your implementation priority for Month 2.

### Question 5: Language Scope for Month 1 Test Fixtures
- **How to ask:**  
  *"For our Month 1 test harness (Vitest against real `.pbm` fixtures), should we focus strictly on C++ (`G++17` whole program and `PRO2` function harnesses) first, or should we include Python problems from the very start?"*
- **Why this helps:** Keeps your initial scope tightly focused on the highest-priority academic courses at UPC.

### Question 6: Jutge AI Token / LLM Endpoint
- **How to ask:**  
  *"In the kickoff notes, a JutgeAI token endpoint was mentioned. For powering the AI assistant inside the Next.js SaaS editor, will students/teachers use a centralized UPC API proxy, or will they supply their own provider API keys (Anthropic / OpenAI / Google)?"*
- **Why this helps:** Clarifies the authentication and API key architecture for Phase 3.

### Question 7: Code Comments & Statement Languages (English vs Catalan)
- **How to ask:**  
  *"In `dominant-peaks.pbm`, we generated the problem statement and code comments in English. In the long term, should the AI agent support multilingual statement generation (Catalan, Spanish, English) simultaneously, and what is your preferred language for golden solution comments?"*
- **Why this helps:** Addresses Pau's original note in `problem-editor/README.md` and aligns on localization requirements.

