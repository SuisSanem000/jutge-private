# Jutge Workspace

> UPC scholarship workspace for **`jtk` (`@jutge.org/toolkit`)** and the Jutge.org problem-authoring & AI tooling ecosystem.

**Live GitHub Pages (Latest):** [02 — `pedit` CLI & PDF Viewer](https://suissanem000.github.io/jutge-private/02/pedit-cli-and-pdf-viewer/) • [CLI](https://suissanem000.github.io/jutge-private/02/pedit-cli-and-pdf-viewer/cli/) • [PDF Viewer](https://suissanem000.github.io/jutge-private/02/pedit-cli-and-pdf-viewer/pdf-viewer/)

## Table of Contents

- [Where to Look First](#where-to-look-first)
- [Directory Structure](#directory-structure)
- [Key Policies](#key-policies)

---

## Where to Look First

1. **AI Entry & Current State:** [AI Start Here](./doc/ai-assistant/start-here.md) • [AI Assistant Rules](./doc/ai-assistant/rules.md) • [Project State](./doc/project-state/state.md)
2. **Learning Plan:** [Skill Tracker](./doc/project-state/learning.md)
3. **Architecture & `jtk` Reference:** [Documentation Map](./doc/readme.md) • [Ecosystem](./doc/understanding/01-ecosystem.md) • [`.pbm` Format](./doc/understanding/03-pbm-format.md)
4. **Core Workflows & Translations:** [Upload Workflow](./doc/core-topics/upload-workflow.md) • [Problem Editor (EN)](./doc/core-topics/problem-editor-en/readme.md)
5. **Deliverable Phases:** [Projects Index](./projects/readme.md) • [Phase 01 Demo (2026-11-12)](./projects/01-demo-20261112/README.md) • [Phase 02 (Active)](./projects/02/readme.md)

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
- **No leaked secrets or local paths:** Credentials, `**/problem.yml`, and local machine paths never enter tracked files.
- **Short lowercase-with-dashes naming:** Used across `doc/` and `projects/` for clarity and traceability.
