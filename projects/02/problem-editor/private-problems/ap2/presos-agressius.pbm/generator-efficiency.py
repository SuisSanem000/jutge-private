import sys


def generate_efficiency_test_cases(num_cases: int) -> None:
    """
    Generates efficiency test cases for the 'Presos agressius' problem.

    This program prints to standard output multiple test cases designed
    to challenge the performance and efficiency of solutions to the problem.
    The test cases follow the problem constraints:
    - N and K satisfy 2 ≤ K ≤ N.
    - Positions of cells are distinct integers.

    The categories of test cases generated are:
    1. Maximum size with evenly spaced cells: N and K large, positions in an
       arithmetic progression with spacing 1, to test algorithms on dense input.
    2. Maximum size with sparse cells: N and K large, positions spaced very far apart,
       testing ability to handle large gaps and large position values.
    3. Maximum size with clustered cells and large K close to N:
       clusters of cells closely packed, forcing algorithm to handle minimal distances.
    4. Large N with K=2 (minimum prisoners), positions spaced non-linearly but
       strictly increasing, to test performance on largest input with minimum K.

    Each test case is printed in the format:
    N K
    p_1 p_2 ... p_N

    No random values are used to ensure reproducibility.
    """
    MAX_N = 10**5  # Assume large max constraint for N
    MAX_POS = 10**9  # Large positions to test for large integer ranges

    cases_generated = 0

    # Category 1: Max size, evenly spaced positions
    if cases_generated < num_cases:
        N = MAX_N
        K = MAX_N // 2  # Half of the positions
        # positions 1,2,3,...,N
        positions = list(range(1, N + 1))
        print(f"{N} {K}")
        print(" ".join(str(p) for p in positions))
        cases_generated += 1

    # Category 2: Max size, sparse positions with large gaps
    if cases_generated < num_cases:
        N = MAX_N
        K = MAX_N - 1000  # Large K close to N
        # positions spaced by 10, to create large gaps: 10,20,30,...,10*N
        positions = [10 * i for i in range(1, N + 1)]
        print(f"{N} {K}")
        print(" ".join(str(p) for p in positions))
        cases_generated += 1

    # Category 3: Max size, clustered cells closely packed with large K
    if cases_generated < num_cases:
        N = MAX_N
        K = N - 1  # K very close to N
        # Create clusters of 10 cells spaced by 1000, each cluster positions spaced by 1
        cluster_size = 10
        gaps_between_clusters = 1000
        positions = []
        clusters = N // cluster_size
        remainder = N % cluster_size
        start_pos = 1
        for _ in range(clusters):
            for i in range(cluster_size):
                positions.append(start_pos + i)
            start_pos += cluster_size + gaps_between_clusters
        for i in range(remainder):
            positions.append(start_pos + i)
        print(f"{N} {K}")
        print(" ".join(str(p) for p in positions))
        cases_generated += 1

    # Category 4: Large N with minimum K=2 and nonlinear spread
    while cases_generated < num_cases:
        N = MAX_N
        K = 2
        positions = []
        # positions are squares: 1,4,9,16,... to test large gaps growing non-linearly
        # fill until N positions
        i = 1
        while len(positions) < N:
            positions.append(i * i)
            i += 1
        print(f"{N} {K}")
        print(" ".join(str(p) for p in positions))
        cases_generated += 1


if __name__ == "__main__":
    num_cases = int(sys.argv[1])
    generate_efficiency_test_cases(num_cases)