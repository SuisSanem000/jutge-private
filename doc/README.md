# Documentation (`doc/`) Map

> **Purpose:** `doc/` contains everything the AI analyzes, clarifies, or structures for Simin.

---

## Folder Organization

```
doc/
│
├── ai-analysis/                 🤖 AI SETTINGS & PROMPTS ONLY
│   ├── 01-ai-system-prompt.md   # System prompt and operational rules for AI assistants
│   └── 02-ai-generation-and-skills.md # JutgeAI API mechanics and Pau's Claude skills
│
├── understanding/               💡 CODEBASE & DOMAIN KNOWLEDGE
│   ├── 01-senior-dev-brief.md   # 15-minute high-level briefing for senior developers
│   ├── 02-ecosystem.md          # Architecture and repository relationships
│   ├── 03-jtk-architecture.md   # Existing jtk CLI execution flows
│   ├── 04-problem-format-and-grading.md # .pbm anatomy, LaTeX, YAML specs, judge grading
│   ├── 05-jtk-rewrite-observations.md   # Code smells, bugs, and technical debt in jtk
│   ├── 06-commands-and-glossary.md      # CLI cheat sheet & domain glossary
│   └── 07-source-verification-log.md   # Audit log of verified facts vs inferences
│
└── meetings-and-next-steps/     📅 MEETINGS & CHRONOLOGICAL STUDY PLANS
    ├── 01-meeting-notes-summary-20261022.md # Summary & analysis of kickoff meeting
    ├── 02-meeting-prep-and-study-plan-20261112.md # 5-hour study plan & proposal pitch
    └── 03-project-state-and-living-log-20261111.md # Living project state and decision log
```

### Quick Navigation Links

| Section | Documents |
|---|---|
| [**`ai-analysis/`**](./ai-analysis/) | • [01. AI System Prompt](./ai-analysis/01-ai-system-prompt.md)<br>• [02. AI Generation & Skills](./ai-analysis/02-ai-generation-and-skills.md) |
| [**`understanding/`**](./understanding/) | • [01. Senior Dev Brief](./understanding/01-senior-dev-brief.md)<br>• [02. Ecosystem & Repos](./understanding/02-ecosystem.md)<br>• [03. jtk Architecture](./understanding/03-jtk-architecture.md)<br>• [04. Problem Format & Grading](./understanding/04-problem-format-and-grading.md)<br>• [05. jtk Rewrite Observations](./understanding/05-jtk-rewrite-observations.md)<br>• [06. Commands & Glossary](./understanding/06-commands-and-glossary.md)<br>• [07. Source Verification Log](./understanding/07-source-verification-log.md) |
| [**`meetings-and-next-steps/`**](./meetings-and-next-steps/) | • [01. Kickoff Meeting Notes Summary (2026-10-22)](./meetings-and-next-steps/01-meeting-notes-summary-20261022.md)<br>• [02. Meeting Prep & 5-Hour Study Plan (2026-11-12)](./meetings-and-next-steps/02-meeting-prep-and-study-plan-20261112.md)<br>• [03. Project State & Living Log](./meetings-and-next-steps/03-project-state-and-living-log-20261111.md) |

---

## Non-Negotiable Rules

1. **`resources/` is untouched:** `resources/` holds upstream mirrors managed solely by Simin.
2. **`doc/` vs `work/`:** Explanations and knowledge belong in `doc/`. Code, implementation tasks, and professor presentations belong in `work/`.
3. **Naming Convention:** All chronological files in `meetings-and-next-steps/` have an order number at the start and a date at the end (`NN-name-YYYYMMDD.md`).
