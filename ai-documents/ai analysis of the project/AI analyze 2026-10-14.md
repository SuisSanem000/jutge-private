# Jutge.org: Project Overview & Architecture Briefing

## Executive Summary

**Jutge.org** is an open educational automated judge platform developed at the Universitat Politècnica de Catalunya (UPC). It provides hands-on programming practice, automated code evaluation (grading/verdicts), course and exam administration, and competitive programming infrastructure.

The platform is undergoing a major modernization cycle—moving toward a decoupled modern architecture centered on API v2, dedicated instructor interfaces, rewrite of client web apps (`new.jutge.org`), developer tooling (CLI, VS Code extensions), and AI integration (`JutgeAI`).

---

## Ecosystem Architecture & Repositories

### 1. Frontends & Client Interfaces

* **`jutge-web-new` (`new.jutge.org`)**: Modern rewrite of the learner-facing web interface built with **TypeScript**. Focuses on responsive UI, modern dashboards, problem viewing, live submissions, and course tracking.
* **`jutge-web-prof`**: Dedicated frontend tailored for professors and teaching assistants for problem authoring, grading rosters, exam configuration, and student monitoring.
* **`jutge-vscode`**: Official Visual Studio Code extension enabling students to browse problem statements, write code, run local tests, and submit solutions directly from their IDE.

### 2. Core API & Integration Layer

* **`jutge-api-doc` & API v2 (`api.jutge.org`)**: REST/JSON API contract powering the entire ecosystem.
* **`jutge-api-clients`**: Multi-language SDK generator producing typed client libraries (TypeScript, Python, PHP, C++) to interact with the backend programmatically.
* **`jutge-cli`**: Command-line tool written in TypeScript (run via Bun/Node) for terminal-based interaction with the API.

### 3. Problem Authoring & Verification Tools

* **`jutge-toolkit` (`jtk`)**: CLI utility (built on Bun/TypeScript) used by professors and problem authors to scaffold (`jtk clone`), auto-generate via AI (`jtk generate`), build statements (Markdown, PDF via LaTeX, HTML), locally verify solutions against test cases, and deploy (`jtk upload`).
* **`JutgeAI`**: Integrated LLM functionality to draft problem statements, generate edge-case test generators, suggest alternative solutions, and handle multi-language translations.

### 4. Execution Drivers & Sandbox Environment

* **`jutge-dockerfiles`**: Standardized container images containing compiler toolchains, execution bounds, and memory limits across 40+ supported compilers and interpreters.
* **`jutge-driver-std` & `jutge-driver-circuits**`: Execution harnesses that receive student source code, enforce sandbox constraints (time/memory limits), feed input vectors, evaluate output differences, and emit verdict tokens (`AC`, `WA`, `TLE`, `MLE`, `RTE`, `CE`).

---

## Key Tech Stack

* **Languages**: TypeScript, Python, Shell, PHP, C++.
* **Runtimes & Tooling**: Bun, Node.js, Docker, LaTeX, Pandoc.
* **Core Domains**: Distributed job evaluation, sandboxed code execution, REST API design, AST/metrics parsing, web frontend engineering.

---

## Discussion Talking Points for Your Meeting

1. **Clarify Subsystem Scope**:
* *Frontend track:* Working on `jutge-web-new` features, accessibility, state management, or UI components for `new.jutge.org`.
* *Instructor track:* Working on `jutge-web-prof` for grading dashboards, exam security, or student analytics.
* *Tooling & Integrations:* Enhancing `jutge-toolkit` / `jtk` features, improving the VS Code extension, or extending `JutgeAI` automated test generation.
* *Execution engine / Drivers:* Compiler containerization, security sandboxing, or new language driver support.


2. **Local Development & Environment Setup**:
* Ask for access permissions to private sub-repos if applicable.
* Ask whether to set up local mocks or connect local clients directly to the staging/dev Jutge API instances.


3. **Roadmap & Priorities**:
* Inquire about the roadmap milestones for migrating legacy traffic fully to `new.jutge.org`.
* Discuss expectations on test coverage, CI/CD pipelines, and pull request workflows within the organization.