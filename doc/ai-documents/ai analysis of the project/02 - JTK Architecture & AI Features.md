# 02 - JTK Architecture & AI Features

**Focus:** Inside `jutge-toolkit` (`jtk`) and its AI problem generator  
**Language Level:** Standard English (B2)

---

## 1. What is `jutge-toolkit` (`jtk`)?

The **Jutge Toolkit (`jtk`)** is the primary command-line tool for professors and problem authors. 

- **Tech Stack:** Written in **TypeScript** and runs fast on the **Bun** runtime.
- **Purpose:** It helps authors create, build, verify, and upload programming exercises to Jutge.org.
- **CLI Commands:** Accessible in the terminal via the alias `jtk` (or `jutge-toolkit`).

---

## 2. Anatomy of a Problem Folder (`.pbm`)

Every problem in Jutge is stored inside a directory ending with `.pbm` (Problem Package).

```text
my-problem.pbm/
├── problem.en.tex       # Problem statement in LaTeX (English)
├── problem.en.yml       # Metadata (Title, author name, email)
├── problem.ca.tex       # Translated statement in Catalan
├── problem.es.tex       # Translated statement in Spanish
├── handler.yml          # Problem type (default is 'std' for Standard I/O)
├── solution.cc          # Golden reference solution (C++)
├── solution.py          # Alternative solution (Python)
├── sample-1.inp         # Public sample input (shown in the statement)
├── test-1.inp           # Hidden private input (grades edge cases)
├── generate-random.py   # Script to generate randomized test inputs
└── README.md            # Generation report (AI cost, energy, and tokens)
```

---

## 3. How `jtk generate problem` Works

`jtk` has an AI command to automatically draft a new problem:

```bash
jtk generate problem -k io -d my-problem.pbm
```

### Two Kinds of Problems (`-k, --kind`):
1. **`io` (Standard I/O):** The student writes a program that reads from `stdin` and writes to `stdout` (e.g. C++, Python, Java).
2. **`funcs` (Functions):** The student only writes specific functions (e.g. `is_prime()`). A hidden driver program calls their function.

### The 6 Steps the AI Follows:
1. **Reads Specification:** Asks for title, description, and languages (interactively or from a YAML file).
2. **Generates Statement:** Creates `problem.en.tex` using Jutge LaTeX templates.
3. **Generates Inputs:** Creates `sample-1.inp`, `sample-2.inp`, `test-1.inp`, `test-2.inp`.
4. **Generates Solutions & Translations:** Creates `solution.cc`, translates LaTeX statements to Catalan and Spanish.
5. **Generates Python Scripts:** Creates `generate-random.py` and `generate-hard.py`.
6. **Writes Audit Log:** Calculates tokens used, price in Euros (€), water, and electricity in `README.md`.

---

## 4. Daily Commands Cheat Sheet

| Command | What It Does |
|---|---|
| `jtk doctor` | Checks if required compilers (GCC, Python, Pandoc, XeLaTeX) are installed. |
| `jtk clone demo -d my-problem.pbm` | Clones a working example template to start editing. |
| `jtk generate problem` | Uses JutgeAI to draft an entire problem package from scratch. |
| `jtk make` | **The Main Build Command:** Compiles `solution.cc`, runs it on all `.inp` files to create `.cor`, and builds PDFs. |
| `jtk verify solution.py` | Tests an alternative solution against all `.cor` files to ensure it produces identical output. |
| `jtk lint` | Checks the folder for syntax errors, missing files, or YAML issues. |
| `jtk clean` | Deletes temporary binary files before uploading. |
| `jtk upload` | Publishes the problem package to Jutge.org via API v2. |
| `jtk submit -l cc solution.cc` | Tests a solution by sending it to the live judge for evaluation. |

---

## 5. The Current Limitation & Your Scholarship Proposal

### The Big Limitation (Open-Loop Generation)
Right now, `jtk generate problem` generates the files and immediately writes them to disk.  
**It never compiles or runs the code during generation!**  
If the AI makes a typo in `solution.cc` or creates an invalid input, the professor only discovers it later when running `jtk make`.

### Your Proposed Solution: Closed-Loop Self-Correction
Implement an automatic test loop during generation:
```
AI generates Solution + Inputs
          │
          ▼
jtk automatically compiles & runs code locally
          │
     ┌────┴────┐
  Success    Error
     │         │
     ▼         ▼
Save files   Feed error trace back to AI to fix itself (retry up to 3 times)
```
*Why professors will love this:* It guarantees that every AI-generated problem compiles and runs with 100% clean test results before the professor touches it.
