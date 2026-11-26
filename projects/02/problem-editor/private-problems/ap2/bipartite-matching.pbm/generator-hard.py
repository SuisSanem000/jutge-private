def write_test_case(case_number: int, edges) -> None:
    with open(f"test-hard-{case_number}.inp", "w") as f:
        for u, v in edges:
            f.write(f"{u} {v}\n")


def generate_hard_test_cases() -> None:
    """
    Generates hard input test cases for the maximum bipartite matching problem.

    The test cases include the following categories:
    - Edge Case: Graph with no edges, testing correct handling of empty matchings.
    - Edge Case: Graph with isolated vertices only on one side, ensuring no invalid matches.
    - Corner Case: A bipartite graph structured as a "chain" or "path" that forces a specific matching.
    - Common Pitfall: Graph with multiple identical edges (parallel edges) between the same pair of vertices.
    - Special Condition: Graph where the maximum matching is less than the size of one partition but not obvious.
    - Degenerate Case: Complete bipartite graph K_n,n where n is small, to verify correct matching size.
    - Corner Case: Bipartite graph with a "layered" structure that forces the algorithm to handle alternating paths properly.
    """
    write_test_case(1, [])

    write_test_case(2, [
        ("u1", "v1"),
        ("u2", "v2"),
    ])

    write_test_case(3, [
        ("u1", "v1"),
        ("u2", "v1"),
        ("u2", "v2"),
        ("u3", "v2"),
        ("u3", "v3"),
    ])

    write_test_case(4, [
        ("u1", "v1"),
        ("u1", "v1"),
        ("u2", "v2"),
        ("u2", "v2"),
    ])

    write_test_case(5, [
        ("u1", "v1"),
        ("u1", "v2"),
        ("u2", "v1"),
        ("u3", "v3"),
    ])

    write_test_case(6, [
        (u, v)
        for u in ("u1", "u2", "u3")
        for v in ("v1", "v2", "v3")
    ])

    write_test_case(7, [
        ("u1", "v1"),
        ("u1", "v2"),
        ("u2", "v1"),
        ("u2", "v3"),
        ("u3", "v2"),
        ("u3", "v4"),
        ("u4", "v3"),
        ("u4", "v4"),
    ])


if __name__ == "__main__":
    generate_hard_test_cases()
