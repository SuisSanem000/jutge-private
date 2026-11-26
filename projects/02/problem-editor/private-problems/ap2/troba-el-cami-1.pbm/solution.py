import heapq
from dataclasses import dataclass, field
from yogi import read, scan

Cell = tuple[int, int]  # A cell of the matrix


@dataclass(order=True)
class State:
    """State of the A* search in a maze"""
    f: int  # The f-value of A* (used as priority)
    h: int  # The h-value of A* (used as priority in case of a tie of f)
    cell: Cell = field(compare=False)


Obstacles = set[Cell]  # A data type to represent the set of obstacles


def distance(c1: Cell, c2: Cell) -> int:
    """Returns the Manhattan distance between two cells"""
    return abs(c1[0]-c2[0]) + abs(c1[1]-c2[1])


def astar_search(source: Cell, target: Cell, obs: Obstacles) -> int:
    """A* search from source to target avoiding the obstacles.
    It returns the shortest distance using Manhattan paths. In case no
    path exists, it will return -1. Be careful: the algorithm may not
    terminate if no path exists."""
    visited: set[Cell] = set()  # Set of visited cells
    d = distance(source, target)
    # The priority queue uses f as priority. In case of a tie, it uses h,
    # which means that the cells closer to the target are expanded first.
    q: list[State] = [State(d, d, source)]
    while q:
        s = heapq.heappop(q)
        if s.cell == target:  # Check if we reached the target
            return s.f
        i, j = s.cell[0], s.cell[1]
        # Since f(n) = g(n)+h(n), we can compute g and add +1 for the next cell
        g = s.f - s.h + 1
        for c in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)):  # Neighbors
            if c[0] < 0 or c[1] < 0 or c in obs or c in visited:
                continue
            h = distance(c, target)
            heapq.heappush(q, State(g + h, h, c))
            visited.add(c)
    return -1


def main() -> None:
    # Read source and target coordinates
    source: Cell = (read(int), read(int))
    target: Cell = (read(int), read(int))
    # Read the set of obstacles
    obstacles: set[Cell] = set()
    i = scan(int)
    while i is not None:
        obstacles.add((i, read(int)))
        i = scan(int)
    # Search and print length of the shortest path
    print(astar_search(source, target, obstacles))


main()
