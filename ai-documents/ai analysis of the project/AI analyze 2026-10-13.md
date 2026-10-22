# Jutge.org Ecosystem: Architecture Analysis & High-Impact Roadmap

## 1. Executive Summary & Strategy: "Show More, Do Less"

As a Master’s scholarship student at UPC working on **Jutge.org**, you want high visibility with minimal frictional overhead.

### Why Avoid Core Backend/Judges Initially?

* Repositories like `jutge-dockerfiles` or execution drivers (`jutge-driver-std`, `jutge-driver-circuits`) involve low-level Linux sandbox security (cgroups, chroot, strict syscall filtering) and high blast radiuses. Breaking them breaks exam evaluations across UPC.
* Changes in backend drivers require complex sandbox setups locally and take long verification cycles.

### Where is the "Sweet Spot" (High Visibility / Low Friction)?

1. **Developer Tools & Extensions (`jutge-vscode` & `jutge-cli`)**:
* Written in modern **TypeScript**.
* Immediate feedback loop (F5 in VS Code).
* Any bugfix or UI polish directly impacts UPC students and instructors. You can quickly record a demo GIF or show working PRs in scholarship sync meetings.


2. **Authoring Automation (`jutge-toolkit`)**:
* Written in **TypeScript / Bun**.
* Integrates problem generation, LaTeX/Pandoc conversion, and JutgeAI routines.
* Instructors (professors like Salvador Roura and Jordi Cortadella) directly interact with problem-authoring tools. Providing templates, test case improvements, or documentation yields direct professor praise.


3. **API & Client SDKs (`jutge-api-clients`, `jutge-api-doc`)**:
* Generates client libraries across Python/TypeScript. Adding or typing missing endpoints is straightforward, low risk, and verifiable with unit tests.



---

## 2. Directory & Repository Map (Local Setup)

Assuming you maintain a parent workspace directory:

```text
jutge-workspace/
├── jutge-vscode/
├── jutge-cli/
├── jutge-toolkit/
├── jutge-web-new/
├── jutge-web-prof/
├── jutge-api-clients/
├── jutge-api-doc/
├── jutge-dockerfiles/
├── jutge-driver-std/
└── jutge-driver-circuits/

```

### Repository Breakdown

| Local Folder | Remote Repository Link | Stack | Role & Strategic Value |
| --- | --- | --- | --- |
| [`./jutge-vscode`](https://www.google.com/search?q=./jutge-vscode) | [jutge-org/jutge-vscode](https://www.google.com/search?q=https://github.com/jutge-org/jutge-vscode) | TypeScript, VS Code API | **Easiest / Highest Impact.** Extension allowing students to submit and view verdicts right in IDE. Open issues exist. |
| [`./jutge-cli`](https://www.google.com/search?q=./jutge-cli) | [jutge-org/jutge-cli](https://www.google.com/search?q=https://github.com/jutge-org/jutge-cli) | TypeScript, Node/Bun | Command-line client. Great for testing, CI/CD integrations, and quick features. |
| [`./jutge-toolkit`](https://www.google.com/search?q=./jutge-toolkit) | [jutge-org/jutge-toolkit](https://github.com/jutge-org/jutge-toolkit) | TypeScript, Bun, Pandoc | CLI (`jtk`) for problem authoring, testcase generation, and JutgeAI problem templates. |
| [`./jutge-web-new`](https://www.google.com/search?q=./jutge-web-new) | [jutge-org/jutge-web-new](https://www.google.com/search?q=https://github.com/jutge-org/jutge-web-new) | TypeScript, Modern Web (Vue/React) | New student portal interface. Visual improvements and localized fixes show immediately. |
| [`./jutge-web-prof`](https://www.google.com/search?q=./jutge-web-prof) | [jutge-org/jutge-web-prof](https://www.google.com/search?q=https://github.com/jutge-org/jutge-web-prof) | TypeScript | Instructor dashboard for contest/exam roster management and submissions. |
| [`./jutge-api-clients`](https://www.google.com/search?q=./jutge-api-clients) | [jutge-org/jutge-api-clients](https://www.google.com/search?q=https://github.com/jutge-org/jutge-api-clients) | PHP / Generator, Python/TS targets | Auto-generates client SDKs for the Jutge API v2. Great for strictly typed tests. |
| [`./jutge-api-doc`](https://www.google.com/search?q=./jutge-api-doc) | [jutge-org/jutge-api-doc](https://www.google.com/search?q=https://github.com/jutge-org/jutge-api-doc) | TypeScript, OpenAPI/Docs | API documentation portal. Fast PRs for schema updates or typo fixes. |
| [`./jutge-driver-std`](https://www.google.com/search?q=./jutge-driver-std) | [jutge-org/jutge-driver-std](https://www.google.com/search?q=https://github.com/jutge-org/jutge-driver-std) | Python | Execution driver running student code inside isolated test containers. |
| [`./jutge-driver-circuits`](https://www.google.com/search?q=./jutge-driver-circuits) | [jutge-org/jutge-driver-circuits](https://www.google.com/search?q=https://github.com/jutge-org/jutge-driver-circuits) | Python | Specialized driver for evaluating digital circuit problems (EDA tools). |
| [`./jutge-dockerfiles`](https://www.google.com/search?q=./jutge-dockerfiles) | [jutge-org/jutge-dockerfiles](https://www.google.com/search?q=https://github.com/jutge-org/jutge-dockerfiles) | Shell, Dockerfile | Base images and compiler sandboxes for judging environments. |

---

## 3. High-Leverage 3-Step Execution Plan

### Step 1: Clone and Environment Bootstrap

Run the setup in your workspace directory:

```bash
mkdir jutge-workspace && cd jutge-workspace

# Clone the high-leverage client & tooling repos
git clone https://github.com/jutge-org/jutge-vscode.git
git clone https://github.com/jutge-org/jutge-toolkit.git
git clone https://github.com/jutge-org/jutge-cli.git
git clone https://github.com/jutge-org/jutge-api-clients.git

# Clone drivers and web repos as references
git clone https://github.com/jutge-org/jutge-web-new.git
git clone https://github.com/jutge-org/jutge-driver-std.git

```

### Step 2: Grab "Low-Hanging Fruit" in [`./jutge-vscode`](https://www.google.com/search?q=./jutge-vscode)

1. Open [`./jutge-vscode`](https://www.google.com/search?q=./jutge-vscode) in VS Code.
2. Run `npm install` and press `F5` to open the Extension Development Host.
3. Review the open GitHub issues (e.g., error reporting handling, token expiration refresh, status bar UI notifications).
4. Submitting a single PR fixing an edge case in the VS Code client immediately proves competent delivery to project leads.

### Step 3: Enhance [`./jutge-toolkit`](https://www.google.com/search?q=./jutge-toolkit)

1. Explore `jtk` problem generation templates (`jtk clone`, `jtk generate`).
2. Add support for improved error diagnostics during `jtk make` or optimize Markdown/LaTeX translation handling.

---

## 4. Master Prompt for Your AI Agent

> [!NOTE]
> The operational system prompt and senior engineer directives for your AI assistant have been decoupled and moved to:
> **[`ai assistant files/AI-ASSISTANT-SYSTEM-PROMPT.md`](file:///Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/ai-documents/ai%20analyze/ai%20assistant%20files/AI-ASSISTANT-SYSTEM-PROMPT.md)**.
> Refer to that file or copy its instructions directly into your AI coding assistant (Anti-Gravity, Cursor, Claude Code, Windsurf, Aider).