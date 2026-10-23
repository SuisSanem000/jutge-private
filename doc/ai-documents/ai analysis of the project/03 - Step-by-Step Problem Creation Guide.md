# 03 - Step-by-Step Problem Creation Guide (Terminal Workflow)

**Goal:** Replicate the exact terminal demo your professor showed you on his computer.  
**Example Problem:** *"Sum of Prime Numbers before 100"* (wrapped in a cute story about a girl named Lily).  
**Approach:** 100% terminal commands using `jtk` and JutgeAI. No manual file writing or code editing.  
**Language Level:** Standard English (B2).

---

## 0. Prerequisites & Terminal Sign-In

### Q1: Do I need to build/compile the cloned repositories?
**No.** `jutge-toolkit` is an npm package that runs on **Bun**. It is already installed on your system.
Verify it anytime by running:
```bash
jtk --version
```

### Q2: How do I sign in from the terminal?
The first time you run a command that connects to Jutge.org (`jtk generate problem` or `jtk upload`), the terminal asks you automatically:
```text
? Jutge.org email: simin.shoaibi@proton.me
? Jutge.org password for simin.shoaibi@proton.me: [input is masked]
```
Type your password and press **Enter**. Your session token is saved automatically on your Mac.

> **Tip (Optional):** If you prefer to log in beforehand without waiting for prompts, export your credentials in your terminal:
> ```bash
> export JUTGE_EMAIL="simin.shoaibi@proton.me"
> export JUTGE_PASSWORD="your-jutge-password"
> ```

---

## 1. Summary of the 4 Terminal Commands

Here is the exact flow the professor demonstrated:

```bash
# Step 1: Generate the entire problem with AI
jtk generate problem -k io -d lily-primes.pbm

# Step 2: Enter the created problem folder
cd lily-primes.pbm

# Step 3: Compile solution and generate correct test outputs (.cor)
jtk make

# Step 4: Upload the problem live to Jutge.org
jtk upload
```

---

## 2. Detailed Walkthrough

### Step 1: Run the Problem Generator in Terminal

Run this command in your terminal:
```bash
jtk generate problem -k io -d lily-primes.pbm
```

#### What happens in your terminal:
`jtk` launches an interactive setup wizard and asks you questions directly in the terminal:

1. **Title:**
   ```text
   ? Title: Lily and the Prime Flowers
   ```
   *(Type the title and press Enter)*

2. **Description (Prompt for the AI):**
   ```text
   ? Description: Lily is a cute young girl who collects glowing flowers in a magical meadow. Each flower has a number. Lily only collects nectar from flowers with prime numbers up to n (where 2 <= n <= 100). Write a program that reads numbers n from standard input until end of file, and for each n prints the sum of all prime numbers between 2 and n.
   ```
   *(Paste or type the story prompt and press Enter)*

3. **Author & Email:**
   - Author: Press Enter to keep your name (`Simin Shoeibi`).
   - Email: Press Enter to keep your email (`simin.shoaibi@proton.me`).

4. **Languages:**
   - **Original language:** Select `en` (English).
   - **Translations:** Select `ca` (Catalan) and `es` (Spanish) if you want translations, or press Enter to skip.

5. **Programming Languages:**
   - **Golden solution language:** Select `cc` (C++).
   - **Alternative languages:** Select `py` (Python).
   - **Generators:** Keep defaults (`hard`, `random`, `efficiency`).

6. **Confirm:**
   - Select **Confirm** and press Enter.

#### What JutgeAI does automatically in seconds:
- Sends your prompt to the JutgeAI backend.
- Generates `problem.en.tex` with the story formatted in Jutge LaTeX.
- Generates `solution.cc` (the C++ reference code).
- Generates `solution.py` (the alternative Python code).
- Generates sample test cases (`sample-1.inp`, `sample-2.inp`).
- Generates hidden grading tests (`test-1.inp`, `test-2.inp`).
- Generates Python test generator scripts (`generate-random.py`, `generate-hard.py`).
- Generates `handler.yml` and a summary `README.md`.

---

### Step 2: Enter the Problem Directory

```bash
cd lily-primes.pbm
```

You can view the generated files with:
```bash
ls -la
```

---

### Step 3: Build Test Cases with `jtk make`

Run the make command:
```bash
jtk make
```

#### What happens automatically:
1. `jtk` compiles `solution.cc` using your Mac's C++ compiler.
2. Runs the compiled program on all `.inp` test files.
3. Automatically creates all `.cor` (correct output) files.
4. Prepares the problem statement for the website.

#### Optional Quick Check:
Run the linter to verify that the problem package has zero syntax or formatting issues:
```bash
jtk lint
```
It will report: `No errors found`.

---

### Step 4: Upload Directly to Jutge.org

Clean temporary binary files and upload:
```bash
jtk clean
jtk upload
```

#### What happens in terminal:
- `jtk` packages all problem files into a zip file.
- Uploads the package to the Jutge server.
- The server registers the problem, assigns a unique problem ID (e.g., `P84920_en`), and saves it into `problem.yml`.
- The terminal prints the live link:
  ```text
  ✔ Uploaded problem P84920_en
  https://jutge.org/problems/P84920_en
  ```

---

### Step 5: View Live on Site & Submit

1. Open the URL printed by `jtk upload` in your browser:
   ```text
   https://jutge.org/problems/<your_problem_id>
   ```
   *(Or on `https://new.jutge.org/problems/<your_problem_id>`)*

2. You can also test submitting your solution directly from the terminal:
   ```bash
   jtk submit -l cc solution.cc
   ```
   The terminal will show the evaluation results and the green verdict: **Accepted (AC)**!

---

## 3. Alternative: 1-Step Automated Generation (Headless Mode)

If you do not want to answer interactive terminal questions every time, you can put the specification into a YAML file and tell `jtk` not to ask:

```bash
# 1. Write specification file
cat << 'EOF' > lily-spec.yml
title: Lily and the Prime Flowers
description: Lily is a cute young girl who collects glowing flowers with prime numbers up to n (where 2 <= n <= 100). Calculate the sum of prime numbers up to n.
golden_proglang: cc
original_language: en
more_proglangs: [py]
more_languages: [ca, es]
generators: [hard, random, efficiency]
EOF

# 2. Run generator in non-interactive mode (-n / --do-not-ask)
jtk generate problem -k io -i lily-spec.yml -n -d lily-primes.pbm

# 3. Build and upload
cd lily-primes.pbm
jtk make
jtk upload
```

---

## 4. What to Tell Your Professor in the Meeting

Here is a 30-second summary you can use in your meeting:

> *"I replicated the exact workflow you demonstrated using `jtk` in the terminal: I used `jtk generate problem` with JutgeAI to draft the problem with the cute story about Lily and prime numbers, ran `jtk make` to compile the golden solution and generate test cases, and uploaded it to Jutge.org with `jtk upload` where it is live and verified. I am familiar with the CLI and ready to work on the internals of `jutge-toolkit`."*
