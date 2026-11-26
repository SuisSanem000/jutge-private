# Jutge Workspace

> Workspace for building **`pedit`** (AI-assisted Jutge problem editor CLI + minimal web viewer) on top of unmodified `jtk`.

---

## Where to Look First

1. **AI Rules & Current State:** [AI Assistant Rules](./doc/ai-assistant/rules.md) • [Project State](./doc/project-state/state.md)
2. **Meeting Decisions & Learning Plan:** [Meetings Summary](./doc/project-state/meetings.md) • [Skill Tracker](./doc/project-state/learning.md)
3. **Core Workflows & Translations:** [Upload Workflow](./doc/core-topics/upload-workflow.md) • [Problem Editor (EN)](./doc/core-topics/problem-editor-en/readme.md)
4. **Architecture & `.pbm` Reference:** [Documentation Map](./doc/readme.md) • [Brief](./doc/understanding/01-brief.md) • [`.pbm` Format](./doc/understanding/04-pbm-format.md)
5. **Deliverable Phases:** [Projects Index](./projects/readme.md) • [Phase 01 Demo (2026-11-12)](./projects/01-demo-20261112/README.md)

---

## Directory Structure

```text
jutge-private/
├── resources/                  # Read-only upstream & professor materials (tracked & pushed)
│   └── private-local/          # Local-only repos, notes, credentials (gitignored)
├── doc/                        # AI rules, dated AI logs, project state, specs & architecture docs
│   ├── ai-assistant/
│   ├── ai-log/
│   ├── project-state/
│   ├── core-topics/
│   └── understanding/
└── projects/                   # 10–15 day deliverable phases for supervisors
    ├── 01-demo-20261112/
    └── 02/
```

## Key Policies

- **`resources/` is read-only for AI:** Professor materials in `resources/` are tracked and pushed, while `resources/private-local/` stays strictly local and gitignored.
- **No leaked secrets or local paths:** Credentials and local machine paths never enter tracked files.
- **Short lowercase-with-dashes naming:** Used across `doc/` and `projects/` for clarity and traceability.
