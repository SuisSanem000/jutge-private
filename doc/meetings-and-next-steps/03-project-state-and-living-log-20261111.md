# Project State & Living Log (2026-11-11)

> **Mandate:** Simin Shoeibi owns the restructure and rebuild of `jtk` (`@jutge.org/toolkit`) from scratch during a 4-month internship at UPC, and enables the AI-assisted Problem Editor.

---

## 1. People & Roles

| Person | Role & Context |
|---|---|
| Jordi Petit | UPC Professor, Jutge.org Lead & Creator. Author of most of `jtk` and Jutge services. |
| Pau Fernandez | UPC Collaborator / Maintainer. Authored `problem-editor` specs, skills, and sample exam. |
| Simin Shoeibi | Senior Software Engineer / UPC Intern. Responsible for `jtk` architecture & rebuild. |

---

## 2. Directory Model & Responsibilities

| Directory | Owner | Policy |
|---|---|---|
| `resources/` | Simin | **NEVER TOUCHED BY AI.** Upstream git clones and professor resources. Updates pulled via `git pull`. |
| `doc/` | AI & Simin | Documentation, technical deep-dives, AI settings, study guides, and meeting plans. |
| `work/` | Simin & AI | Tasks, code implementation, proofs-of-concept, and presentations for professors. |

---

## 3. Work Registry

| Subfolder | Task / Deliverable | Status |
|---|---|---|
| [**01. Task: Problem Editor Analysis**](../../work/01-task-problem-editor-analysis-20261103/) | In-depth audit of Pau's problem-editor (specs, models, skills). | Prepared |
| [**02. Task: Meeting Follow-ups**](../../work/02-task-meeting-followups-20261103/) | Action items tracking the 2026-10-22 meeting notes. | Prepared |
| [**03. Meeting Presentation (Nov 12)**](../../work/03-meeting-presentation-20261112/) | Presentation agenda & proposals for the 2026-11-12 meeting. | **ACTIVE (Meeting Tomorrow)** |

---

## 4. Timeline Log

*   **2026-10-22:** Kickoff meeting between Simin, Jordi Petit, and Pau Fernandez.
*   **2026-10-25:** Pau provided `problem-editor` materials (spec, models, Claude skills).
*   **2026-10-27:** Jordi Petit added `private-problems/` (EDA, AP1, AP2 problems).
*   **2026-11-03:** Initial ecosystem analysis and task scaffolds created.
*   **2026-11-07:** Senior developer brief, 4-hour study plan, and meeting proposals formulated.
*   **2026-11-11:** Clean decoupling completed: AI settings isolated in `doc/ai-analysis/`, understanding in `doc/understanding/`, meetings in `doc/meetings-and-next-steps/`, and tasks in `work/`. Prepared for 2026-11-12 meeting.

