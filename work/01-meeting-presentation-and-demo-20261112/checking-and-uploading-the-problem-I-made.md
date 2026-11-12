# Checking & Uploading Dominant Peaks (`dominant-peaks.pbm`)

> **Live Meeting Cheat Sheet:** Clean, sequential one-line commands to inspect, verify, upload, and test your generated problem in front of your professors.

---

### 1. Navigate to the Problem Directory

Go into the problem directory (if in your separate `problem-editor` workspace):
```bash
cd dominant-peaks.pbm
```

*(Or go into the problem directory if running from the `jutge-private` repository):*
```bash
cd /Users/siminshoeibizadeh/mienne/Programming/dev/projects/scholarship-project-uni/jutge-private/work/01-meeting-presentation-and-demo-20261112/01-claude-task/dominant-peaks.pbm
```

---

### 2. Lint the Problem Directory

Validate the folder anatomy, YAML schemas, and test file naming conventions:
```bash
jtk lint
```

---

### 3. Generate Official Output Files (`.cor`)

Compile the golden solution and generate all expected output files from test inputs:
```bash
jtk make exe cor
```

---

### 4. Verify the Naive Solution

Test the naive quadratic solution to demonstrate correctness and worst-case time limit enforcement:
```bash
jtk verify solution-slow.cc
```

---

### 5. Clean Build Artifacts Before Upload

Remove compiled binaries and temporary files so only clean source is uploaded:
```bash
jtk clean
```

---

### 6. Upload Problem to Jutge.org

Publish the problem to Jutge web services, stream live validation logs, and receive the Problem ID:
```bash
jtk upload
```

---

### 7. View Problem ID & Sharing Settings

Display the server-assigned Problem ID, generated passcode, and sharing settings recorded in `problem.yml`:
```bash
jtk share show
```

---

### 8. Submit Solution to Live Judge

Submit the C++17 golden solution to Jutge.org to verify the remote server Accepted verdict:
```bash
jtk submit -l C++17 solution.cc
```

