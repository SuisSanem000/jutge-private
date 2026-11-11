# Problem Idea: Dominant Mountain Peaks

> **Navigation:** [Task Overview](../README.md) • [Master Prompt](../CLAUDE-MASTER-PROMPT.md) • [Execution Guide](../HOW-TO-USE-CLAUDE-CODE.md)

## Summary
Given a sequence of integers representing the elevations of mountain peaks from left to right, a peak is called **dominant** if it is strictly higher than every peak that appears to its right in the sequence. The last peak in the sequence is always dominant by definition.

The program must output:
1. The total count of dominant peaks.
2. The elevations of all dominant peaks, in the original order they appeared (left to right).

## Constraints
- Number of test cases: Multiple cases until EOF.
- Sequence length: $1 \le N \le 100,000$.
- Elevations: $-10^9 \le E_i \le 10^9$.
- Time limit: 1.0 second.

## Complexity Requirements
- **Optimal (Golden Solution):** $O(N)$ time and $O(N)$ auxiliary space. Process from right to left while maintaining the running maximum elevation, then output the collected peaks.
- **Slow Solution (`solution-slow.cc`):** $O(N^2)$ time. For each element, scans all subsequent elements to check if any is higher. This solution must trigger `EE, time-limit exceeded` on efficiency test cases.

## Test Case Strategy
- **Sample 1:** A simple sequence demonstrating standard behavior: `5 1 4 2 3` -> Dominant peaks: `5 4 3`.
- **Sample 2:** A strictly descending sequence (all peaks dominant): `10 8 6 4 2` -> Dominant peaks: `10 8 6 4 2`.
- **Private Correctness:** Sequences with negative numbers, identical values (equal height is NOT strictly greater), single-element sequences ($N=1$), and alternating values.
- **Private Efficiency:** Random large sequences ($N=100,000$) and strictly increasing sequences (worst case for naive search).

