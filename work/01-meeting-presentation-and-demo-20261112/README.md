# Task 01: Meeting Presentation & Claude Problem Demo (November 12)

> **Workspace:** `work/01-meeting-presentation-and-demo-20261112/`  
> **Meeting Date:** November 12, 2026  
> **Supervisors:** Prof. Jordi Petit & Pau Fernandez  
> **Author:** Simin Shoeibi  
> **Navigation:** [Root Workspace](../../README.md) • [Work Directory](../README.md)

---

## Clean 3-Folder Structure

Everything in this task directory is cleanly decoupled into three dedicated subfolders:

```text
work/01-meeting-presentation-and-demo-20261112/
│
├── summary/                     🌟 SIMPLIFIED 10-SLIDE PRESENTATION & SUMMARY
│   ├── README.md                # Simple 10-slide summary with "What to say aloud" scripts & commands
│   └── meeting-presentation.pptx# Simple 10-slide PowerPoint presentation deck
│
├── 01-claude-task/              🤖 CLAUDE CODE TASK & GENERATED SOLUTION
│   ├── README.md                # Overview of the Claude task & verification
│   ├── claude-expalanation-of-the-task.md # Claude's self-explanation & audit of results
│   ├── CLAUDE-MASTER-PROMPT.md  # Master prompt to copy-paste into Claude Code in VS Code
│   ├── HOW-TO-USE-CLAUDE-CODE.md# Step-by-step VS Code instructions and terminal commands
│   ├── sample-problem-idea/     # Algorithmic idea: "Dominant Mountain Peaks"
│   └── dominant-peaks.pbm/      # Complete generated problem (solution.cc, generate.ts, etc.)
│
├── 02-explanations-for-simin/   📖 DEEP-DIVE STUDY NOTES FOR SIMIN
│   ├── README.md                # Explanations summary
│   ├── 01-what-is-problem-editor.md # Origin, pain points, SaaS vision, and 4 phases
│   └── 02-what-did-i-do.md      # Simin's execution: Phase 1 study, Phase 2 demo, jtk finding
│
└── 03-for-meeting-tomorrow/     💼 MATERIALS TO TAKE TO THE MEETING
    ├── README.md                # Meeting checklist & timeline
    ├── PROPOSAL-PRESENTATION-20261112.md # Architecture proposal (jtk v5, 4-month roadmap)
    ├── 01-meeting-speaking-script.md     # Word-for-word script & live terminal demo steps
    └── 02-questions-to-ask-professors.md # Key decision questions for Jordi & Pau
```

---

## Quick Navigation Links

| Subfolder | Purpose & Contents |
|---|---|
| [**`summary/`**](./summary/README.md) | **Simple 10-Slide Presentation & Speaking Script:**<br>• [10 simple slides with conversational "What to say aloud" scripts & live commands](./summary/README.md)<br>• [Simplified PowerPoint Deck (`summary/meeting-presentation.pptx`)](./summary/meeting-presentation.pptx) |
| [**`01-claude-task/`**](./01-claude-task/README.md) | **The Claude Task:**<br>• [Claude's Self-Report](./01-claude-task/claude-expalanation-of-the-task.md)<br>• [Master Prompt](./01-claude-task/CLAUDE-MASTER-PROMPT.md)<br>• [VS Code Execution Guide](./01-claude-task/HOW-TO-USE-CLAUDE-CODE.md)<br>• [Problem Idea (`IDEA.md`)](./01-claude-task/sample-problem-idea/IDEA.md)<br>• [Generated Problem Code (`dominant-peaks.pbm/`)](./01-claude-task/dominant-peaks.pbm/) |
| [**`02-explanations-for-simin/`**](./02-explanations-for-simin/README.md) | **Deep-Dive Explanations for Simin:**<br>• [What is `problem-editor`?](./02-explanations-for-simin/01-what-is-problem-editor.md)<br>• [What did I do?](./02-explanations-for-simin/02-what-did-i-do.md) |
| [**`03-for-meeting-tomorrow/`**](./03-for-meeting-tomorrow/README.md) | **Materials for Tomorrow's Meeting:**<br>• [Engineering Proposal & Roadmap](./03-for-meeting-tomorrow/PROPOSAL-PRESENTATION-20261112.md)<br>• [Speaking Script & Live Demo](./03-for-meeting-tomorrow/01-meeting-speaking-script.md)<br>• [Key Questions to Ask Supervisors](./03-for-meeting-tomorrow/02-questions-to-ask-professors.md) |

---

## Quick Meeting Strategy

1. **Phase 1 & 2 Execution:** Open [**`01-meeting-speaking-script.md`**](./03-for-meeting-tomorrow/01-meeting-speaking-script.md) and review how you explain Phase 1 format mastery and demonstrate the generated problem in [**`01-claude-task/dominant-peaks.pbm/`**](./01-claude-task/dominant-peaks.pbm/).
2. **Phase 3 Architecture Pitch:** Screen-share [**`PROPOSAL-PRESENTATION-20261112.md`**](./03-for-meeting-tomorrow/PROPOSAL-PRESENTATION-20261112.md) to pitch the 4-month rebuild of `jtk` into a decoupled headless engine (`@jutge/core`).
3. **Decisions:** Use [**`02-questions-to-ask-professors.md`**](./03-for-meeting-tomorrow/02-questions-to-ask-professors.md) to get decisions on repo workflow, review process, and language scope.
