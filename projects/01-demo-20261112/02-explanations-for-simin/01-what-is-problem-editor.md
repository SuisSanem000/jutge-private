# Explanation: What Is the `problem-editor` Repository?

> **Location:** `work/01-meeting-presentation-and-demo-20261112/02-explanations-for-simin/01-what-is-problem-editor.md`  
> **Parent Navigation:** [Explanations Overview](./README.md) • [What Did I Do?](./02-what-did-i-do.md) • [Task 01 Root](../README.md)

---

## 1. The Real-World Problem It Solves

Creating high-quality programming problems for university computer science courses (such as EDA, PRO2, and AP2 at UPC) and competitive programming platforms is extremely time-consuming and difficult for professors:

- **Formal LaTeX statements:** Professors must author mathematically rigorous statements, explain preconditions, and format sample tables using specialized LaTeX macros.
- **Pedagogically sound code:** The solution cannot just work; it must adhere to strict pedagogical standards (clean code, early termination on searches, no forbidden advanced C++ features).
- **Comprehensive test generation:** Edge cases (empty sequences, single elements, negative numbers, extreme values) and efficiency stress cases ($N = 100,000$) must be generated.
- **Complex YAML configurations:** Problem metadata, compiler modes, time factors, and partial scoring tables must be meticulously configured.
- **Slow solutions for limit checks:** Professors must write naive alternative solutions to ensure students cannot pass with suboptimal algorithms.

Because this manual workflow requires deep expertise across multiple tools, very few professors create new problems, leading to stagnant problem sets and reused exam questions.

---

## 2. Pau Fernandez's Vision: The Problem Editor SaaS

Pau Fernandez and Prof. Jordi Petit envisioned building an AI-assisted **SaaS Web Application** (*"Google Docs for Programming Problems"*):

```text
[Teacher in Browser] 
       │
       ▼
┌────────────────────────────────────────────────────────┐
│  Next.js SaaS Web Interface                            │
│  - Visual Problem Inspector (Statement, Code, Tests)   │
│  - Bottom Prompt Box for AI Agent                      │
└────────────────────────────────────────────────────────┘
       │                              ▲
       │ Prompts / Edits              │ Structured Feedback
       ▼                              │
┌────────────────────────────────────────────────────────┐
│  AI Coding Agent (Preloaded with Jutge Skills & Specs) │
└────────────────────────────────────────────────────────┘
       │                              ▲
       │ Executes Commands            │ Machine-Readable JSON
       ▼                              │
┌────────────────────────────────────────────────────────┐
│  Deterministic Engine (jtk / CLI / MCP Server)         │
│  - Compiles C++, runs tests, verifies limits           │
└────────────────────────────────────────────────────────┘
```

### Core Principles of Pau's Vision
1. **Teacher Dashboard:** A teacher signs in and sees their library of problems.
2. **Graphical Problem Inspector:** Teachers can visually inspect the problem statement, golden solution, sample inputs/outputs, and test generators without touching raw terminal files.
3. **AI Agent Chat Box:** Teachers instruct an AI agent (e.g. *"Create a binary tree traversal problem testing post-order evaluation with $N \le 10^5$"*). The agent scaffolds or modifies the problem files on behalf of the teacher.
4. **Deterministic Feedback Loop:** The AI agent does not guess blindly. It invokes a deterministic CLI/MCP tool that compiles the code and executes the test generator. If a compilation or time limit fails, the tool returns explicit error diagnostics so the AI can self-correct.
5. **Code Over Probability:** If an operation can be solved deterministically with code (linting, compiling, formatting, running tests), code is used rather than asking an LLM to guess.

---

## 3. The 4 Proposed Phases

In `problem-editor/README.md`, Pau outlined the project roadmap:

| Phase | Milestone | Focus | Status |
|---|---|---|---|
| **Phase 1** | **Learn Problem Format** | Master the `.pbm` directory anatomy, compiler modes (`G++17`, `PRO2`), and the C++17 pedagogical constitution. | **COMPLETED** (Studied & specs translated) |
| **Phase 2** | **Generate via AI Skills** | Use an AI agent (Claude Code in VS Code) preloaded with skills to create, compile, and verify problems from idea drafts. | **COMPLETED** (`dominant-peaks.pbm` generated) |
| **Phase 3** | **Scaffold Next.js Site** | Build the web application replicating the terminal workflow with a graphical user interface. | **UPCOMING** (Target of your 4-month internship) |
| **Phase 4** | **Iterate and Harden** | Expand commands, validate across hundreds of problems, and release to university faculty. | **FUTURE** |

---

## 4. Anatomy of the Upstream `problem-editor` Folder

When you look inside `problem-editor`, here is what each folder does:

| Folder / File | What It Contains |
|---|---|
| `README.md` | Pau's project vision, SaaS design, and 4 roadmap phases. |
| `spec/constitucio.md` | **The Pedagogical Constitution:** The non-negotiable rules for code elegance, efficiency, and the educational C++17 subset (forbids `std::unordered_map`, lambdas, `enum class`, and `std::variant`). |
| `spec/problema-jutge.md` | **Technical Specification:** Complete `.pbm` folder anatomy, `handler.yml` keys, compiler options (`G++17` vs `PRO2`), `.cor` invariants, and AI review checklists. |
| `spec/models/` | **7 Reference Models:** Real working problems demonstrating different categories (Percentiles, Bicolor numbers, Selection sort, Binary tree, Expressions, Linked lists, Winners). |
| `skills/` | **Claude Agent Skills:** Instructions for AI agents (`skills/problemes-jutge/SKILL.md` for problem creation, and `skills/revisa-problemes-jutge/SKILL.md` for problem audit). |
| `generated-exam-sample/` | **Real Exam Proof-of-Concept:** Three real exam problems generated by Claude Code from an `IDEA.md` draft, compiled with `jtk`, and rendered into exam and solution PDFs using Typst. |
| `private-problems/` | ~162 real private problems from past university courses (EDA, AP1, AP2) added by Prof. Jordi Petit for regression testing. |

