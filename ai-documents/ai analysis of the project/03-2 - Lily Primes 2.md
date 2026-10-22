# 03-2 - Lily Primes 2 (Commands & Outcomes Guide)

**Purpose:** Quick command-by-command cheat sheet to create, build, and publish the problem `lily-primes-2` on your own.  
**Language Level:** Standard English (B2).

---

## Pre-Check: Login & Environment

### Command:
```bash
jutge login
```
### Expected Outcome:
```text
? Jutge.org email: simin.shoaibi@proton.me
? Jutge.org password for simin.shoaibi@proton.me: [input is masked]
✔ Logged in as Simin Shoeibi with email simin.shoaibi@proton.me
```

---

## Step 1: Generate the Problem with JutgeAI

### Command:
```bash
jtk generate problem -k io -d lily-primes-2.pbm
```

### What to Enter in Terminal Prompts:
| Prompt | What to Type / Select |
|---|---|
| `? Title:` | `Lily and the Prime Flowers 2` |
| `? Description:` | `Lily is a cute young girl who collects glowing flowers in a magical meadow. Each flower has a number. Lily only collects nectar from flowers with prime numbers up to n (2 <= n <= 100). Write a program that reads numbers n from standard input until end of file, and prints the sum of all prime numbers between 2 and n.` |
| `? Author:` | Press **Enter** *(keeps `Simin Shoeibi`)* |
| `? Email:` | Press **Enter** *(keeps `simin.shoaibi@proton.me`)* |
| `? Language for original version:` | Select **`en` (English)** |
| `? Other languages:` | Select **`ca`** and **`es`** *(or press Enter to skip)* |
| `? Programming language for golden solution:` | Select **`cc` (C++)** |
| `? Other programming languages:` | Select **`py` (Python)** |
| `? Generators:` | Press **Enter** *(keeps `hard`, `random`, `efficiency`)* |
| `? Choose an action:` | Select **`Confirm`** |

### Expected Outcome:
```text
┌──────────────────────────────────────────────────────────────────────────────┐
│ Generating problem with JutgeAI using openai/gpt-6-luna                      │
└──────────────────────────────────────────────────────────────────────────────┘
│   Generating statement ✔
│   Generating testcases ✔
│   Generating solutions ✔
│   Translating statements ✔
│   Generating test cases generators ✔
│   Generating README.md ✔
✔ Created problem lily-primes-2.pbm
```

---

## Step 2: Enter the Folder

### Command:
```bash
cd lily-primes-2.pbm
```

### Expected Outcome:
Your terminal prompt changes to:
```text
siminshoeibizadeh@simins-MacBook-Air lily-primes-2.pbm %
```

---

## Step 3: Build and Generate Correct Test Outputs (`.cor`)

### Command:
```bash
jtk make
```

### Expected Outcome:
```text
┌──────────────────────────────────────────────────────────────────────────────┐
│ Making problem lily-primes-2.pbm                                             │
└──────────────────────────────────────────────────────────────────────────────┘
│   Compiling solution.cc with clang++ ✔
│   Running test sample-1.inp -> sample-1.cor ✔
│   Running test sample-2.inp -> sample-2.cor ✔
│   Running test test-1.inp -> test-1.cor ✔
│   Running test test-2.inp -> test-2.cor ✔
✔ Make completed successfully
```

---

## Step 4: Verify Quality (Linting)

### Command:
```bash
jtk lint
```

### Expected Outcome:
```text
┌──────────────────────────────────────────────────────────────────────────────┐
│ Linting lily-primes-2.pbm                                                    │
└──────────────────────────────────────────────────────────────────────────────┘
✔ No errors found! Problem package is valid.
```

---

## Step 5: Upload Live to Jutge.org

### Command:
```bash
jtk clean
jtk upload
```

### Expected Outcome:
```text
┌──────────────────────────────────────────────────────────────────────────────┐
│ Uploading problem to Jutge.org                                               │
└──────────────────────────────────────────────────────────────────────────────┘
│   Packaging problem files into archive... ✔
│   Uploading to Jutge.org API v2... ✔
│   Problem ID assigned: P84921_en ✔
✔ Uploaded problem successfully:
  https://jutge.org/problems/P84921_en
```

---

## Step 6: Test Submit Live Solution

### Command:
```bash
jtk submit -l cc solution.cc
```

### Expected Outcome:
```text
┌──────────────────────────────────────────────────────────────────────────────┐
│ Submitting solution to Jutge.org                                             │
└──────────────────────────────────────────────────────────────────────────────┘
│   Verdict: Accepted (AC) ✔
│   CPU Time: 0.00s
│   Memory: 1.2 MB
✔ Correct answer on all test cases!
```

---

## Shortcut: 100% Non-Interactive Command (Headless)

If you want to create the entire problem in one single copy-paste without answering interactive prompts:

```bash
# 1. Create specification file
cat << 'EOF' > lily2-spec.yml
title: Lily and the Prime Flowers 2
description: Lily is a cute young girl who collects glowing flowers with prime numbers up to n (2 <= n <= 100). Calculate the sum of primes up to n.
golden_proglang: cc
original_language: en
more_proglangs: [py]
more_languages: [ca, es]
generators: [hard, random, efficiency]
EOF

# 2. Run generator in automated mode (-n)
jtk generate problem -k io -i lily2-spec.yml -n -d lily-primes-2.pbm

# 3. Enter, build, and publish
cd lily-primes-2.pbm
jtk make
jtk upload
```
