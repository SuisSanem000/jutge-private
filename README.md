# Jutge Private Workspace

> **Welcome:** If you just opened this repository and don't know where to look, start below.

---

## 🧭 Where to Look First

1. **For an instant 15-minute briefing (Senior Dev perspective):**  
   👉 Read [`doc/SENIOR-DEV-BRIEF.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/SENIOR-DEV-BRIEF.md)  
   *Covers the domain, system architecture, core `.pbm` entity, and current technical debt.*

2. **For your upcoming supervisor meeting (November 12th) & 4-hour study plan:**  
   👉 Read [`doc/meeting-20261112/ONBOARDING-STUDY-PLAN-AND-PROPOSALS.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/meeting-20261112/ONBOARDING-STUDY-PLAN-AND-PROPOSALS.md)  
   *Covers your hour-by-hour reading schedule and 3 concrete proposals to present to Jordi Petit and Pau Fernández.*

---

## 📁 Meaning of Folders

```
jutge-private/
│
├── resources/           ⛔ STRICT RULE: MANAGED ONLY BY SIMIN. AI NEVER TOUCHES THIS.
│                        Contains upstream git clones of Jutge repos and original materials
│                        from the professors. Simin pulls updates here via `git pull`.
│
├── doc/                 📖 DOCUMENTATION, STUDY NOTES & MEETING PREP
│                        All analysis, knowledge base files, architectural RFCs, and formal
│                        reports for your professors live here.
│
└── work/                💻 ACTIVE DEVELOPMENT & CODE
                         All your actual code, proofs-of-concept, new modules, and PR
                         branches live here. No duplicating external repos.
```

---

## 🔒 Directory Policies & Non-Negotiable Rules

1. **`resources/` is strictly for Simin (Read-Only to AI):**  
   - This folder holds original copies of `jutge_repos` and `problem-editor`.
   - Simin manages updates here directly (e.g. `git pull`).
   - The AI assistant will **NEVER** edit, create, or delete any file inside `resources/`.

2. **No Folder Duplication:**  
   - Never copy entire repos from `resources/` into `work/` or `doc/`.
   - `work/` contains only new code, isolated packages, and focused PR candidates.

3. **Where New Work Happens:**  
   - Analysis, notes, and meeting documents go in `doc/`.
   - Code, scripts, and prototypes go in `work/`.

---

## 📅 Immediate Next Steps (Meeting on Nov 12)

*   **Study Plan:** Allocate ~4 hours following the schedule in [`ONBOARDING-STUDY-PLAN-AND-PROPOSALS.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/meeting-20261112/ONBOARDING-STUDY-PLAN-AND-PROPOSALS.md).
*   **Pick a Meeting Deliverable:** Choose between **Proposal A** (Architecture RFC & 4-Month Roadmap), **Proposal B** (Working Closed-Loop Verifier POC in `work/`), or the **Recommended Hybrid** (both).
*   **Tell the Assistant to Implement:** Once you approve the proposal track, the AI will implement the complete deliverable so you can share it in the meeting.

