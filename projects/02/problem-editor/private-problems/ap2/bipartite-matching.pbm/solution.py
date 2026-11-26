from typing import TypeAlias
from collections import defaultdict, deque
import yogi

Arc: TypeAlias = tuple[str, str]  # (left side node, right side node)
BipartiteGraph: TypeAlias = list[Arc]

WeightedArc: TypeAlias = tuple[int, int, int]  # (source, destination, capacity)
Network: TypeAlias = list[WeightedArc]


def read_bipartite_graph() -> BipartiteGraph:
    g: BipartiteGraph = []
    for u in yogi.tokens(str):
        v = yogi.read(str)
        g.append((u, v))
    return g


def read_weighted_graph() -> Network:
    return [
        (yogi.read(int), yogi.read(int), yogi.read(int)) for _ in range(yogi.read(int))
    ]


class MaxFlowAlgorithm:
    _source: int
    _sink: int
    _network: Network
    _cap: defaultdict[int, defaultdict[int, int]]
    _flow: dict[tuple[int, int], int]
    _max_flow: int

    def __init__(self, network: Network, source: int, sink: int):
        """
        Initialize the max flow algorithm with the graph and the source and sink nodes.
        """

        self._source = source
        self._sink = sink
        self._network = network

        # Residual capacity: cap[u][v] = remaining capacity on edge u->v
        self._cap = defaultdict(lambda: defaultdict(int))
        # Flow assigned to each original arc
        self._flow = {}
        self._max_flow = 0

        for u, v, c in network:
            self._cap[u][v] += c
            self._flow[(u, v)] = self._flow.get((u, v), 0)  # init to 0
            # Reverse edge (for residual graph); don't overwrite if already exists
            if v not in self._cap or u not in self._cap[v]:
                self._cap[v][u]  # touch to ensure key exists (defaults to 0)

    def _bfs(self) -> dict[int, int] | None:
        """Find an augmenting path via BFS. Returns parent map, or None if no path."""

        parent: dict[int, int] = {self._source: -1}
        queue = deque([self._source])
        while queue:
            u = queue.popleft()
            for v, cap in self._cap[u].items():
                if v not in parent and cap > 0:
                    parent[v] = u
                    if v == self._sink:
                        return parent
                    queue.append(v)
        return None

    def run(self) -> None:
        """
        Run the max flow algorithm.
        """

        while (parent := self._bfs()) is not None:
            # Find bottleneck capacity along the path
            path_flow = 10**18
            v = self._sink
            while v != self._source:
                u = parent[v]
                path_flow = min(path_flow, self._cap[u][v])
                v = u

            # Update residual capacities along the path
            v = self._sink
            while v != self._source:
                u = parent[v]
                self._cap[u][v] -= path_flow
                self._cap[v][u] += path_flow
                v = u

            self._max_flow += path_flow

    def maxflow(self) -> int:
        """
        Return the maximum flow of the graph.
        Prec: .run() has been called.
        """

        return self._max_flow

    def flow(self, source: int, destination: int) -> int:
        """
        Return the flow on the edge from the source to the destination.
        Prec: .run() has been called.
        """

        original_cap = sum(
            c for u, v, c in self._network if u == source and v == destination
        )
        return original_cap - self._cap[source][destination]


def max_matching(g: BipartiteGraph) -> int:
    """Returns the size of a maximum matching in the given bipartite graph."""

    left_nodes = set[str]()
    right_nodes = set[str]()
    index = dict[str, int]()  # dict str -> int
    n = 0
    for u, v in g:
        if u not in left_nodes:
            left_nodes.add(u)
            index[u] = n
            n += 1
        if v not in right_nodes:
            right_nodes.add(v)
            index[v] = n
            n += 1

    network: Network = []
    source = n
    sink = n + 1
    for u in left_nodes:
        network.append((source, index[u], 1))
    for u, v in g:
        network.append((index[u], index[v], 1))
    for v in right_nodes:
        network.append((index[v], sink, 1))

    alg = MaxFlowAlgorithm(network, source, sink)
    alg.run()
    return alg.maxflow()


def main2() -> None:
    graph = read_weighted_graph()
    source, sink = yogi.read(int), yogi.read(int)
    alg = MaxFlowAlgorithm(graph, source, sink)
    alg.run()
    print(alg.maxflow())
    for source_node, destination, _ in graph:
        print(source_node, destination, alg.flow(source_node, destination))


def main() -> None:
    print(max_matching(read_bipartite_graph()))


if __name__ == "__main__":
    main()
