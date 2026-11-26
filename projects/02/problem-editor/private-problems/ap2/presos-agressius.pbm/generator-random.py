import sys
import random


def generate_random_test_cases(num_cases: int) -> None:
    """
    Generates and prints random test cases for the 'Presos agressius' problem.

    Each test case consists of:
    - N: the number of prison cells (each with distinct integer positions on a number line).
    - K: the number of aggressive prisoners to place (2 ≤ K ≤ N).
    - A list of N distinct integers representing the positions of the cells.

    The program outputs multiple test cases, each on a separate group of lines as specified.

    The test cases generated fall into the following categories to cover a wide range of scenarios:

    1. Small cases:
        - Minimal valid sizes (e.g., N=K=2).
        - Small N with K close to N.

    2. Uniformly spaced cells:
        - Positions placed at equal intervals (e.g., 1, 2, 3, ... or with a fixed step).
        - To test distributions with predictable spacing.

    3. Large range, sparse cells:
        - Positions scattered randomly over a large range.
        - Tests algorithm's handling of large gaps.

    4. Reverse ordered or shuffled input:
        - Positions not sorted to ensure proper sorting in solution.

    Constraints are respected:
    - 2 ≤ K ≤ N
    - Positions are distinct integers.
    - Positions can be positive integers, with upper bound around 1,000,000,000 for diversity.

    The number of test cases to generate is determined by num_cases.

    Output format per test case:
    N K
    p1 p2 ... pN
    """
    MAX_POSITION = 10**9

    for _ in range(num_cases):
        case_type = random.choice([1, 2, 3, 4])
        print(f"Case type: {case_type}", file=sys.stderr)

        if case_type == 1:
            # Small cases
            # N and K small, positions packed tightly
            N = random.randint(2, 10)
            K = random.randint(2, N)
            positions = random.sample(range(1, 20), N)
            positions.sort()

        elif case_type == 2:
            # Uniformly spaced cells
            # Choose N up to 1000 for variety
            N = random.randint(10, 1000)
            K = random.randint(2, N)
            step = random.randint(1, 1000)
            start = random.randint(1, 1000)
            positions = [start + i * step for i in range(N)]

        elif case_type == 3:
            # Large range, sparse cells
            # N up to 2000, positions scattered over large range
            N = random.randint(100, 2000)
            K = random.randint(2, N)
            positions = set()
            while len(positions) < N:
                positions.add(random.randint(1, MAX_POSITION))
            positions = sorted(positions)

        elif case_type == 4:
            # Reverse ordered or shuffled input
            # N and K moderate
            N = random.randint(10, 1000)
            K = random.randint(2, N)
            positions = random.sample(range(1, 50_000), N)
            # shuffle positions randomly; do not sort to test input order
            random.shuffle(positions)

        # print test case
        print(f"{N} {K}")
        print(" ".join(str(p) for p in positions))


if __name__ == "__main__":
    num_cases = int(sys.argv[1])
    seed = int(sys.argv[2]) if len(sys.argv) > 2 else 42
    random.seed(seed)
    generate_random_test_cases(num_cases)