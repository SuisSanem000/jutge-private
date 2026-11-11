# Meeting Notes Summary & Analysis (2026-10-22)

> **Context:** Kickoff meeting between Simin and the professors (Jordi Petit, Pau Fernandez).  
> **Source:** `resources/original-info-from-professors/meeting notes 20261022.md` (read-only reference).

---

## 1. What Was Discussed & Why This Project Exists

1. **The Problem with Problems:**
   * Jutge's problem bank gets exhausted: existing problems leak or are solved by students from past semesters.
   * Creating high-quality competitive/exam problems manually is slow and hard for most professors.
   * **Goal:** Use AI to democratize and automate problem authoring so teachers can generate high-quality, verified problems easily.

2. **The Tooling & Ecosystem:**
   * **`jtk` (`@jutge.org/toolkit`):** The primary CLI authoring tool. This is what teachers and tools interact with to make, verify, and upload problems. Simin's mandate is to restructure and rebuild this tool.
   * **Claude Skills / Problem Editor:** Pau Fernandez prepared initial AI skills (problem-creation skill) and specifications to guide an LLM agent in creating problems.
   * **User Interface:** Pau proposed a SaaS web service (eventual Next.js web editor) where teachers interact with an AI agent.

3. **Courses & Problem Varieties:**
   * Jordi's courses cover multiple languages: C++, Python, Haskell, Clojure.
   * Two main problem formats:
     * **I/O problems:** Full standard input/output programs (`std::cin` -> `std::cout`).
     * **Function problems:** Student submits a function or class only; merged with teacher's `main.cc` / harness.

---

## 2. Deliverables Expected From Professors vs What Actually Arrived

| Item from Notes | Status | Evidence in Workspace |
|---|---|---|
| Problem-making documentation & format spec | **Received** | See translated [Problem Spec](../problem-editor-en-translate-20261111/spec/problem-spec.md) and [Constitution](../problem-editor-en-translate-20261111/spec/constitution.md). |
| Claude skills from Pau | **Received** | See translated [Problem Creation Skill](../problem-editor-en-translate-20261111/skills/jutge-problems/SKILL.md) and [Review Skill](../problem-editor-en-translate-20261111/skills/review-jutge-problems/SKILL.md). |
| Sample problems | **Received** | See [Reference Models Guide](../problem-editor-en-translate-20261111/spec/models-guide.md) (7 reference models) and [Problem Editor Overview](../problem-editor-en-translate-20261111/README.md). |
| Private problems repository | **Received** | Added by Jordi Petit on 2026-10-27 in original `problem-editor/private-problems/` (with EDA, AP1, AP2 problems). |
| Token / LLM budget | **Pending / Unclear** | Mentions JutgeAI token endpoint, but direct budget/quota limits are not formalized. |
| jtk repository access & review workflow | **Needs Discussion** | Need to agree on git workflow for the rewrite in the Nov 12 meeting. |

