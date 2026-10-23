# 05 - Jutge Toolkit Codebase Mastery (5-Minute Review)

**Target Audience:** Simin Shoeibi  
**Reading Time:** 5 minutes  
**Goal:** Prove to your professor that you deeply understand the `jutge-toolkit` (`jtk`) codebase from the inside out.  
**Language Level:** Standard English (B2).

---

## 1. Tech Stack & Architectural Patterns

When talking to your professor, highlight these architectural facts:

- **Runtime:** Built for **Bun** (fast JavaScript/TypeScript engine).
- **CLI Engine:** Uses `@commander-js/extra-typings` for end-to-end TypeScript type safety across CLI flags and arguments.
- **Data Validation:** Uses **Zod** schemas (`z.object({...})`) to validate problem metadata, specification files (`IOSpecification`), and API responses.
- **Terminal UI:** Uses `@inquirer/prompts` for interactive wizards (arrow keys, search checkboxes, masked passwords).
- **API Client:** Talks to Jutge API v2 (`api.jutge.org/api`) with Bearer token authentication stored in `~/.config/jutge/credentials.json`.

---

## 2. Directory Layout: Where Everything Lives

```text
jutge-toolkit/
├── toolkit/             # CLI command definitions (entry points for jtk commands)
│   ├── generate.ts      # 'jtk generate' (AI generation commands)
│   ├── make.ts          # 'jtk make' (compiling & building outputs)
│   ├── upload.ts        # 'jtk upload' (packaging & publishing to server)
│   ├── lint.ts          # 'jtk lint' (syntax & structure checker)
│   ├── verify.ts        # 'jtk verify' (checking alternative solutions against golden)
│   ├── stage.ts         # 'jtk stage' (batch testing solutions)
│   └── dummies.ts       # 'jtk for-dummies' / 'interactive' (interactive menu)
│
├── lib/                 # Core business logic & execution engine
│   ├── maker.ts         # Compilation logic, runner for test cases, XeLaTeX/Pandoc builders
│   ├── create-io.ts     # Generation workflow for standard I/O problems
│   ├── create-funcs.ts  # Generation workflow for function-only problems
│   ├── aiclient.ts      # JutgeAI chat client & SSE streaming wrapper
│   ├── login.ts         # Multi-method authentication (Token -> File -> Env -> Prompt)
│   └── compilers.ts     # Definitions for GCC, Clang, Python, Haskell, Rust, Java
│
└── assets/              # Static assets & prompts
    ├── prompts/         # System prompts and templates for JutgeAI (io, funcs, ask)
    ├── latex/           # Root templates for PDF and HTML rendering
    └── problems/        # Pre-built template problems for 'jtk clone'
```

---

## 3. How the Core Commands Work Internally

### `jtk generate problem` (`lib/create-io.ts`)
1. **Reads Spec:** Reads options interactively or from a YAML file (`IOSpecification`).
2. **JutgeAI Streaming:** Connects to the backend via Server-Sent Events (SSE).
3. **Sequential Pipeline:**
   - Statement $\to$ Sample Tests $\to$ Hidden Private Tests $\to$ Solutions (C++, Python) $\to$ Translations (Catalan, Spanish) $\to$ Python test generators.
4. **Calculates Impact:** Calculates tokens used, estimated price in Euros (€), electrical consumption (kWh), and water footprint in `README.md`.

### `jtk make` (`lib/maker.ts`)
1. Compiles the golden solution (`solution.cc`) using macOS Clang (`clang++`).
2. Discovers all `sample-*.inp` and `test-*.inp` files.
3. Runs the compiled executable on each input and redirects stdout into matching `*.cor` files.
4. Optionally builds PDF/HTML statements using `pandoc` and `xelatex`.

### `jtk upload` (`toolkit/upload.ts`)
1. Verifies that the problem has valid solutions and outputs.
2. Zips the directory into a package in memory.
3. Sends an HTTP POST to `api.jutge.org/api` (Instructor endpoints).
4. The server assigns an official Problem ID (e.g. `P84920_en`) and writes it to `problem.yml`.

---

## 4. Insider Findings (Code Details That Prove You Studied It)

Mentioning these specific nuances will immediately impress Prof. Jordi Petit:

1. **Context Window Management in `create-io.ts`:**  
   You noticed that `IOProblemGenerator` calls `this.bot.forgetLastInteraction()` repeatedly.  
   *Why?* To discard intermediate sample tests and translations from the LLM prompt memory, preventing the context window from overflowing during generation.

2. **Two Distinct Problem Kinds:**  
   - **`io`:** Standard console input/output (reads `stdin`, prints `stdout`).
   - **`funcs`:** Function-only tasks (the student writes a function; Jutge runs a hidden driver program to call and test it).

3. **Compiler Selection Quirk in `lib/maker.ts`:**  
   In `maker.ts`, `selectCompiler()` selects the compiler based on the extension of `goldenSolution` (`.cc`) rather than the target solution's extension. Passing `jtk make exe` when an alternative `solution.py` exists causes it to invoke `g++` on Python code. Use `jtk make cor` to build test outputs and `jtk verify solution.py` to test alternatives.

4. **Strict `\Sample` Linter Rule:**  
   In `toolkit/lint.ts`, `jtk lint` checks that if `sample-*.inp` files exist, `problem.<lang>.tex` **must** include the `\Sample` macro, otherwise it flags a warning.

---

## 5. Your 30-Second Speaking Script for the Meeting

> *"Professor, I spent time studying the internal codebase of `jutge-toolkit`.  
> I analyzed how `create-io.ts` orchestrates the JutgeAI generation pipeline and manages prompt memory with `forgetLastInteraction()`, how `lib/maker.ts` handles the compilation lifecycle and test output generation, and how `upload.ts` connects to API v2.  
>  
> One specific improvement I would like to propose for my internship is adding a **closed-loop verification step** to `jtk generate problem`: having the generator locally compile `solution.cc` and test it with `maker.ts` before writing to disk, so any AI syntax error is self-corrected automatically."*
