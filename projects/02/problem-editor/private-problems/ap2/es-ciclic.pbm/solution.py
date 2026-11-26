from yogi import read, tokens

AdjList = list[int]
Graph = list[AdjList]


def read_graph(n: int) -> Graph:
    m = read(int)
    G: Graph = [[] for _ in range(n)]
    for _ in range(m):
        G[read(int)].append(read(int))
    return G


def is_cyclic(G: Graph) -> bool:
    n = len(G)

    # compute input degree of each node
    in_degree = [0 for _ in range(n)]
    for u in range(n):
        for v in G[u]:
            in_degree[v] += 1

    # create list of nodes with input degree zero
    zeroes = [u for u in range(n) if in_degree[u] == 0]

    # remove from list and "erase" arcs
    while zeroes != []:
        u = zeroes.pop()
        n -= 1
        for v in G[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                zeroes.append(v)

    return n > 0


def main():
    for n in tokens(int):
        print("yes" if is_cyclic(read_graph(n)) else "no")


main()