# 04 - Meeting Cheat Sheet & Talking Points

**Use For:** Quick 5-minute review before your meeting with your professor  
**Language Level:** Standard English (B2)

---

## 1. 30-Second Elevator Pitch (What to Say First)

> *"Hello Professor!  
> I reviewed our last session and replicated the entire problem authoring flow on my own using `jtk`. I created the prime numbers problem with the story statement, built the test cases with `jtk make`, and uploaded it to Jutge.org where it is live and verified with Accepted verdicts.  
>  
> I also studied the `jutge-toolkit` codebase. I am ready to focus on `jtk` for my internship and have some concrete ideas on how we can improve the AI problem generator."*

---

## 2. Your Project Proposal: "Closed-Loop Self-Correction"

When your professor asks what you want to work on in `jutge-toolkit`, present this:

- **The Problem in `jtk generate problem`:**  
  Currently, the AI generates the solution code and test cases, but it never compiles or runs them during generation. If the AI makes a mistake, the author only finds out later during `jtk make`.
- **Your Proposal:**  
  Add an **automatic feedback loop**:
  1. AI generates `solution.cc` and `*.inp`.
  2. `jtk` immediately compiles and runs the code locally.
  3. If there is a compiler error or runtime crash, `jtk` sends the error message back to the AI to fix itself before saving to disk.
- **Why It Matters:**  
  It guarantees that all AI-generated problems compile cleanly and work out of the box, saving professors from fixing broken drafts by hand.

---

## 3. Important Questions to Ask Your Professor

1. **Scope:**  
   *"Can we confirm that improving `jutge-toolkit` (`jtk`) and its AI generator is my main priority for the 4 months?"*
2. **Priorities:**  
   *"Do you prefer that I start by making `jtk generate problem` self-correcting with a compiler feedback loop, or are there specific authoring features you need first?"*
3. **Repository Workflow:**  
   *"Should I push my work on a feature branch in `jutge-toolkit` and open pull requests for you and Pau to review?"*

---

## 4. Key Terminology Cheat Sheet

| Term | What It Means |
|---|---|
| **`jtk`** | The command-line authoring tool (written in TypeScript / Bun). |
| **`.pbm`** | Problem folder ending with `.pbm` (Problem Package). |
| **Golden Solution** | The reference code (`solution.cc`) that defines what is correct. |
| **`*.inp`** | Input test files fed into the program. |
| **`*.cor`** | Expected correct output files (generated automatically, never written by hand). |
| **`handler.yml`** | Configuration setting the problem mode (`std` for standard I/O, `quiz`, or `game`). |
| **`AC`** | Verdict: **Accepted** (Green semaphore). All test cases passed! |
| **`WA`** | Verdict: **Wrong Answer**. Output does not match the `.cor` file. |
| **`jtk make`** | The command that compiles solutions, generates `.cor`, and builds statement PDFs. |
| **`jtk upload`** | The command that publishes the problem to Jutge.org via API v2. |
