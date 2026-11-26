# Sync to `pedit-demo` & `jutge-org/problem-editor`

## Table of Contents

- [Reusable Prompt](#reusable-prompt)
- [Execution Checklist](#execution-checklist)

---

## Reusable Prompt

```text
Take the code from local `projects/02/problem-editor/` and sync both:
1. `https://github.com/SuisSanem000/pedit-demo` (public GitHub Pages mirror: only `pedit/`, `viewer/`, safe `demo-problems/`, and `.github/workflows/pages.yml` — never private professor/exam materials).
2. `https://github.com/jutge-org/problem-editor` (`main` branch, date-tagged commit `YYYY-MM-DD`, updating `README.md` and `.github/workflows/pages.yml`).
```

---

## Execution Checklist

1. Read from local `projects/<NN>/problem-editor/` (gitignored source of truth in `jutge-private`).
2. **Public mirror (`SuisSanem000/pedit-demo`):** Sync only `pedit/`, `viewer/`, safe `demo-problems/`, and `.github/workflows/pages.yml` (excluding `node_modules/`, `.env*`, `**/problem.yml`, `private-problems/`, `spec/`, `skills/`, `generated-exam-sample/`), commit with `YYYY-MM-DD: ...`, and push `main`.
3. **Upstream (`jutge-org/problem-editor`):** Sync `pedit/`, `viewer/`, `generated-demo/`, `.github/workflows/pages.yml`, and `README.md` (excluding `node_modules/`, `.env*`, `**/problem.yml`), commit with `YYYY-MM-DD: ...`, tag `vYYYY-MM-DD`, and push `main --tags`.
4. Verify no secrets or local paths leaked, log to `doc/ai-log/YYYY-MM-DD/NN.md`, and push `jutge-private`.
