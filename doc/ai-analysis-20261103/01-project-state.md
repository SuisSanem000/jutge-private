# 01 — Project state (living file)

**Last updated:** 2026-11-03

## Mandate

Simin owns the **restructure / from-scratch rebuild of `jtk`** (package `@jutge.org/toolkit`) during a 4-month internship, and contributes ideas for it. Related work: AI-assisted problem creation ("problem-editor") and follow-ups from the 2026-10-22 meeting.

## Task registry

| Folder | Task | Status |
|---|---|---|
| `doc/task-01-problem-editor-analysis/` | Analyse everything in the problem-editor folder. Produce study notes for Simin and a report for the professor. | NOT STARTED |
| `doc/task-02-meeting-20261022-next-steps/` | Review everything and list what Simin should do next and in the near future, from the 2026-10-22 meeting notes. Study notes plus a professor-facing version. | NOT STARTED |

## Timeline

| Date | Event |
|---|---|
| 2026-01-08 | First commit of the new jutge-toolkit (jtk). Legacy Python toolkit marked legacy on 2026-02-03. |
| 2026-10-22 | Meeting with the professors. Notes in `resources/original-info-from-professors/meeting notes 20261022.md`. Pau Fernández pushed the first problem-editor material the same day. |
| 2026-10-25 | Folder "professor gave 2026-10-25" holds problem-editor. |
| 2026-10-27 | Jordi Petit added `private-problems/` to problem-editor. |
| 2026-11-02 | Simin added a `.gitignore` in problem-editor. |
| 2026-11-03 | This knowledge base written. Old `doc/ai-documents/` verified, merged and removed. |

## People (evidence from git history and files)

| Person | Role, with evidence |
|---|---|
| Jordi Petit | Lead. About 1,600 commits across the repos; 354 of 384 jtk commits; author in `package.json`. |
| Pau Fernández | Maintainer (jtk 29 commits, jutge-cli, vscode, dockerfiles, api-doc). Wrote the problem-editor README and first commits. |
| Salvador Roura | Credited as "Lead" in `jutge-web-new/lib/about.ts`; author of legacy example problems. No commits. |
| Jordi Cortadella | In the publication list of `jutge-web-new/lib/about.ts`; circuits example in jtk. No commits. |
| Jordi Reig, Cristina Raluca | Listed contributors in jtk `package.json`. |

*Inference:* "Paul" and "Lori" in the meeting notes most likely mean Pau Fernández and Jordi (or Lori, a person Simin should confirm). Ask Simin.

## Simin's instructions from the 2026-11-03 prompt (summary)

- Study the whole project, including the old AI documents, and keep only what is true.
- Put the verified understanding in `doc/ai-analysis-20261103/`; remove `doc/ai-documents/`.
- Prepare one folder per next task, with study notes for Simin and a professor-facing version of each.
- Keep this state file so a future prompt can be "I put the next task in folder X, go do it".
- This session only prepares context and prompts. It does **not** do the task work.
- **Never touch `resources/`. Output only in `doc/`.**
- The folder structure will be reorganised soon.

## Open questions for the professors (collected so far)

1. Should `jtk` be rewritten in place or as a new repo? Who reviews the work (Pau, Jordi)?
2. What is the first milestone: MVP then extend, or the reverse? (Meeting notes list both.)
3. Interface for the AI agent: CLI wrapped by an agent, MCP, or web service only? (Pau suggested a web service.)
4. LLM budget and tokens (the meeting notes mention it).
5. Which problem types are in scope: C++ only, or also Python, quiz, graphic, Haskell, Clojure?
6. Meeting notes list items the professors should provide. Which have arrived? (problem-editor arrived. Documentation, Pau's skills and sample problems appear to be in it. Confirm.)

## Log

- 2026-11-03: Created the knowledge base and the two task folders. Removed `doc/ai-documents/`.
