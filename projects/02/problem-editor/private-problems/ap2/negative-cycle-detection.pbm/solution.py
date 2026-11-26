from typing import TypeAlias
import yogi

INF = 1000000000000  # a large number to represent infinity according to the problem constraints

Arc: TypeAlias = tuple[int, int]  # (destination, cost)
AdjacencyList: TypeAlias = list[Arc]
Graph: TypeAlias = list[AdjacencyList]


def contains_negative_cycle(G: Graph) -> bool:
    """Tells whether the graph G contains a negative cycle using the Bellman-Ford algorithm."""

    n = len(G)
    dist = [0] * n

    # relax edges n times
    for _ in range(n):
        for u in range(n):
            for v, c in G[u]:
                if dist[u] < INF and dist[u] + c < dist[v]:
                    dist[v] = dist[u] + c

    # check for negative cycles
    return any(dist[u] < INF and dist[u] + c < dist[v] for u in range(n) for v, c in G[u])


def main() -> None:
    for n in yogi.tokens(int):
        G: Graph = [[] for _ in range(n)]
        for _ in range(yogi.read(int)):
            u, v, c = yogi.read(int), yogi.read(int), yogi.read(int)
            G[u].append((v, c))
        print("YES" if contains_negative_cycle(G) else "NO")


if __name__ == "__main__":
    main()
