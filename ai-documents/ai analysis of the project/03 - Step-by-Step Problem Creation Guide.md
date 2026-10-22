# 03 - Step-by-Step Problem Creation Guide

**Goal:** Replicate the exact live terminal demo your professor showed you  
**Example Problem:** *"Sum of Prime Numbers before 100"* (wrapped in a cute story about a girl named Lily)  
**Language Level:** Standard English (B2)

---

## 0. Two Important Questions Answered (Read First!)

### Q1: Do I need to build/compile the cloned projects to get binary files?
**No! You do NOT need to build or compile the 31 cloned repositories to produce binaries.**  
`jutge-toolkit` is an installable command-line tool that runs on **Bun** (a fast JavaScript runtime). 

To have the `jtk` command ready in your terminal, run these 2 quick commands:

```bash
# 1. Install Bun runtime on your Mac (if not already installed)
curl -fsSL https://bun.sh/install | bash

# 2. Install Jutge Toolkit globally
bun install --global @jutge.org/toolkit

# 3. Verify that jtk is installed:
jtk --version
```

*(Note: When you run `jtk make` later to build a problem, `jtk` will automatically call your Mac's built-in C++ compiler `/usr/bin/clang++` to compile your solution. You do not need to manually compile anything beforehand!)*

---

### Q2: I am already logged in on the browser. How do I sign in via terminal?
You have 4 simple ways to sign in from your terminal:

- **Method 1 (Easiest — Automatic Terminal Prompt):**  
  You do not need to sign in beforehand! The first time you run a command that talks to the server (like `jtk upload` or `jtk submit`), `jtk` will automatically pause and ask you:
  ```text
  Jutge.org email: <Type your university email>
  Password: <Type your password (characters stay hidden for security)>
  ```
  Once you press Enter, it connects, verifies your account, and saves your login token locally. You won't have to enter it again.

- **Method 2 (Using Environment Variables):**  
  If you prefer not to wait for prompts, you can export your credentials directly in your terminal:
  ```bash
  export JUTGE_EMAIL="your-university-email@estudiantat.upc.edu"
  export JUTGE_PASSWORD="your-password"
  ```
  `jtk` checks these environment variables automatically.

- **Method 3 (Copy Token from Browser):**  
  Since you are already logged in to `jutge.org` or `new.jutge.org` in your browser:
  1. Open Developer Tools in your browser (Press `Cmd + Option + I` or Right-Click $\to$ **Inspect**).
  2. Go to **Application** (Chrome/Brave) or **Storage** (Firefox/Safari) $\to$ **Cookies** or **Local Storage** for `jutge.org`.
  3. Find the `token` value and copy it.
  4. In your terminal, paste it:
     ```bash
     export JUTGE_TOKEN="your_copied_token_here"
     ```

- **Method 4 (Using Jutge CLI):**  
  Install the Jutge CLI tool and log in once:
  ```bash
  bun install --global @jutge.org/cli
  jutge login
  ```
  Both `jutge` and `jtk` share the exact same credentials file, so logging into `jutge` logs you into `jtk` automatically.

---

## 1. Overview of the Problem Flow

Once your terminal is ready, you will follow these 7 simple steps:
1. Check setup and account login (`jtk doctor`, `jtk config show`).
2. Create the folder `lily-primes.pbm`.
3. Write the story statement in LaTeX (`problem.en.tex`).
4. Write the golden solution in C++ (`solution.cc`).
5. Write sample and private test inputs (`sample-*.inp`, `test-*.inp`).
6. Run `jtk make` to compile the solution and generate correct outputs (`*.cor`).
7. Run `jtk upload` to publish the problem to Jutge.org.

---

## 2. Step-by-Step Instructions

### Step 1: Check System & Account
Open your terminal and verify your environment:
```bash
# Verify compilers and tools are ready
jtk doctor

# Verify your saved configuration
jtk config show
```

---

### Step 2: Create Problem Folder
Every problem needs a folder ending in `.pbm`:
```bash
mkdir lily-primes.pbm
cd lily-primes.pbm
```

---

### Step 3: Write the Problem Statement (`problem.en.tex`)
Create a file named `problem.en.tex` with the narrative about Lily:

```latex
\Problem{Lily and the Prime Flowers}

\Statement
Lily is a kind young girl who loves exploring the meadow behind her house. 
According to a local legend, each flower in the meadow has a number. Only flowers with \emph{prime} numbers carry magical glowing nectar!

Whenever Lily visits the meadow, she chooses a maximum number $n$ and collects nectar from all prime flowers between $2$ and $n$ (inclusive). To write about her adventure in her diary, she wants to calculate the total sum of all these prime numbers.

Write a program that reads numbers $n$ and prints the sum of all prime numbers from $2$ up to $n$.

\Input
The input consists of several natural numbers $n$ ($2 \le n \le 100$), one per line, finishing at end-of-file (EOF).

\Output
For each number $n$, print the sum of all prime numbers between $2$ and $n$ on a single line.

\Sample
```

Create `problem.en.yml` for metadata:
```yaml
title: Lily and the Prime Flowers
author: Simin Shoeibi
email: simin.shoaibi@proton.me
```

---

### Step 4: Write the Golden Solution (`solution.cc`)
Create `solution.cc` in C++. This program computes the true answers:

```cpp
#include <iostream>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        int sum_primes = 0;
        for (int i = 2; i <= n; ++i) {
            if (is_prime(i)) {
                sum_primes += i;
            }
        }
        cout << sum_primes << "\n";
    }
    return 0;
}
```

---

### Step 5: Add Test Cases & Handler Setting

1. Create `handler.yml` (sets standard console I/O):
```yaml
handler: std
```

2. Create public sample inputs in `sample-1.inp` (shown to students):
```text
10
20
```
*(Primes $\le 10$: $2+3+5+7 = 17$. Primes $\le 20$: $17+11+13+17+19 = 77$).*

3. Create hidden test inputs in `test-1.inp` (used to grade edge cases up to 100):
```text
2
3
97
100
```

> **Note:** Do not create `sample-1.cor` or `test-1.cor`. The toolkit creates them in the next step.

---

### Step 6: Build with `jtk make`
Run the build command:
```bash
jtk make
```

**What happens automatically:**
- Compiles `solution.cc`.
- Runs `solution.cc` on `sample-1.inp` and `test-1.inp`.
- Automatically creates `sample-1.cor` and `test-1.cor`.
- Builds PDF and HTML statements using Pandoc/XeLaTeX.

Verify your directory structure:
```bash
jtk lint
```

---

### Step 7: Upload to Jutge.org
Clean temporary binaries and upload:
```bash
jtk clean
jtk upload
```

**The result:**
- `jtk` packages your files into a zip archive and uploads it to the server.
- The server generates an ID (e.g. `P84920_en`) and saves it inside `problem.yml`.
- The terminal displays the live link:
  ```text
  https://jutge.org/problems/Pxxxxx_en
  ```

---

### Step 8: View Live & Test Submit
1. Open the problem link in your web browser (`https://jutge.org/problems/<your-id>` or `https://new.jutge.org/problems/<your-id>`).
2. Test a solution from the terminal:
   ```bash
   jtk submit -l cc solution.cc
   ```
3. You will see the green verdict: **Accepted (AC)**!
