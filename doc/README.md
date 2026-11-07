# Documentation & Engineering Workspace Map

> **Start Here:** For a high-signal 15-minute onboarding guide written for senior engineers, read [`SENIOR-DEV-BRIEF.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/SENIOR-DEV-BRIEF.md).

## Workspace Structure (No Duplication Policy)

To avoid duplicating large external repositories while maintaining clean version control:

| Directory | Role | Description |
|---|---|---|
| `resources/` | **Upstream / External** | Cloned Jutge repos (`jutge-toolkit`, drivers, etc.) and original materials from professors. Keep read-only; update via `git pull`. |
| `doc/` | **Knowledge & Deliverables** | Architectural documentation, analysis, meeting agendas, and formal reports for supervisors. |
| `work/` | **Active Implementation** | Your working code, POCs, experiments, and staging branches for upstream PRs. |

## What is in `doc/`

| Path | What it is |
|---|---|
| [`SENIOR-DEV-BRIEF.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/doc/SENIOR-DEV-BRIEF.md) | **Executive summary:** Domain context, architecture diagram, 4-hour study plan, and meeting proposals. |
| `ai-analysis-20261103/` | Verified knowledge base about Jutge, `jtk`, and problem-editor (technical deep-dive). |
| `task-01-problem-editor-analysis/` | Detailed audit of Pau's problem-editor material (spec inconsistencies, models, skills). |
| `task-02-meeting-20261022-next-steps/` | Action items, open questions, and preparation for supervisor meetings. |

## Engineering Rules

1. **Keep `resources/` clean:** Treat files in `resources/` as upstream mirrors. Do not make untracked manual edits inside it; pull updates when professors push changes.
2. **Develop in `work/` or branches:** Code contributions, prototypes, and PR candidates live under `work/` or on dedicated git feature branches.
3. **Verify claims against code:** Ground every finding on concrete repository evidence.


## How to run a task ("next task is in folder X, go do it")

1. Read `doc/README.md` (this file).
2. Read `ai-analysis-20261103/00-START-HERE-system-prompt.md`.
3. Read `ai-analysis-20261103/01-project-state.md`.
4. Read `X/TASK.md`. It is self-contained.
5. Do the work. Write results only into `X/study/` (for Simin) and `X/for-professor/` (for the professor).
6. Set the status in `X/TASK.md`. Update the task registry and the log in `01-project-state.md`.

To add a new task: create `task-NN-short-name/` with `TASK.md`, `study/` and `for-professor/`, and add a row to the registry in `01-project-state.md`.
