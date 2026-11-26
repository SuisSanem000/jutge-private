def generate_hard_test_cases() -> None:
    """
    Generates hard input test cases for the "Presos agressius" problem.

    The generated test cases include:

    1. Minimal distance edge case:
       Positions are all consecutive integers, and K = N.
       This forces the minimal distance to be exactly 1, testing correct placement when 
       the only possible maximal minimal distance is the smallest.

    2. Large gaps with clustered cells:
       A few clusters of cells tightly grouped far apart.
       Tests the algorithm's ability to pick cells across clusters to maximize minimal distance.

    3. Identical maximum gap alternatives:
       Multiple pairs of cells have the same large gaps,
       forcing the solution to choose among equally good distances and test tie-breaking correctness.

    4. Nearly arithmetic progression with one outlier:
       Cells mostly evenly spaced except one cell very far out.
       Tests robustness against outlier positions affecting maximal minimal distance.

    5. Cells sorted but with multiple duplicates removed:
       Cells placed so that the spacing between consecutive cells is not uniform but has repeated gaps,
       which can cause corner cases in binary search or greedy placement logic.

    For each test case, standard output format is:
    N K
    p_1 p_2 ... p_N

    Multiple test cases are printed sequentially.
    """
    # For clarity we print a blank line between test cases (not required by problem).

    # Test case 1: Minimal distance edge case
    # Positions: consecutive integers starting from 1,
    # K = N (all cells occupied), minimal distance must be 1.
    N1 = 10
    K1 = 10
    positions1 = list(range(1, N1 + 1))
    print(N1, K1)
    print(*positions1)
    print()

    # Test case 2: Large gaps with clustered cells
    # Three clusters at positions:
    # Cluster A: 1,2,3
    # Cluster B: 100,101,102
    # Cluster C: 1000,1001,1002
    # K = 4 (pick one or more from clusters far apart)
    N2 = 9
    K2 = 4
    positions2 = [1, 2, 3, 100, 101, 102, 1000, 1001, 1002]
    print(N2, K2)
    print(*positions2)
    print()

    # Test case 3: Identical maximum gap alternatives
    # Positions: gaps of size 10 repeated:
    # 0,10,20,30,40,50
    # K=3, maximal minimal distance could be 20 choosing 0,20,40 or 10,30,50
    # Tests that algorithm does not get confused by multiple optimal placements
    N3 = 6
    K3 = 3
    positions3 = [0, 10, 20, 30, 40, 50]
    print(N3, K3)
    print(*positions3)
    print()

    # Test case 4: Nearly arithmetic progression with one outlier
    # Positions: 0, 5, 10, 15, 20, 1000
    # K=3, testing placing prisoners with one cell extremely far out
    N4 = 6
    K4 = 3
    positions4 = [0, 5, 10, 15, 20, 1000]
    print(N4, K4)
    print(*positions4)
    print()

    # Test case 5: Non-uniform gaps with repeated gap sizes
    # Positions: 1,2,4,7,11,16 (gaps: 1,2,3,4,5)
    # K=3, forces careful placement to maximize minimal distance
    N5 = 6
    K5 = 3
    positions5 = [1, 2, 4, 7, 11, 16]
    print(N5, K5)
    print(*positions5)
    print()


if __name__ == "__main__":
    generate_hard_test_cases()