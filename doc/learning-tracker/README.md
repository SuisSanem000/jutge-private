# Project Learning Tracker & Skill Acquisition Board

> **Purpose:** A living task-tracking board to systematically record, prioritize, and master new technologies, tools, and paradigms required for the Jutge.org scholarship project.

---

## 1. Skill Acquisition Dashboard

| ID | Skill / Technology | Category | Priority | Status | Direct Jutge Application |
|:---:|---|---|:---:|:---:|---|
| **SK-01** | **Typst** | Modern Document Typesetting | `P0 - High` | 🟡 In Progress | Used by Pau Fernandez for exam PDFs (`PRO2_Parcial_2026P_Solucio.typ`); lightweight replacement for heavy LaTeX/Pandoc toolchains in `jtk make pdf`. |
| *SK-02* | *Model Context Protocol (MCP)* | AI Agent Tooling | `P1 - Medium` | ⚪ Planned | Exposing `@jutge/core` commands (`make`, `lint`, `verify`) directly to Claude Code and IDE agents. |
| *SK-03* | *Server-Sent Events / WebStreams* | Network Architecture | `P1 - Medium` | ⚪ Planned | Deepening understanding of `api.jutge.org/api/webstreams` real-time compilation logging. |

---

## 2. Active Learning Task: SK-01 — Typst

### Overview: What Is Typst?
[Typst](https://typst.app) is a modern, blazing-fast, Rust-based markup and typesetting system designed as a clean, programmable successor to LaTeX. Unlike LaTeX—which requires multi-gigabyte TeX Live distributions and slow macro expansion—Typst compiles documents to PDF and SVG in tens of milliseconds, provides clean mathematical typesetting, and includes a built-in programming language (`#let`, `#for`, `#import`).

---

### Why Typst Is Critical for the Jutge Project
1. **Direct Adoption by Supervisors:**  
   In `resources/professor gave 2026-10-25/problem-editor/generated-exam-sample/`, Pau Fernandez created [`PRO2_Parcial_2026P_Solucio.typ`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/professor%20gave%202026-10-25/problem-editor/generated-exam-sample/PRO2_Parcial_2026P_Solucio.typ), which imports `@preview/codly` and dynamically reads source solutions (`#let p1 = read("P1-tresors-inaccessibles.Y52290.pbm/solution.cc")`) to compile exam solution manuals automatically.
2. **Solving the Legacy `jtk` Toolchain Bottleneck:**  
   During local problem verification with `jtk make`, macOS repeatedly warns: `pandoc with lua support not found`. Compiling LaTeX statements currently requires Pandoc with custom Lua filters and `pdflatex`. Replacing or supplementing this pipeline with Typst allows `@jutge/core` to generate instant PDF statements with zero heavy system dependencies.
3. **Automated Exam & Problem Book Compilation:**  
   Typst's programmatic scripting allows instructors to pull 10 `.pbm` folders and produce an entire multi-page exam paper or solution booklet in under a second.

---

### Actionable Learning Checklist

- [ ] **Task 1: Toolchain Installation & Verification**
  - Install Typst CLI on macOS via Homebrew:
    ```bash
    brew install typst
    typst --version
    ```
  - Verify editor tooling: Install the official **Tinymist Typst** extension in VS Code for live preview and syntax highlighting.

- [ ] **Task 2: Core Syntax & Mathematical Markup**
  - Learn basic formatting: Headings (`= Title`), bold (`*text*`), italic (`_text_`), lists (`- item`), links.
  - Master math syntax: Inline `$a + b = c$` and display equations `$ sum_(i=1)^n i = (n(n+1))/2 $`.
  - Contrast with LaTeX: Notice clean delimiters and lack of verbose `\begin{equation}` environments.

- [ ] **Task 3: Dissect Supervisor's Exam Solution Template**
  - Read and analyze [`PRO2_Parcial_2026P_Solucio.typ`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/resources/professor%20gave%202026-10-25/problem-editor/generated-exam-sample/PRO2_Parcial_2026P_Solucio.typ).
  - Understand package imports:
    ```typst
    #import "@preview/codly:1.3.0"
    #import "@preview/codly-languages:0.1.10"
    ```
  - Understand dynamic file reading and raw code formatting:
    ```typst
    #let sol = read("dominant-peaks.pbm/solution.cc")
    #raw(sol, lang: "cpp")
    ```

- [ ] **Task 4: Build a Prototype Problem Statement (`problem.en.typ`)**
  - Convert `dominant-peaks.pbm/problem.en.tex` into a standalone `problem.en.typ` file.
  - Implement a clean two-column sample table layout using Typst grid layouts (`#grid(columns: (1fr, 1fr), ...)`).
  - Compile to PDF and measure execution time:
    ```bash
    typst compile problem.en.typ problem.en.pdf
    ```

- [ ] **Task 5: Architectural Proposal for `@jutge/core` Integration**
  - Document a proposal for supporting `problem.<lang>.typ` as an alternate statement format alongside `problem.<lang>.tex`.
  - Compare build speed, binary footprint, and PDF output fidelity between Typst and LaTeX/Pandoc.

---

### Curated Learning Resources

| Resource | Description | Link |
|---|---|---|
| **Typst Official Tutorial** | 20-minute interactive guide to document writing | [typst.app/docs/tutorial](https://typst.app/docs/tutorial/) |
| **Typst for LaTeX Users** | Side-by-side syntax comparison with LaTeX | [typst.app/docs/guides/guide-for-latex-users](https://typst.app/docs/guides/guide-for-latex-users/) |
| **Codly Package** | Beautiful code block highlighting used in Jutge exams | [typst.app/universe/package/codly](https://typst.app/universe/package/codly/) |
| **Tinymist VS Code Extension** | Live preview and language server for Typst | [Marketplace](https://marketplace.visualstudio.com/items?itemName=myriad-dreamin.tinymist) |

---

## 3. Template for Adding Future Learning Topics

When tracking a new technology or skill, append a new section below using this standard schema:

```markdown
### SK-XX: [Technology Name]
- **Category:** [e.g. Runtime / Protocol / Language]
- **Priority:** [P0 - High / P1 - Medium / P2 - Low]
- **Why It Matters for Jutge:** [1-2 sentences on direct project impact]
- **Actionable Tasks:**
  - [ ] Task 1: [Install / setup]
  - [ ] Task 2: [Syntax / fundamentals]
  - [ ] Task 3: [Integration prototype]
- **Key Resources:** [Links to documentation]
```

