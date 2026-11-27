# Phase 02 — Unified `pedit` CLI & PDF Problem Viewer

## Table of Contents

- [What This Achieves](#what-this-achieves)
- [Live Demo & Repositories](#live-demo--repositories)
- [1. CLI Commands, Usage & Differences from `jtk`](#1-cli-commands-usage--differences-from-jtk)
- [2. Problem PDF Viewer](#2-problem-pdf-viewer)
- [Technical Details](#technical-details)
- [Related Docs](#related-docs)

## What This Achieves

- **One unified tool (`pedit/`):** Combines the AI problem-editor CLI and the Problem PDF Viewer in `projects/02/problem-editor/pedit/` on top of unmodified `jtk` (`4.4.50`).
- **One root GitHub Pages link:** Shows `pedit` CLI download + usage at the top and the interactive Problem PDF Viewer (with browser-only **Open `.pbm` from PC**) below.
- **Low-cost OpenRouter AI:** Uses `@openrouter/sdk` (default `openai/gpt-4o-mini`), hidden `spec/` & `skills/` prompts, and closed-loop `jtk` verification (never writes `*.cor`).
- **Safe public mirror:** Shares only self-authored `pedit/` and synthetic `sum-evens.pbm` publicly without private exam problems.

## Live Demo & Repositories

| Target | Contents | Link / Status |
|---|---|---|
| **Public Pages Demo** (`SuisSanem000/pedit-demo`) | Unified `pedit/` + `demo-problems/sum-evens.pbm` | [Live Page](https://suissanem000.github.io/pedit-demo/) • [Repo](https://github.com/SuisSanem000/pedit-demo) |
| **Local Source** (`projects/02/problem-editor/pedit/`) | CLI + Viewer + Tests | Gitignored source of truth |
| **Private Upstream** (`jutge-org/problem-editor`) | Paused at `6779486` (2026-11-11) | Will be synced after demo sign-off |

## 1. CLI Commands, Usage & Differences from `jtk`

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

## 2. Problem PDF Viewer

- **Local live server (`pedit viewer --dir ..`):** Auto-builds PDFs (`jtk make pdf` + headless Chrome fallback) and provides **Rebuild PDF**, **`jtk make`**, **`jtk lint`**, and **Logs**.
- **Static GitHub Pages (`bun run export ./dist-pages`):** Serves `sum-evens.pbm` plus browser-only **Open `.pbm` from PC** / drag-and-drop (keeps previously opened problems in the sidebar list, supports `en/` language subfolders, nothing uploaded).

## Technical Details

- **Modules (`pedit/src/`):** `index.ts` (CLI router + `show` read guard), `jtk.ts` (`jtk` + `generate.ts` runner), `pbm.ts` (scanner & write guard), `pdf.ts` (`jtk make pdf` + headless Chrome fallback), `ai.ts` (`@openrouter/sdk` + 2-retry loop), `viewer-server.ts`, `export-static.ts`, and `public/index.html`.
- **Verification:** `bun test` (2/2 pass), `list`/`status`/`show`/`lint`/`pdf` on `generated-demo/sum-evens.pbm`, live `pedit viewer` (`HTTP 200`), and `export-static.ts` all verified.
- **Professor checklist:** Copy-pasteable verification steps are in `pedit/README.md` (and root `README.md` of `pedit-demo`).

## Related Docs

- [How `pedit` Differs from `jtk`](./jtk-vs-pedit.md)
- [Phase 02 Issues Log](./issues.md)
- [Supervisor Email Draft](./supervisor-email.md)
