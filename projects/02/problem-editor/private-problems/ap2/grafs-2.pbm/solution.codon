"""
Jordi Petit, feb 2023
"""

from yogi import read


AdjacencyList = list[int]
Graph = list[AdjacencyList]


def dfs(G: Graph, u: int, vis: list[bool]):
    if not vis[u]:
        vis[u] = True
        for v in G[u]:
            dfs(G, v, vis)


def reachable(G: Graph, x: int, y: int) -> bool:
    n = len(G)
    vis = [False for _ in range(n)]
    dfs(G, x, vis)
    return vis[y]


def main():
    n = read(int)
    ids = {read(str): i for i in range(n)}
    m = read(int)
    G: Graph = [[] for _ in range(m)]
    for _ in range(m):
        u = ids[read(str)]
        v = ids[read(str)]
        G[u].append(v)
    x = ids[read(str)]
    y = ids[read(str)]
    print("yes" if reachable(G, x, y) else "no")


main()
