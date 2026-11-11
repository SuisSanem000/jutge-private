# 08 — Verification log of the old `doc/ai-documents/`

The old folder (9 files, 877 lines, written by an earlier AI assistant) was checked against the code. It was then removed from the working tree. It stays in git history (see the commit that removes it).

## Claims that held (kept)

| Claim | Evidence |
|---|---|
| `IOProblemGenerator` calls `bot.forgetLastInteraction()` to prune context | `lib/create-io.ts:153` and 7 more places |
| `selectCompiler()` uses the golden solution's extension | `lib/maker.ts:278`. Narrower than stated: only `make exe` is affected |
| Default model `openai/gpt-6-luna` | `lib/types.ts:201` |
| `\Sample` lint rule | Real, but in `lib/lint.ts:431-457` |
| `*.cor` never hand or LLM written | Matches problem-editor spec and jtk design |
| `generate problem` flags `-k -i -n -d` and the spec keys | `toolkit/generate.ts` (io kind) |
| `upload` writes `problem.yml` | `saveProblemYml` |
| `clean`, `doctor`, `config show`, `for-dummies` exist | `toolkit/*.ts` |
| Generation is open loop | No compile or run step in `create-io.ts` |
| People and roles | Confirmed from git authors and files (see `01-project-state.md`), except Roura and Cortadella have no commits |
| Do not touch drivers/dockerfiles | Kept as a rule (production grading) |
| Ecosystem layers | Kept in `02-ecosystem.md` |

## Corrected

| Old claim | Correction |
|---|---|
| Credentials at `~/.config/jutge/credentials.json`; order Token → File → Env → Prompt | Path comes from `envPaths('jutge',{suffix:'cli'})` (jutge-cli's file). Order differs per field. `JUTGE_TOKEN` also exists |
| `jtk submit -l cc` | `-l` is human language; `-c` is compiler |
| `jtk clone demo -d x.pbm` | `demo/demo.pbm` |
| `lib/compilers.ts` | Top-level `compilers/` dir; `toolkit/compilers.ts` is the developer command |
| `\Sample` rule in `toolkit/lint.ts` | `lib/lint.ts`; fires for any `.inp` name containing `sample` |
| Generated file list | Missing the `.yml` files, translations, `generate-efficiency.py`, `.gitignore`; funcs kind writes a different set |
| `.pbm` anatomy had `problem.en.yml` + `README.md` etc. as fixed | Real set is in file 04 |
| "Anyone can use `jtk make exe`" implied safe | Quirk above |
| `lib/` listed as containing `compilers.ts` | See above |
| "No need to build the repos" (Q1 in guide 03) | Only true if `jtk` is installed globally; jtk-dev runs from source |

## Dropped

| Dropped item | Reason |
|---|---|
| "Expected Outcome" terminal blocks in 03 and 03-2 (boxes, `Verdict: Accepted`, problem ids `P84920_en`, `P84921_en`, CPU time and memory) | Not verifiable. Likely invented. |
| Personal login details | Not needed |
| Meeting talking points, elevator pitches, "insider findings to impress Prof. Petit" | Not knowledge; replaced by facts in files 03 and 06 |
| "Show more, do less" strategy | Conflicts with the real mandate (rebuild jtk) |
| STATE-2026-10-22 agenda and backlog | Stale. Replaced by `01-project-state.md` |
| The system prompt's PR-ready/Conventional Commits directives | Not Simin's stated rules; replaced by `00-START-HERE-system-prompt.md` |
| Lily Primes walkthrough | Specific demo, no lasting value; commands are in file 07 |

## Still unverified

- Whether `jtk submit` for `.java` really sends `Java` instead of `JDK` (not tested against the API).
- Exact Jutge API behaviour behind `jtk upload`'s output matching (`Problem X12345 created.`).
- Whether jtk is installed on Simin's machine; nothing was run in this session.
