# Phase 02 — `pedit` CLI & Problem PDF Viewer

## Table of Contents

- [What This Is (What This Achieves)](#what-this-is-what-this-achieves)
- [Connections to Our Nov 12 Meeting](#connections-to-our-nov-12-meeting)
- [How I Built It](#how-i-built-it)
- [1. `pedit` CLI Commands, Usage & Differences from `jtk`](#1-pedit-cli-commands-usage--differences-from-jtk)
- [2. Problem PDF Viewer & Live Demo](#2-problem-pdf-viewer--live-demo)
- [Technical Details](#technical-details)
- [Related Docs](#related-docs)

## What This Is (What This Achieves)

- **One unified tool (`pedit/`):** An AI-assisted Jutge problem-editor CLI and Problem PDF Viewer built on top of unmodified `jtk` (`4.4.50`).
- **Live public demo:** [pedit CLI & PDF Problem Viewer](https://suissanem000.github.io/pedit-demo/) — CLI download and commands at the top, interactive Problem PDF Viewer (with browser-only **Open `.pbm` from PC**) below.
- **Safe & verified:** Uses OpenRouter (`openai/gpt-4o-mini` by default), enforces write guards (never writes `*.cor` or `problem.yml`), and runs `jtk make` + `jtk lint` in a closed loop.

## Connections to Our Nov 12 Meeting

| What We Discussed (Nov 12) | What I Built in `pedit` |
|---|---|
| Keep `jtk` unmodified as the deterministic backend | `pedit` wraps `jtk` (`build`, `pdf`, `lint`, `verify`, `clean`) via `src/jtk.ts` without touching `jtk` |
| Catalog problem-editing operations & helper commands | Added dedicated commands (`list`, `status`, `show`, `meta`, `handler`, `presets`) for common deterministic edits |
| Integrate OpenRouter SDK (cheap models, easy to route via Jutge later) | Built `src/ai.ts` with `@openrouter/sdk` (`openai/gpt-4o-mini`, `gemini-2.5-flash-lite`, `deepseek-chat-v3-0324`) |
| Move long boilerplate out of prompts into skills | `loadSkillsPrompt()` loads `spec/constitucio.md`, `spec/problema-jutge.md`, and `skills/problemes-jutge/SKILL.md` automatically |
| Build a simple web PDF/problem viewer (no heavy architecture) | Single-page HTML viewer (`public/index.html`) served locally by `pedit viewer` or exported to static GitHub Pages |

## How I Built It

- **Step 1 — Wrapped `jtk` safely:** Built `src/jtk.ts` and `src/pbm.ts` to inspect `.pbm` folders, run `generate.ts` + `jtk`, and block unsafe writes (`*.cor`, `problem.yml`, `../`).
- **Step 2 — Added OpenRouter closed-loop editing:** Built `src/ai.ts` so `create`, `edit`, and `chat` load Jutge specs/skills, generate JSON file edits, apply safe writes, and auto-retry if `jtk make` or `jtk lint` fails.
- **Step 3 — Built PDF generation + web viewer:** Built `src/pdf.ts` (`jtk make pdf` + headless Chrome HTML-to-PDF fallback), `src/viewer-server.ts` (`pedit viewer`), and `src/export-static.ts` (static GitHub Pages bundle with client-side **Open `.pbm` from PC**).

## 1. `pedit` CLI Commands, Usage & Differences from `jtk`

### All CLI Commands

| Category | Command | Purpose |
|---|---|---|
| **Inspect** | `pedit list [--dir <path>] [--include-private] [--json]` | Discover `.pbm` folders |
| **Inspect** | `pedit status <problem.pbm> [--json]` | Summarize languages, PDFs, solutions, tests |
| **Inspect** | `pedit show <problem.pbm> [file] [--json]` | Print summary or file (blocks `problem.yml` / `../`) |
| **Deterministic `jtk`** | `pedit build\|pdf\|lint\|verify\|clean <problem.pbm> [--json]` | Run `generate.ts` + unmodified `jtk` |
| **Deterministic edits** | `pedit meta <problem.pbm> --lang en [--title "..."] [--author "..."]` | Update `problem.<lang>.yml` without AI |
| **Deterministic edits** | `pedit handler <problem.pbm> [--handler std] [--compilers G++17]` | Update `handler.yml` without AI |
| **AI authoring** | `pedit models [--json]` • `pedit presets [--json]` | List cheap OpenRouter models & edit presets |
| **AI authoring** | `pedit create <dir.pbm> "<idea>" [--model <id>] [--json]` | Create + build + lint new `.pbm` |
| **AI authoring** | `pedit edit <dir.pbm> ["<req>"] [--preset <name>] [--json]` | Edit + rebuild + lint existing `.pbm` |
| **AI authoring** | `pedit chat <dir.pbm> [--model <id>]` | Interactive multi-turn editing loop |
| **Web Viewer** | `pedit viewer [--dir <path>] [--port 3456]` | Start local PDF Problem Viewer server |

### Usage & Use Cases

- **Install:** `cd pedit && bun install` (and optionally `bun link` for global `pedit`).
- **Create from idea:** `bun run src/index.ts create ./sum-evens.pbm "Sum of even numbers"`
- **Edit with preset:** `bun run src/index.ts edit ./sum-evens.pbm --preset add-edge-tests`
- **Local PDF viewer:** `bun run src/index.ts viewer --dir .. --port 3456`

### Differences from `jtk`

| Dimension | `jtk` (Unchanged) | `pedit` (Unified Tool) |
|---|---|---|
| **Role** | Deterministic build, test, PDF, lint, upload | AI authoring, editing & PDF viewer |
| **Model** | Fixed Jutge API (`openai/gpt-6-luna`) | OpenRouter SDK (default `openai/gpt-4o-mini`) |
| **Prompts** | Hardcoded | Hidden `spec/` & `skills/` |
| **Loop** | One-shot | Closed-loop `jtk` retries (blocks `*.cor`/`problem.yml` writes) |

## 2. Problem PDF Viewer & Live Demo

| Target | Contents | Link / Status |
|---|---|---|
| **Public Pages Demo** (`SuisSanem000/pedit-demo`) | Unified `pedit/` + `demo-problems/sum-evens.pbm` | [Live Page](https://suissanem000.github.io/pedit-demo/) • [Repo](https://github.com/SuisSanem000/pedit-demo) |
| **Local Source** (`projects/02-pedit-cli-and-viewer/problem-editor/pedit/`) | CLI + Viewer + Tests | Gitignored source of truth |
| **Private Upstream** (`jutge-org/problem-editor`) | Paused at `6779486` (2026-11-11) | Will be synced after demo sign-off |

- **Local live server (`pedit viewer --dir ..`):** Auto-builds PDFs (`jtk make pdf` + Chrome fallback) and provides **Rebuild PDF**, **`jtk make`**, **`jtk lint`**, and **Logs**.
- **Static GitHub Pages:** Serves `sum-evens.pbm` plus browser-only **Open `.pbm` from PC** / drag-and-drop (keeps previously opened problems in the sidebar list, supports `en/` language subfolders, nothing uploaded).

## Technical Details

- **Modules (`pedit/src/`):** `index.ts` (CLI router + `show` read guard), `jtk.ts` (`jtk` + `generate.ts` runner), `pbm.ts` (scanner & write guard), `pdf.ts` (`jtk make pdf` + Chrome fallback), `ai.ts` (`@openrouter/sdk` + 2-retry loop), `viewer-server.ts`, `export-static.ts`, and `public/index.html`.
- **Verification:** `bun test` (2/2 pass), `list`/`status`/`show`/`lint`/`pdf` on `generated-demo/sum-evens.pbm`, live `pedit viewer` (`HTTP 200`), and `export-static.ts` all verified.
- **Professor checklist:** Copy-pasteable verification steps are in `pedit/README.md` (and root `README.md` of `pedit-demo`).

## Related Docs

- [How `pedit` Differs from `jtk`](./jtk-vs-pedit.md)
- [Phase 02 Issues Log](./issues.md)
- [Supervisor Email Draft](./supervisor-email.md)
