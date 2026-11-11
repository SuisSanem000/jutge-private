# Meeting Speaking Script & Live Demo Walkthrough (November 12)

> **Location:** `work/01-meeting-presentation-and-demo-20261112/03-for-meeting-tomorrow/01-meeting-speaking-script.md`  
> **Audience:** Prof. Jordi Petit & Pau Fernandez  
> **Parent Navigation:** [Meeting Materials Overview](./README.md) • [Engineering Proposal](./PROPOSAL-PRESENTATION-20261112.md) • [Questions to Ask](./02-questions-to-ask-professors.md) • [Task 01 Root](../README.md)

---

## 1. Meeting Agenda & Timeline (30–45 min total)

1. **Opener & Credibility (3 min):** Roadmap alignment with Pau's `problem-editor`.
2. **Phase 1 Summary (5 min):** What you learned about `.pbm` anatomy and the C++17 constitution.
3. **Phase 2 Live Demonstration (10 min):** Showing the generated problem (`dominant-peaks.pbm`) and running `jtk make` live.
4. **Phase 3 Architecture Pitch (10 min):** Why `jtk` must be rebuilt as a decoupled engine (`@jutge/core`).
5. **Decisions & Next Steps (10 min):** Asking the key questions from [Questions to Ask](./02-questions-to-ask-professors.md).

---

## 2. Word-for-Word Speaking Script

### Part 1: The Opener (Roadmap Alignment)
> *"Good morning Jordi and Pau. Over the past two weeks, I conducted an in-depth audit of the ecosystem and reviewed the roadmap outlined in Pau's `problem-editor` repository.*
>
> *I saw that your stated roadmap begins with Phase 1: Learn the Problem Format, and Phase 2: Use skills to generate problems using an AI agent.*
>
> *Rather than just presenting theoretical ideas, I decided to execute both Phase 1 and Phase 2 directly to validate the workflow before we begin architectural discussions."*

### Part 2: Phase 1 Mastery (Format & Pedagogy)
> *"For Phase 1, I studied the `.pbm` directory anatomy, the YAML configuration schemas, and the 7 reference models in `spec/models/`.*
>
> *I paid close attention to the C++17 Pedagogical Constitution: early exit on searches, no `std::unordered_map` or lambdas, and prioritizing clean, readable code.*
>
> *I also internalized the core invariant that `.cor` expected output files must never be written by hand or by LLMs; they must be produced deterministically by running the golden solution via `jtk make`."*

### Part 3: Phase 2 Live Demonstration (The Generated Problem)
> *"For Phase 2, I tested generating a real problem using Claude Code loaded with Pau's skills running directly inside the `problem-editor` repository:*
>
> 1. *I designed an algorithmic problem: 'Dominant Mountain Peaks'—finding peaks that are strictly higher than all peaks to their right.*
> 2. *Claude Code read the specifications in `spec/` and generated the complete package in English: LaTeX statement, optimal $O(N)$ solution, naive $O(N^2)$ solution, Bun test generator, and YAML configs.*
> 3. *Let me open my terminal and show you `dominant-peaks.pbm` right now."*

#### 💻 Live Terminal Demo (Screen Share)
Run these commands in front of your supervisors:

```bash
# 1. Enter the problem directory
cd dominant-peaks.pbm

# 2. Show that generate.ts produces private test cases
./generate.ts

# 3. Compile the golden solution and generate .cor files
jtk make exe cor

# 4. Show that jtk lint passes with 0 errors
jtk lint

# 5. Run the slow solution to demonstrate that it exceeds the time limit
jtk verify solution-slow.cc
```

Explain what they are seeing on screen:
> *"As you can see:*
> *• The golden solution executes in at most **0.41 seconds** on 100,000 elements.*
> *• The naive $O(N^2)$ solution takes **3.8 seconds** on the monotonic test case, running over 9× slower and properly failing the efficiency test.*
> *• `jtk lint` confirms 100% adherence to formatting and file conventions."*

### Part 4: The Pivot to Phase 3 & The 4-Month Rebuild
> *"Executing Phase 2 directly brought me to my main engineering conclusion for Phase 3 (the Next.js SaaS Web Editor):*
>
> *Current `jtk` was built as a human interactive CLI with terminal spinners and console prompts. It cannot be imported as a headless TypeScript package, and it does not provide machine-readable JSON output (`--json`).*
>
> *When an AI agent inside a web editor generates code that fails compilation or test limits, it receives unstructured terminal text rather than typed error objects. This makes automated self-correction brittle.*
>
> *For my 4-month internship, I propose rebuilding `jtk` from the ground up as a decoupled engine (`@jutge/core`) with a machine-readable CLI/MCP interface and full Vitest test coverage.*
>
> *I prepared a structured 4-month architecture proposal document for today's meeting, and I would love to walk through it with you."*

*(Open [**`PROPOSAL-PRESENTATION-20261112.md`**](./PROPOSAL-PRESENTATION-20261112.md)).*

