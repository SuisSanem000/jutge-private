from dataclasses import dataclass
from yogi import read, scan
from collections import deque

Cell = tuple[int, int]  # A cell of the matrix


@dataclass
class State:
    """State of the BFS search in a maze"""
    d: int  # distance
    cell: Cell  # location


Obstacles = set[Cell]  # A data type to represent the set of obstacles


def bfs(source: Cell, target: Cell, obs: Obstacles) -> int:
    """BFS to find the shortest path from source to target avoiding
    the obstacles. It returns the shortest distance using Manhattan paths.
    It returns -1 if no path is found. Be careful: the algorithm may not
    terminate if no path exists."""
    visited: set[Cell] = set()
    q = deque([State(0, source)])  # BFS FIFO
    while q:
        s = q.popleft()
        if s.cell == target:
            return s.d
        i, j = s.cell[0], s.cell[1]
        for c in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)):
            if c[0] < 0 or c[1] < 0 or c in obs or c in visited:
                continue
            q.append(State(s.d + 1, c))
            visited.add(c)
    return -1


def main() -> None:
    # Read source and target coordinates
    source: Cell = (read(int), read(int))
    target: Cell = (read(int), read(int))
    obstacles: set[Cell] = set()
    i = scan(int)
    while i is not None:
        obstacles.add((i, read(int)))
        i = scan(int)
    # Search and print length of the shortest path
    print(bfs(source, target, obstacles))


main()
