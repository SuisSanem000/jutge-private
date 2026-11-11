
# What I did: the "Dominant Mountain Peaks" problem

## The problem
We have a list of mountain heights. A peak is "dominant" if it is higher than ALL the peaks to its right. The last peak is always dominant. For each list, we print the dominant peaks from left to right.

Example: `3 1 4 1 2 1` → `4 2 1`
- The last `1` is dominant (nothing is to its right).
- `2` is higher than the `1` after it → dominant.
- `4` is higher than `1, 2, 1` → dominant.
- The other peaks are not dominant. A peak with an equal height to its right does not count, because the rule says "strictly higher".

## The idea of the fast solution (O(N))
Go through the list from right to left. Remember the highest peak seen so far. If the current peak is higher than that maximum, it is dominant. Save it and update the maximum.

We find the peaks from right to left, so at the end we print them in reverse order. Each peak is looked at only once, so it takes O(N) time.

## The slow solution (O(N²))
For each peak, look at the peaks to its right and stop when you find one that is the same height or higher. This is correct, but it is slow when the list is strictly decreasing. In that case every peak is dominant, so every scan goes to the end. With N = 100,000 that is billions of comparisons.

## The files I created (folder `dominant-peaks.pbm/`)
| File | Purpose |
|---|---|
| `handler.yml` | Tells Jutge: standard grading, G++17, a full program with a `main` |
| `problem.en.yml` | Title, author, email |
| `problem.en.tex` | The problem statement in LaTeX |
| `solution.cc` | The fast, correct solution. Jutge uses it to create the expected outputs |
| `solution-slow.cc` | The slow solution, used to check that the tests catch slow code |
| `sample-1.inp`, `sample-2.inp` | Public examples that students see |
| `generate.ts` | A Bun/TypeScript script that creates the private tests |
| `scores.yml` | How the points are divided |
| `.clang-format`, `.gitignore` | Code style, and files that Git should ignore |

## The tests
`generate.ts` makes the private tests. It uses a fixed random seed, so the tests are always the same. Each test file has its own function.
- **correctness-1-edge**: a single peak, equal heights, negative numbers, the extreme values ±10⁹.
- **correctness-2-alternating-small**: alternating values and many small random lists.
- **efficiency-1-random**: big random lists (N = 100,000). A second file uses only the values from -3 to 3, so the answers are more varied.
- **efficiency-2-monotone**: big increasing and decreasing lists. The decreasing ones are the worst case for the slow solution. Its output is bigger than 2 MB, so I added an `.ops` file with `--maxoutput=4`.

## Scores
Points must be whole numbers that add up to 10:
- correctness tests: 4 points
- efficiency tests: 6 points (this group also includes the correctness tests, so a wrong program cannot get these points by luck)

## How I checked it
- `jtk make exe cor` compiled the fast solution and created the `.cor` files (expected outputs). I never wrote those by hand.
- `jtk lint` reported no problems.
- `jtk verify solution-slow.cc` showed that the slow solution gives correct answers but takes 3.8 s on the hardest test. The fast one takes 0.42 s, so the slow one is about 9 times slower.

## Problems I found and fixed
1. My first slow solution counted over all elements without stopping. The compiler made it fast, so it was only 3 times slower. I changed it to stop at the first peak that is the same height or higher, and I added decreasing lists as tests.
2. The hardest test's output was bigger than 2 MB, so I added the `.ops` file.
3. The generator was one long script. I split it into one function per test file, with parameters.
4. The `.cor` files should not go into Git, so I added a `.gitignore`.

## Differences from the original request
- Test files are named `private-...` because the project spec requires it.
- Scores are 4 and 6 instead of 40 and 60. The spec says the total must be 10, and the ratio is the same.
- The statement ends with `\SampleTwoCol`, which builds the sample tables from the sample files.

## Not done / not checked
- The statement was not compiled to PDF, because pandoc with Lua support is not installed.
- `clang-format` is not installed, so I formatted the code by hand.
- The spec also asks for Catalan and Spanish statements. I wrote only English.
- Code comments are in English, but the course rules say Catalan.
- I did not commit or push anything.