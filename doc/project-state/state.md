# Project State & Living Log

> **Current Mandate (post-2026-11-12 pivot):** Keep `jtk` unchanged (`jtk` serves as the deterministic tool/MCP layer) and build a separate CLI/agent tool named **`pedit`** (problem editor) using the OpenRouter SDK (starting with DeepSeek v4, routing through Jutge's API later) plus a simple web interface to display problems kept in a folder.

## Table of Contents

- [1. People & Roles](#1-people--roles)
- [2. Directory Model](#2-directory-model)
- [3. Phase Registry (`projects/`)](#3-phase-registry-projects)
- [4. Meeting Decisions & Next Focus](#4-meeting-decisions--next-focus)
- [5. Timeline Log](#5-timeline-log)

---

## 1. People & Roles

| Person | Role |
|---|---|
| Jordi Petit | UPC Professor, Jutge.org creator & lead |
| Pau Fernandez | UPC collaborator & maintainer of `problem-editor` |
| Simin Shoeibi | UPC master's intern leading `pedit` architecture & delivery |

---

## 2. Directory Model

| Folder | Owner | Purpose |
|---|---|---|
| `resources/` | Simin | Read-only upstream clones (`resources/problem-editor/`, `resources/private-local/jutge_repos/`) and professor notes. Never modified by AI. |
| `doc/` | AI & Simin | AI assistant entry/rules, daily AI logs, project state, core topic translations/guides, and architecture references. |
| `projects/` | Simin & AI | Time-boxed 10–15 day deliverable phases for supervisor check-ins. |

---

## 3. Phase Registry (`projects/`)

| Phase | Deliverable | Dates | Status |
|---|---|---|---|
| [01-demo-20261112](../../projects/01-demo-20261112/README.md) | `.pbm` demo (`dominant-peaks.pbm`), Claude task, explanations, and Nov 12 presentation | 2026-11-11 – 2026-11-12 | Completed |
| [02](../../projects/02/readme.md) | `pedit` CLI & PDF Problem Viewer | 2026-11-26 – TBD | Planning (awaiting confirmation) |

---

## 4. Meeting Decisions & Next Focus

- **2026-10-22 (Kickoff):** Support I/O and function (`no_main`) problems across C++, Python, Haskell, and Clojure; keep `.pbm` + `jtk` as ground truth; use AI + skills so teachers can author problems easily.
- **2026-11-12 (Pivot to `pedit`):**
  1. Keep `jtk` unmodified as the tool/MCP backend; build `pedit` around it to create and edit problems in a local folder.
  2. Catalog all problem-editing operations and design dedicated helper commands for common edits.
  3. Integrate the **OpenRouter SDK** (e.g., DeepSeek v4) with a clean path to route calls through Jutge's API later.
  4. Move long boilerplate from master prompts into skills so prompts focus strictly on the problem idea.
  5. Study DeepSeek agent/harness patterns (Jordi) and OpenCode with OpenRouter (Pau), and build a simple web PDF/problem viewer (no heavy architecture).

---

## 5. Timeline Log

- **2026-10-22:** Kickoff meeting with Jordi Petit and Pau Fernandez; goals and `.pbm` problem format defined.
- **2026-10-25:** Pau shared `problem-editor` specs, pedagogical constitution, 7 reference models, and Claude skills.
- **2026-10-27:** Jordi added private exam problems (`private-problems/`) to `problem-editor`.
- **2026-11-12:** Phase 1 demo (`dominant-peaks.pbm`) presented; direction pivoted from rewriting `jtk` to building `pedit` on top of unmodified `jtk`, OpenRouter SDK, and a minimal problem-viewer web UI.
- **2026-11-26:** Workspace reorganized (`doc/ai-assistant/`, `doc/ai-log/`, `doc/project-state/`, `projects/02/`); duplicate docs consolidated and `start-here.md` created.
