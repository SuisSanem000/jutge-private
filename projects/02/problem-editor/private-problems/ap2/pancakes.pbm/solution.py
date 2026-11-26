import sys
from typing import TypeAlias, Optional
from dataclasses import dataclass, field
import heapq
from yogi import read
import time


DIJKSTRA = False  # Set to True to disable heuristic


Pancakes: TypeAlias = list[int]


@dataclass(order=True)
class State:
    f: int
    g: int = field(compare=False)
    h: int
    pancakes: Pancakes = field(compare=False)
    flips: list[int] = field(compare=False)


def read_pancakes() -> Pancakes:
    n = int(input())
    return [read(int) for _ in range(n)]


def hscore(p: Pancakes) -> int:
    """Count number of non consecutive integers (+1 if last is not the biggest)"""
    if DIJKSTRA:
        return 0
    h = 1 if p[-1] != len(p) else 0
    for i in range(len(p)-1):
        if abs(p[i+1] - p[i]) > 1:
            h += 1
    return h


def solved(p: Pancakes) -> bool:
    return all(p[i] == i+1 for i in range(len(p)))


def flip(p: Pancakes, k: int) -> Pancakes:
    """Returns the array after a flip of the first k pancakes"""
    c = p[:]
    c[:k] = c[:k][::-1]
    return c


def minimum_steps(p: Pancakes) -> Optional[int]:
    """Returns the minimum number of steps to solve the pancakes, or None if impossible"""
    n = len(p)
    # el set hauria de ser de Pancakes però les llistes són mutables per tant en deso les seves tuples
    visited: set[tuple[int]] = set()
    h = hscore(p)
    q: list[State] = [State(h, 0, h, p, [])]
    while q:
        s = heapq.heappop(q)
        if solved(s.pancakes):
            # print("Solution flips:", s.flips, file=sys.stderr)
            # print("Number of explored states:", len(visited), file=sys.stderr)
            return s.g
        for k in range(2, n+1):  # state neighbours
            c = flip(s.pancakes, k)
            tc = tuple(c)
            if tc not in visited:
                g = s.g + 1
                h = hscore(c)
                flips = s.flips[:] + [k]
                heapq.heappush(q, State(g + h, g, h, c, flips))
                visited.add(tc)
    return None


def main() -> None:
    if DIJKSTRA:
        print("Executing in Dijkstra mode! (h=0)", file=sys.stderr)
    # t = time.time()
    sol = minimum_steps(read_pancakes())
    # print("Solved in", round(time.time() - t, 2), "seconds", file=sys.stderr)
    # print("", file=sys.stderr, flush=True)
    print(sol)


if __name__ == '__main__':
    main()
