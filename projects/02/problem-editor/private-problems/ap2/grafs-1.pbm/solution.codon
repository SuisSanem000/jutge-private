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
    n, m = read(int), read(int)
    G: Graph = [[] for _ in range(n)]
    for _ in range(m):
        G[read(int)].append(read(int))
    x, y = read(int), read(int)
    print("yes" if reachable(G, x, y) else "no")


main()
