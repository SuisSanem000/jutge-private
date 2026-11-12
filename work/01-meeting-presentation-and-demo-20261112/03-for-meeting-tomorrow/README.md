# Folder 03: Materials to Take to Tomorrow's Meeting (November 12)

> **Location:** `work/01-meeting-presentation-and-demo-20261112/03-for-meeting-tomorrow/`  
> **Meeting Date:** November 12, 2026  
> **Supervisors:** Prof. Jordi Petit & Pau Fernandez  
> **Parent Navigation:** [Task 01 Root Overview](../README.md) • [Claude Task & Generated Code](../01-claude-task/README.md) • [Explanations for Simin](../02-explanations-for-simin/README.md)

---

## What Is in This Folder?

This folder contains all the materials, presentation notes, scripts, and decision questions you should take into tomorrow's meeting:

| Document | Purpose & Content |
|---|---|
| [**`checking-and-uploading-the-problem-I-made.md`**](../checking-and-uploading-the-problem-I-made.md) | **Live Demo Cheat Sheet:** Clean, sequential one-line commands to check, verify, upload, and test your problem on Jutge.org in front of your professors. |
| [**`PROPOSAL-PRESENTATION-20261112.md`**](./PROPOSAL-PRESENTATION-20261112.md) | **The Architecture Proposal:** Formal engineering document detailing findings in legacy `jtk`, the `@jutge/core` decoupled architecture, the 4-month milestone roadmap, and system diagrams. |
| [**`01-meeting-speaking-script.md`**](./01-meeting-speaking-script.md) | **Speaking Script & Live Demo:** Word-for-word talking points, opener, live terminal demonstration steps, and how to transition to the proposal pitch. |
| [**`02-questions-to-ask-professors.md`**](./02-questions-to-ask-professors.md) | **Key Questions for Supervisors:** Specific, senior-level questions for Jordi Petit and Pau Fernandez (git workflow, MCP vs CLI `--json`, language scope, and storage conventions). |

---

## Meeting Day Checklist

### 1. Before Joining the Call
- Open your terminal and navigate to the generated problem directory:
  ```bash
  cd work/01-meeting-presentation-and-demo-20261112/01-claude-task/dominant-peaks.pbm
  ```
  *(Or in your separate `problem-editor` workspace: `cd dominant-peaks.pbm`).*
- Open [**`01-meeting-speaking-script.md`**](./01-meeting-speaking-script.md) on your screen for quick reference.
- Have [**`PROPOSAL-PRESENTATION-20261112.md`**](./PROPOSAL-PRESENTATION-20261112.md) open and ready to screen-share.

### 2. During the Meeting
1. **Deliver the Opener:** Explain that you aligned your ramp-up with Pau's stated roadmap (Phase 1 & Phase 2).
2. **Run the Live Demo:** Run `jtk make exe cor && jtk lint && jtk verify solution-slow.cc` live. Show the 0.41s vs 3.8s execution difference!
3. **Present the Proposal:** Share your screen on `PROPOSAL-PRESENTATION-20261112.md` to walk through the 4-month `@jutge/core` plan.
4. **Ask the Questions:** Go through [**`02-questions-to-ask-professors.md`**](./02-questions-to-ask-professors.md) to get concrete decisions on repository access and review workflows.

