"""
Jordi Petit, feb 2023
"""


from yogi import read, tokens
import heapq

AdjList = list[int]
Graph = list[AdjList]


def read_graph(n: int) -> Graph:
    m = read(int)
    G: Graph = [[] for _ in range(n)]
    for _ in range(m):
        G[read(int)].append(read(int))
    return G


def topological_ordering(G: Graph) -> list[int]:
    n = len(G)

    # compute input degree of each node
    in_degree = [0 for _ in range(n)]
    for u in range(n):
        for v in G[u]:
            in_degree[v] += 1

    # create priority queue of nodes with input degree zero
    pq = [u for u in range(n) if in_degree[u] == 0]
    heapq.heapify(pq)

    # remove from queue and "erase" arcs
    ordering: list[int] = []
    for _ in range(n):
        u = heapq.heappop(pq)
        ordering.append(u)
        for v in G[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                heapq.heappush(pq, v)

    return ordering


def main():
    for n in tokens(int):
        print(*topological_ordering(read_graph(n)))


main()
