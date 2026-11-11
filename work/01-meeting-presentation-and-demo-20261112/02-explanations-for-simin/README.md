# Folder 02: Explanations for Simin (Study & Deep-Dive Notes)

> **Location:** `work/01-meeting-presentation-and-demo-20261112/02-explanations-for-simin/`  
> **Purpose:** Deep-dive explanations answering the two core questions: What is `problem-editor`, and what did Simin do?  
> **Parent Navigation:** [Task 01 Root Overview](../README.md) • [Claude Task & Generated Code](../01-claude-task/README.md) • [Meeting Materials](../03-for-meeting-tomorrow/README.md)

---

## Documents in This Folder

This folder provides in-depth technical briefings written specifically for you to ramp up and understand every moving part before tomorrow's meeting:

| Document | Core Topics Covered |
|---|---|
| [**`01-what-is-problem-editor.md`**](./01-what-is-problem-editor.md) | **Deep Dive on `problem-editor`:**<br>• The real-world problem professors face when authoring problems by hand.<br>• Pau Fernandez's vision for an AI-assisted Next.js SaaS Web Application (*"Google Docs for Problems"*).<br>• The 4 proposed phases from Pau's README.<br>• Full breakdown of upstream folders (`spec/`, `skills/`, `models/`, `generated-exam-sample/`, `private-problems/`). |
| [**`02-what-did-i-do.md`**](./02-what-did-i-do.md) | **Deep Dive on Simin's Execution:**<br>• Phase 1 format mastery (directory anatomy, C++17 constitution, `.cor` invariant).<br>• Phase 2 implementation with Claude Code (algorithm design, prompt delegation, generated problem files).<br>• Local compilation and verification using `jtk make exe cor`.<br>• The key engineering finding: why current `jtk` must be rebuilt into a decoupled engine (`@jutge/core`) to enable the Phase 3 web editor. |

---

## Key Takeaway Summary

1. **`problem-editor` is the blueprint for an AI SaaS platform:** It contains the rules, reference models, and skills that allow an AI agent to build problems for teachers.
2. **You proved that Phase 1 & 2 work:** You used Claude Code to generate a complete, working problem that compiles, runs, and passes `jtk lint`.
3. **You discovered the missing link:** An AI agent in a web editor needs structured JSON outputs and closed-loop verification, which current `jtk` does not provide. That is the mandate of your 4-month internship.
