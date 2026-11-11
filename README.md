# Jutge Private Workspace

> **Welcome:** If you just opened this repository and don't know where to look, start below.

---

## 🧭 Where to Look First

1. **For Phase 1 & 2 problem generation with Claude Code (VS Code):**  
   👉 [Claude Code Master Prompt & Execution Guide](./doc/ai-analysis/delegate-to-claude/HOW-TO-USE-CLAUDE-CODE.md) • [Copy-Paste Prompt](./doc/ai-analysis/delegate-to-claude/CLAUDE-MASTER-PROMPT.md)  
   *Includes exact step-by-step instructions for the Claude VS Code extension, master prompt, and presentation script.*

2. **For the full English translation of the Problem Editor specs:**  
   👉 [Problem Editor Complete English Translation](./doc/problem-editor-en-translate-20261111/README.md)  
   *Pure English translation of the constitution, problem anatomy, reference models, and Claude skills.*

3. **For your meeting preparation & 5-hour study plan (Nov 12):**  
   👉 [Meeting Prep & Study Plan (Nov 12)](./doc/meetings-and-next-steps/02-meeting-prep-and-study-plan-20261112.md)  
   *Includes your talking points and proposal pitch for Jordi Petit and Pau Fernandez.*

4. **For the presentation slides & architecture proposal document:**  
   👉 [Proposal & Presentation Document (Nov 12)](./work/03-meeting-presentation-20261112/PROPOSAL-PRESENTATION-20261112.md)  
   *The structured engineering proposal: jtk v5 architecture, 4-month roadmap, and discussion questions.*

---

## 📁 Meaning of Folders

```
jutge-private/
│
├── resources/           ⛔ STRICT RULE: MANAGED ONLY BY SIMIN. AI NEVER TOUCHES THIS.
│                        Contains upstream git clones of Jutge repos and original materials
│                        from the professors. Simin pulls updates here via `git pull`.
│
├── doc/                 📖 WHAT AI EXPLAINS TO SIMIN (Knowledge, Translations & Meetings)
│   ├── problem-editor-en-translate-20261111/ -> Complete English translation of problem-editor
│   ├── ai-analysis/ (or ai-assistant/)       -> System prompt & delegate-to-claude master prompt
│   ├── understanding/                        -> System architecture, .pbm specs, and codebase debt
│   └── meetings-and-next-steps/              -> Chronological meeting notes, study plans, and logs
│
└── work/                💻 WHAT SIMIN DOES & PRESENTS TO PROFESSORS (Code & Prototypes)
    ├── problem-generation-claude-20261111/   -> Phase 1 & 2: Claude problem generation target & idea
    └── 03-meeting-presentation-20261112/     -> Proposal & presentation for Nov 12 meeting
```

### Quick Folder Navigation

| Folder | What it is |
|---|---|
| [**`resources/`**](./resources/) | Upstream repositories and professor documents (**read-only to AI**). |
| [**`doc/`**](./doc/) | Knowledge base, translations, architecture guides, and meeting plans. |
| ↳ [**`doc/ai-assistant/delegate-to-claude/`**](./doc/ai-analysis/delegate-to-claude/) | **Delegate to Claude:** Master prompt and step-by-step VS Code guide. |
| ↳ [**`doc/problem-editor-en-translate-20261111/`**](./doc/problem-editor-en-translate-20261111/) | Complete English translation of `problem-editor` (constitution, specs, skills). |
| ↳ [**`doc/understanding/`**](./doc/understanding/) | Codebase architecture, `.pbm` specifications, and rewrite observations. |
| ↳ [**`doc/meetings-and-next-steps/`**](./doc/meetings-and-next-steps/) | Chronological meeting summaries, study plans, and project logs. |
| ↳ [**`doc/ai-analysis/`**](./doc/ai-analysis/) | AI system prompt and operational rules. |
| [**`work/`**](./work/) | Code implementations, active tasks, and deliverables to present. |
| ↳ [**`work/problem-generation-claude-20261111/`**](./work/problem-generation-claude-20261111/) | **Core Focus:** Target directory for generated problem (`dominant-peaks.pbm`) and sample idea. |
| ↳ [**`work/03-meeting-presentation-20261112/`**](./work/03-meeting-presentation-20261112/) | Architectural proposal and 4-month roadmap for November 12 meeting. |

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
