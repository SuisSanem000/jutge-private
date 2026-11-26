# Sync to `jutge-org/problem-editor`

## Table of Contents

- [Reusable Prompt](#reusable-prompt)
- [Execution Checklist](#execution-checklist)

---

## Reusable Prompt

```text
Take all code in the latest project's `problem-editor/` folder (for example `projects/02/problem-editor/`), sync and push everything to https://github.com/jutge-org/problem-editor on `main`, tag the commit with today's date (`YYYY-MM-DD`) so it is clear in the commit history, and update GitHub Actions / GitHub Pages and README links properly on that repository as well.
```

---

## Execution Checklist

1. Locate the latest phase folder under `projects/` containing `problem-editor/` (e.g. `projects/02/problem-editor/`).
2. Clone or update `https://github.com/jutge-org/problem-editor` in a temporary directory outside tracked repo files (never commit nested `.git` into `jutge-private`).
3. Copy updated code, `pedit/`, `viewer/`, `.github/workflows/pages.yml`, and updated `README.md` routes into that `problem-editor` clone (excluding secrets, `.env*`, and `**/problem.yml` if private).
4. Commit with a date-prefixed message (e.g. `2026-11-26: sync pedit cli and pdf viewer from phase 02`), create a date tag if appropriate (`git tag -a vYYYY-MM-DD -m "..."`), and push to `origin main` (and tags).
5. Verify GitHub Pages workflow and README links on `jutge-org/problem-editor`, log to `doc/ai-log/YYYY-MM-DD/NN.md`, and push `jutge-private`.
