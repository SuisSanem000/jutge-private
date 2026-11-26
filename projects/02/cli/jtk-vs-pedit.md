# How `pedit` Differs from `jtk`

## Table of Contents

- [1. Why `jtk` Already Exists (and Stays Unchanged)](#1-why-jtk-already-exists-and-stays-unchanged)
- [2. How `pedit` Is Different](#2-how-pedit-is-different)
  - [2.1 Model Selection & Conversational AI (OpenRouter SDK)](#21-model-selection--conversational-ai-openrouter-sdk)
  - [2.2 Suggested Commands & Common Edit Helpers](#22-suggested-commands--common-edit-helpers)
  - [2.3 Hidden Master Prompts & Phase-Specific Skills](#23-hidden-master-prompts--phase-specific-skills)
  - [2.4 Closed-Loop Verification via `jtk`](#24-closed-loop-verification-via-jtk)
- [3. Side-by-Side Comparison](#3-side-by-side-comparison)

---

## 1. Why `jtk` Already Exists (and Stays Unchanged)

`jtk` (`@jutge.org/toolkit` v4.4.50) is the existing CLI for building and publishing `.pbm` problems:
- **What it does well:** Compiles golden solutions and generates `.cor` files (`jtk make`), builds PDFs (`jtk make pdf`), checks structure (`jtk lint`), tests alternative solutions (`jtk verify`), and uploads/submits to `api.jutge.org` (`jtk upload`, `jtk submit`).
- **What `jtk generate` lacks:** It sends one-shot prompts through `api.jutge.org/api/instructor/jutgeai/chat` (default model `openai/gpt-6-luna`) and dumps files to disk **open-loop**—it does not compile, run tests, self-correct, or support conversational editing of an existing `.pbm` folder.
- **Decision (Nov 12 meeting):** Do **not** modify `jtk`. Keep `jtk` as the deterministic tool/MCP backend and build **`pedit`** as a separate CLI on top of it.

---

## 2. How `pedit` Is Different

### 2.1 Model Selection & Conversational AI (OpenRouter SDK)
- `pedit` uses the **OpenRouter SDK** so you can pick the LLM (e.g., DeepSeek v4 or other models) and talk to it iteratively about a problem folder.
- Later, the same model interface can route through Jutge's own API without changing the CLI commands.

### 2.2 Suggested Commands & Common Edit Helpers
- Instead of only generating a problem from scratch, `pedit` targets **day-to-day editing** with suggested commands and shortcuts for common tasks:
  - Tighten or relax constraints (`handler.yml`, `.ops`).
  - Add edge-case or efficiency test generators (`generate.ts`, `*.inp`).
  - Add/test wrong or slow solutions (`solution-*.cc`).
  - Update or translate statements (`problem.<lang>.tex`, `problem.<lang>.yml`).
  - Deterministic helpers (inspect, status, metadata updates) run directly in code without wasting an LLM call.

### 2.3 Hidden Master Prompts & Phase-Specific Skills
- In Phase 01, you had to paste a long master prompt containing `.pbm` rules, the C++17 constitution, and `jtk` instructions.
- `pedit` **hides the master prompt** from the user by loading the right **skills** (`spec/` + `skills/`) for each command or phase automatically.
- The user only writes the **problem idea or short edit request** (e.g., *"add a slow O(n^2) solution and test that it fails"*).

### 2.4 Closed-Loop Verification via `jtk`
- Whenever `pedit` edits a problem, it automatically invokes unmodified `jtk` (`jtk make`, `jtk lint`, `jtk verify`) in the background.
- If compilation, linting, or a test fails, `pedit` feeds the error back to the AI so it fixes the mistake before finishing.

---

## 3. Side-by-Side Comparison

| Dimension | `jtk` (Existing) | `pedit` (New CLI) |
|---|---|---|
| **Role** | Deterministic build, test, PDF, upload engine | AI-assisted problem editor & workflow wrapper |
| **LLM Backend** | Fixed Jutge API (`openai/gpt-6-luna`) | **OpenRouter SDK** (selectable models; Jutge API later) |
| **Interaction** | One-shot `jtk generate` | Conversational edits + suggested helper commands |
| **Prompts / Rules** | Hardcoded in CLI | **Hidden master prompts** + phase-specific skills |
| **Verification** | Manual (`jtk make` / `lint` / `verify` run separately) | **Closed-loop** (calls `jtk` automatically & self-corrects) |
