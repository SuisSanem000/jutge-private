# doc/ — map and rules

> The folder structure is **temporary**. Simin will reorganise it soon. Until then, follow this map.

## What is in here

| Path | What it is |
|---|---|
| `ai-analysis-20261103/` | Verified knowledge base about Jutge, `jtk` and problem-editor, plus the AI system prompt and the living project state. Start here. |
| `task-01-problem-editor-analysis/` | Task brief (`TASK.md`) plus empty `study/` and `for-professor/` folders. Not started. |
| `task-02-meeting-20261022-next-steps/` | Task brief plus empty `study/` and `for-professor/` folders. Not started. |

## Hard rules (always)

1. **Never touch anything in `resources/`.** It is original information from the professors and upstream repos.
2. **Only write output inside `doc/`.**
3. Facts must be checked against the code in `resources/`. Mark anything unchecked as *inference*.
4. Do not invent terminal output, line numbers or quotes.

## How to run a task ("next task is in folder X, go do it")

1. Read `doc/README.md` (this file).
2. Read `ai-analysis-20261103/00-START-HERE-system-prompt.md`.
3. Read `ai-analysis-20261103/01-project-state.md`.
4. Read `X/TASK.md`. It is self-contained.
5. Do the work. Write results only into `X/study/` (for Simin) and `X/for-professor/` (for the professor).
6. Set the status in `X/TASK.md`. Update the task registry and the log in `01-project-state.md`.

To add a new task: create `task-NN-short-name/` with `TASK.md`, `study/` and `for-professor/`, and add a row to the registry in `01-project-state.md`.
