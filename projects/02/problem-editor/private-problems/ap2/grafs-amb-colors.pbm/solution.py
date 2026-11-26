from yogi import read, tokens
from typing import TypeAlias


Vertex: TypeAlias = int
AdjacencyList: TypeAlias = list[int]
Graph: TypeAlias = list[AdjacencyList]


def dfs(G: Graph, colors: list[str], src: Vertex, dst: Vertex, vis: list[bool]) -> bool:
    """
    Depth-first search to check if there is a path between two vertices src and dst
    without two consecutive vertices with the same color.
    """

    if src == dst:
        return True
    if not vis[src]:
        vis[src] = True
        for nxt in G[src]:
            if colors[nxt] != colors[src]:
                if dfs(G, colors, nxt, dst, vis):
                    return True
    return False


def reachable(G: Graph, colors: list[str], x: int, y: int) -> bool:
    """
    Check if there is a path between two vertices x and y without two consecutive vertices with the same color.
    """

    n = len(G)
    vis = [False for _ in range(n)]
    return dfs(G, colors, x, y, vis)


def main():
    # read graph with colors
    n = read(int)
    G: Graph = [[] for _ in range(n)]
    colors: list[str] = []
    ids: dict[str, Vertex] = {}
    for i in range(n):
        name = read(str)
        colors.append(read(str))
        ids[name] = i
    m = read(int)
    for _ in range(m):
        u = ids[read(str)]
        v = ids[read(str)]
        G[u].append(v)
    # read source and destination vertices and write result
    for x in tokens(str):
        y = read(str)
        if reachable(G, colors, ids[x], ids[y]):
            print("yes")
        else:
            print("no")


main()
