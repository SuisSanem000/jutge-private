# Jutge Private Workspace

> **Welcome:** If you just opened this repository and don't know where to look, start below.

---

## 🧭 Where to Look First

1. **For your 5-hour study plan & tomorrow's meeting preparation (Nov 12):**  
   👉 [Meeting Prep & Study Plan (Nov 12)](./doc/meetings-and-next-steps/02-meeting-prep-and-study-plan-20261112.md)  
   *Includes your block-by-block study roadmap, talking points, and pitch for Jordi Petit and Pau Fernandez.*

2. **For what you can present/share on screen with your professors tomorrow:**  
   👉 [Proposal & Presentation Document (Nov 12)](./work/03-meeting-presentation-20261112/PROPOSAL-PRESENTATION-20261112.md)  
   *The structured engineering proposal: jtk v5 architecture, 4-month roadmap, and discussion questions.*

3. **For an instant 15-minute senior developer domain briefing:**  
   👉 [Senior Developer Onboarding Brief](./doc/understanding/01-senior-dev-brief.md)  
   *Covers the Jutge domain, system architecture, `.pbm` format, and current technical debt.*

---

## 📁 Meaning of Folders

```
jutge-private/
│
├── resources/           ⛔ STRICT RULE: MANAGED ONLY BY SIMIN. AI NEVER TOUCHES THIS.
│                        Contains upstream git clones of Jutge repos and original materials
│                        from the professors. Simin pulls updates here via `git pull`.
│
├── doc/                 📖 WHAT AI EXPLAINS TO SIMIN (Knowledge, Prompts & Meetings)
│   ├── ai-analysis/                 -> AI settings, system prompt, and API mechanics
│   ├── understanding/               -> System architecture, .pbm specs, and codebase debt
│   └── meetings-and-next-steps/     -> Chronological meeting notes, study plans, and logs
│
└── work/                💻 WHAT SIMIN DOES & PRESENTS TO PROFESSORS (Code & Tasks)
    ├── 01-task-problem-editor-analysis-20261103/ -> Analysis of Pau's problem-editor
    ├── 02-task-meeting-followups-20261103/       -> Action items from Oct 22 kickoff
    └── 03-meeting-presentation-20261112/         -> Proposal & presentation for Nov 12 meeting
```

### Quick Folder Navigation

| Folder | What it is |
|---|---|
| [**`resources/`**](./resources/) | Upstream repositories and professor documents (**read-only to AI**). |
| [**`doc/`**](./doc/) | Knowledge base, AI prompts, architecture guides, and meeting plans. |
| ↳ [**`doc/ai-analysis/`**](./doc/ai-analysis/) | AI system prompt and JutgeAI generation mechanics. |
| ↳ [**`doc/understanding/`**](./doc/understanding/) | Codebase architecture, `.pbm` specifications, and rewrite observations. |
| ↳ [**`doc/meetings-and-next-steps/`**](./doc/meetings-and-next-steps/) | Chronological meeting summaries, study plans, and project logs. |
| [**`work/`**](./work/) | Code implementations, active tasks, and deliverables to present. |
| ↳ [**`work/01-task-problem-editor-analysis-20261103/`**](./work/01-task-problem-editor-analysis-20261103/) | Task 01: Audit of problem-editor specifications and models. |
| ↳ [**`work/02-task-meeting-followups-20261103/`**](./work/02-task-meeting-followups-20261103/) | Task 02: Tracking action items from the October 22 kickoff. |
| ↳ [**`work/03-meeting-presentation-20261112/`**](./work/03-meeting-presentation-20261112/) | Task 03: Engineering proposal and slides for the November 12 meeting. |

---

## 🔒 Directory Policies & Naming Rules

1. **`resources/` is strictly for Simin (Read-Only to AI):**  
   - This folder holds original copies of `jutge_repos` and `problem-editor`.
   - Simin manages updates here directly (e.g. `git pull`).
   - The AI assistant will **NEVER** edit, create, or delete any file inside `resources/`.

2. **Subfolder Naming Standard (`work/` and `doc/meetings-and-next-steps/`):**  
   - Every chronological folder and file begins with a two-digit order number and ends with the date:  
     `NN-<short-name>-YYYYMMDD` (e.g. `02-meeting-prep-and-study-plan-20261112.md`, `03-meeting-presentation-20261112/`).

3. **No Folder Duplication:**  
   - Never copy entire repos from `resources/` into `work/` or `doc/`.
   - `work/` contains only targeted code modules, tasks, and presentation materials.
