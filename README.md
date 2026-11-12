# Jutge Private Workspace

> **Welcome:** If you just opened this repository and don't know where to look, start below.

---

## 🧭 Where to Look First

1. **For Phase 1 & 2 problem generation with Claude Code (VS Code):**  
   👉 [01. Meeting Presentation & Problem Demo (Nov 12)](./work/01-meeting-presentation-and-demo-20261112/README.md) • [Copy-Paste Prompt](./work/01-meeting-presentation-and-demo-20261112/01-claude-task/CLAUDE-MASTER-PROMPT.md)  
   *Organized into 3 folders: Claude task artifacts, in-depth explanations for you, and tomorrow's presentation.*

2. **For the full English translation of the Problem Editor specs:**  
   👉 [Problem Editor Complete English Translation](./doc/related-core-topics/problem-editor-en-translate-20261111/README.md)  
   *Pure English translation of the constitution, problem anatomy, reference models, and Claude skills.*

3. **For your meeting preparation & 5-hour study plan (Nov 12):**  
   👉 [Meeting Prep & Study Plan (Nov 12)](./doc/meetings-and-next-steps/02-meeting-prep-and-study-plan-20261112.md)  
   *Includes your talking points and proposal pitch for Jordi Petit and Pau Fernandez.*

4. **For the presentation slides & architecture proposal document:**  
   👉 [Proposal & Presentation Document (Nov 12)](./work/01-meeting-presentation-and-demo-20261112/03-for-meeting-tomorrow/PROPOSAL-PRESENTATION-20261112.md)  
   *The structured engineering proposal: jtk v5 architecture, 4-month roadmap, and discussion questions.*

5. **For Problem Definition, Login & Upload Workflow (`jtk upload` guide):**  
   👉 [Problem Definition & Upload Workflow Guide](./doc/related-core-topics/problem-definition-and-upload-workflow/README.md)  
   *Detailed breakdown of the terminal demo from your first meeting, API protocol, and step-by-step upload manual.*

6. **For the Simple 10-Slide Meeting Presentation & Speaking Scripts:**  
   👉 [Simple 10-Slide Summary & Speaking Guide](./work/01-meeting-presentation-and-demo-20261112/summary/README.md) • [PowerPoint Deck (`.pptx`)](./work/01-meeting-presentation-and-demo-20261112/summary/meeting-presentation.pptx)  
   *Simple, conversational 10 slides with 'what to say aloud' scripts, exact commands, and the live 3.7s benchmark results.*

7. **For Project Learning & Skill Tracking (Typst, MCP, WebStreams):**  
   👉 [Learning Tracker & Skill Acquisition Board](./doc/learning-tracker/README.md)  
   *Actionable task tracking file for skills needed in the scholarship, featuring Typst for exam/statement PDF compilation.*

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
│   ├── learning-tracker/                     -> Systematic skill acquisition board (Typst, MCP, WebStreams)
│   ├── related-core-topics/                  -> Deep dives on core workflows & problem-editor translations
│   ├── ai-analysis/                          -> AI assistant system prompt and operational rules
│   ├── understanding/                        -> System architecture, .pbm specs, and codebase debt
│   └── meetings-and-next-steps/              -> Chronological meeting notes, study plans, and logs
│
└── work/                💻 WHAT SIMIN DOES & PRESENTS TO PROFESSORS (Code & Prototypes)
    └── 01-meeting-presentation-and-demo-20261112/ -> Unified meeting package: proposal, generated code, guide & prompt
```

### Quick Folder Navigation

| Folder | What it is |
|---|---|
| [**`resources/`**](./resources/) | Upstream repositories and professor documents (**read-only to AI**). |
| [**`doc/`**](./doc/) | Knowledge base, translations, architecture guides, and meeting plans. |
| ↳ [**`doc/learning-tracker/`**](./doc/learning-tracker/) | Systematic skill acquisition board (Typst, MCP, WebStreams). |
| ↳ [**`doc/related-core-topics/`**](./doc/related-core-topics/) | Deep-dive guides on platform workflows (`jtk upload` guide, English translations). |
| ↳ [**`doc/related-core-topics/problem-editor-en-translate-20261111/`**](./doc/related-core-topics/problem-editor-en-translate-20261111/) | Complete English translation of `problem-editor` (constitution, specs, skills). |
| ↳ [**`doc/understanding/`**](./doc/understanding/) | Codebase architecture, `.pbm` specifications, and rewrite observations. |
| ↳ [**`doc/meetings-and-next-steps/`**](./doc/meetings-and-next-steps/) | Chronological meeting summaries, study plans, and project logs. |
| ↳ [**`doc/ai-analysis/`**](./doc/ai-analysis/) | AI system prompt and operational rules. |
| [**`work/`**](./work/) | Code implementations, active tasks, and deliverables to present. |
| ↳ [**`work/01-meeting-presentation-and-demo-20261112/`**](./work/01-meeting-presentation-and-demo-20261112/) | **Unified Meeting Workspace:** Complete proposal, live generated code (`dominant-peaks.pbm`), walkthrough guide, and master prompt. |

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
