# Documentation (`doc/`) Map

> **Purpose:** `doc/` contains everything the AI analyzes, clarifies, or structures for Simin.

---

## Folder Organization

```
doc/
│
├── learning-tracker/            🎯 LIVING LEARNING & SKILL TRACKING
│   └── README.md                   # Systematic skill acquisition board (Typst, MCP, WebStreams)
│
├── ai-analysis/                 🤖 AI SETTINGS & SYSTEM PROMPTS ONLY
│   └── 01-ai-system-prompt.md      # System prompt and operational rules for AI assistants
│
├── related-core-topics/         🔬 CORE PLATFORM WORKFLOWS & RESEARCH
│   ├── problem-editor-en-translate-20261111/   # Complete English translation of problem-editor
│   └── problem-definition-and-upload-workflow/ # jtk login, scaffolding, web services & upload guide
│
├── understanding/                  💡 CODEBASE & DOMAIN KNOWLEDGE
│   ├── 01-senior-dev-brief.md      # 15-minute high-level briefing for senior developers
│   ├── 02-ecosystem.md             # Architecture and repository relationships
│   ├── 03-jtk-architecture.md      # Existing jtk CLI execution flows
│   ├── 04-problem-format-and-grading.md # .pbm anatomy, LaTeX, YAML specs, judge grading
│   ├── 05-ai-problem-generation-analysis.md # Comparison of jtk generate vs Problem Editor
│   ├── 06-jtk-rewrite-observations.md   # Code smells, bugs, and technical debt in jtk
│   ├── 07-commands-and-glossary.md      # CLI cheat sheet & domain glossary
│   └── 08-source-verification-log.md   # Audit log of verified facts vs inferences
│
└── meetings-and-next-steps/        📅 MEETINGS & CHRONOLOGICAL STUDY PLANS
    ├── 01-meeting-notes-summary-20261022.md # Summary & analysis of kickoff meeting
    ├── 02-meeting-prep-and-study-plan-20261112.md # 5-hour study plan & proposal pitch
    └── 03-project-state-and-living-log-20261111.md # Living project state and decision log
```

### Quick Navigation Links

| Section | Documents |
|---|---|
| [**`learning-tracker/`**](./learning-tracker/) | • [Learning Tracker & Skill Acquisition Board](./learning-tracker/README.md) *(Typst task checklist, MCP, WebStreams)* |
| [**`related-core-topics/`**](./related-core-topics/) | • [Problem Definition & Upload Workflow](./related-core-topics/problem-definition-and-upload-workflow/README.md) *(jtk login, upload, webstream API & guide)*<br>• [Problem Editor Complete Translation](./related-core-topics/problem-editor-en-translate-20261111/README.md)<br>• [Pedagogical Constitution](./related-core-topics/problem-editor-en-translate-20261111/spec/constitution.md)<br>• [Problem Specification](./related-core-topics/problem-editor-en-translate-20261111/spec/problem-spec.md)<br>• [Reference Models Guide](./related-core-topics/problem-editor-en-translate-20261111/spec/models-guide.md)<br>• [Problem Creation Skill](./related-core-topics/problem-editor-en-translate-20261111/skills/jutge-problems/SKILL.md) |
| [**`ai-analysis/`**](./ai-analysis/) | • [01. AI System Prompt](./ai-analysis/01-ai-system-prompt.md) |
| [**`understanding/`**](./understanding/) | • [01. Senior Dev Brief](./understanding/01-senior-dev-brief.md)<br>• [02. Ecosystem & Repos](./understanding/02-ecosystem.md)<br>• [03. jtk Architecture](./understanding/03-jtk-architecture.md)<br>• [04. Problem Format & Grading](./understanding/04-problem-format-and-grading.md)<br>• [05. AI Problem Generation Analysis](./understanding/05-ai-problem-generation-analysis.md)<br>• [06. jtk Rewrite Observations](./understanding/06-jtk-rewrite-observations.md)<br>• [07. Commands & Glossary](./understanding/07-commands-and-glossary.md)<br>• [08. Source Verification Log](./understanding/08-source-verification-log.md) |
| [**`meetings-and-next-steps/`**](./meetings-and-next-steps/) | • [01. Kickoff Meeting Notes Summary (2026-10-22)](./meetings-and-next-steps/01-meeting-notes-summary-20261022.md)<br>• [02. Meeting Prep & 5-Hour Study Plan (2026-11-12)](./meetings-and-next-steps/02-meeting-prep-and-study-plan-20261112.md)<br>• [03. Project State & Living Log](./meetings-and-next-steps/03-project-state-and-living-log-20261111.md) |

---

## Non-Negotiable Rules

1. **`resources/` is untouched:** `resources/` holds upstream mirrors managed solely by Simin.
2. **`doc/` vs `work/`:** Explanations and knowledge belong in `doc/`. Code, implementation tasks, and professor presentations belong in `work/`.
3. **Naming Convention:** All chronological files in `meetings-and-next-steps/` have an order number at the start and a date at the end (`NN-name-YYYYMMDD.md`).
