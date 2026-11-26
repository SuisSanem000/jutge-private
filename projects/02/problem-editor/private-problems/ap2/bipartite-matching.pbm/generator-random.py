import sys
import random
import string


def generate_random_word(length: int) -> str:
    """Generate a random lowercase word of given length."""
    return ''.join(random.choices(string.ascii_lowercase, k=length))


def generate_unique_words(count: int, min_len: int = 3, max_len: int = 8) -> list[str]:
    """Generate a list of unique random words."""
    words = set()
    while len(words) < count:
        w = generate_random_word(random.randint(min_len, max_len))
        words.add(w)
    return list(words)


def write_test_case(case_number: int, edges) -> None:
    with open(f"test-random-{case_number}.inp", "w") as f:
        for u, v in edges:
            f.write(f"{u} {v}\n")


def generate_random_test_cases(num_cases: int) -> None:
    """
    Generate random test cases for the maximum matching problem in bipartite graphs.
    Each test case consists of a bipartite graph described by a list of edges connecting vertices
    from set U to vertices from set V.

    Categories of test cases generated:
    1. Empty graph: No vertices and no edges.
    2. Graph with isolated vertices (vertices without edges).
    3. Complete bipartite graphs (every vertex in U connected to every vertex in V).
    4. Sparse bipartite graphs with few random edges.
    5. Medium density bipartite graphs with random edges.
    6. Large bipartite graphs with a moderate number of edges.
    7. Bipartite graphs where vertices have unique matching (perfect matchings).
    8. Bipartite graphs with multiple edges and various random structures.
    """

    for case_number in range(1, num_cases + 1):
        category = random.randint(1, 8)

        # To keep test size reasonable for competitive programming style:
        # Maximum size constraints chosen arbitrarily but realistically.
        max_U = 20
        max_V = 20

        if category == 1:
            edges = []

        elif category == 2:
            # Graph with isolated vertices; edges are few and some vertices have no edges
            nU = random.randint(3, max_U)
            nV = random.randint(3, max_V)
            U = generate_unique_words(nU)
            V = generate_unique_words(nV)
            # Generate few edges, avoiding connecting all vertices
            nE = random.randint(0, max(1, (nU * nV) // 10))
            edges = set()
            while len(edges) < nE:
                u = random.choice(U)
                v = random.choice(V)
                edges.add((u, v))

        elif category == 3:
            # Complete bipartite graph K_{nU,nV}
            nU = random.randint(3, max_U)
            nV = random.randint(3, max_V)
            U = generate_unique_words(nU)
            V = generate_unique_words(nV)
            edges = [(u, v) for u in U for v in V]

        elif category == 4:
            # Sparse graph with few random edges
            nU = random.randint(5, max_U)
            nV = random.randint(5, max_V)
            U = generate_unique_words(nU)
            V = generate_unique_words(nV)
            max_edges = nU * nV
            nE = random.randint(max(1, max_edges // 20), max(1, max_edges // 10))
            edges = set()
            while len(edges) < nE:
                u = random.choice(U)
                v = random.choice(V)
                edges.add((u, v))

        elif category == 5:
            # Medium density bipartite graph
            nU = random.randint(5, max_U)
            nV = random.randint(5, max_V)
            U = generate_unique_words(nU)
            V = generate_unique_words(nV)
            max_edges = nU * nV
            nE = random.randint(max_edges // 4, max_edges // 2)
            edges = set()
            while len(edges) < nE:
                u = random.choice(U)
                v = random.choice(V)
                edges.add((u, v))

        elif category == 6:
            # Larger bipartite graph (up to max_U, max_V) with moderate edges
            nU = random.randint(10, max_U)
            nV = random.randint(10, max_V)
            U = generate_unique_words(nU)
            V = generate_unique_words(nV)
            max_edges = nU * nV
            nE = random.randint(max_edges // 3, max_edges // 2)
            edges = set()
            while len(edges) < nE:
                u = random.choice(U)
                v = random.choice(V)
                edges.add((u, v))

        elif category == 7:
            # Bipartite graph with a perfect matching (unique matching)
            n = random.randint(3, min(max_U, max_V))
            # Generate exactly n edges to form a perfect matching
            U = generate_unique_words(n)
            V = generate_unique_words(n)
            edges = [(U[i], V[i]) for i in range(n)]
            # Add some random extra edges to complicate
            extra_edges_count = random.randint(0, n)
            extra_edges = set()
            while len(extra_edges) < extra_edges_count:
                u = random.choice(U)
                v = random.choice(V)
                if (u, v) not in edges:
                    extra_edges.add((u, v))
            edges.extend(list(extra_edges))

        else:
            # Category 8: Random graph with random edges and random sizes
            nU = random.randint(3, max_U)
            nV = random.randint(3, max_V)
            U = generate_unique_words(nU)
            V = generate_unique_words(nV)
            max_edges = nU * nV
            nE = random.randint(1, max_edges)
            edges = set()
            while len(edges) < nE:
                u = random.choice(U)
                v = random.choice(V)
                edges.add((u, v))

        write_test_case(case_number, edges)


if __name__ == "__main__":
    num_cases = int(sys.argv[1])
    seed = int(sys.argv[2]) if len(sys.argv) > 2 else 42
    random.seed(seed)
    generate_random_test_cases(num_cases)