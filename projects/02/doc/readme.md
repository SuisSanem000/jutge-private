# Phase 02 — Unified `pedit` CLI & PDF Problem Viewer

## Table of Contents

- [What This Achieves](#what-this-achieves)
- [Live Demo & Repositories](#live-demo--repositories)
- [CLI & Viewer Commands](#cli--viewer-commands)
- [Technical Details](#technical-details)
- [Related Docs](#related-docs)

## What This Achieves

- **One unified tool (`pedit/`):** Combines the AI problem-editor CLI and the Problem PDF Viewer in `projects/02/problem-editor/pedit/` on top of unmodified `jtk` (`4.4.50`).
- **One root GitHub Pages link:** Shows `pedit` CLI download + usage at the top and the interactive Problem PDF Viewer (with **Open `.pbm` from PC**) below.
- **Low-cost OpenRouter AI:** Uses `@openrouter/sdk` (default `openai/gpt-4o-mini`), hidden `spec/` & `skills/` prompts, and closed-loop `jtk` verification (never writes `*.cor`).
- **Safe public mirror:** Shares only self-authored `pedit/` and synthetic `sum-evens.pbm` publicly without private exam problems.

## Live Demo & Repositories

| Target | Contents | Link / Status |
|---|---|---|
| **Public Pages Demo** (`SuisSanem000/pedit-demo`) | Unified `pedit/` + `sum-evens.pbm` | [Live Page](https://suissanem000.github.io/pedit-demo/) • [Repo](https://github.com/SuisSanem000/pedit-demo) |
| **Local Source** (`projects/02/problem-editor/pedit/`) | CLI + Viewer + Tests | Gitignored source of truth |
| **Private Upstream** (`jutge-org/problem-editor`) | Identical `pedit/` + `generated-demo/` (`62ff90b`, `v2026-11-26`) | Ready for professors to run locally |

## CLI & Viewer Commands

| Action | Command |
|---|---|
| **Install** | `cd pedit && bun install` |
| **Inspect / Build (`jtk`)** | `bun run src/index.ts list --dir ..` • `status <pbm>` • `build` / `pdf` / `lint` / `verify <pbm>` |
| **AI Create / Edit** | `bun run src/index.ts create <dir.pbm> "<idea>"` • `edit <pbm> ["<req>"] [--preset add-edge-tests]` • `chat <pbm>` |
| **Start PDF Viewer** | `bun run src/index.ts viewer --dir .. --port 3456` |
| **Export Static Pages** | `bun run export ./dist-pages` |

## Technical Details

- **Modules (`pedit/src/`):** `index.ts` (CLI router), `jtk.ts` (`jtk` + `generate.ts` runner), `pbm.ts` (scanner & write guard), `pdf.ts` (`jtk make pdf` + headless Chrome fallback), `ai.ts` (`@openrouter/sdk` + 2-retry loop), `viewer-server.ts`, `export-static.ts`, and `public/index.html`.
- **Verification:** `bun test` (2/2 pass), compiled standalone binary (`bun run compile` → `./pedit --help`, `list`, `viewer`), live OpenRouter `create` + `edit` on `sum-evens.pbm`, live `pedit viewer` (`HTTP 200`, `%PDF-1.4`), and `export-static.ts` all verified.
- **For professors:** Step-by-step verification commands are in `pedit/README.md` (`bun test`, `bun run compile`, `pedit build`/`lint`, `pedit create`/`edit`, `pedit viewer`).

## Related Docs

- [How `pedit` Differs from `jtk`](./jtk-vs-pedit.md)
- [Phase 02 Issues Log](./issues.md)
- [Supervisor Email Draft](./supervisor-email.md)
