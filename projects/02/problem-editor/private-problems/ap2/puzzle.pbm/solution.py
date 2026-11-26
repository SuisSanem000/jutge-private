# comprovar amb https://deniz.co/8-puzzle-solver/

from typing import TypeAlias, Optional
from dataclasses import dataclass, field
import heapq
from yogi import read


Puzzle: TypeAlias = list[int]


@dataclass(order=True)
class State:
    f: int
    g: int = field(compare=False)  # aquest no deu caler guardar-lo
    h: int
    puzzle: Puzzle = field(compare=False)


def read_puzzle() -> Puzzle:
    return [read(int) for _ in range(9)]


def hscore(p: Puzzle) -> int:
    """number of misplaced tiles by comparing the current state and the goal state"""
    return sum(1 for i, x in enumerate(p) if x != i + 1)


def solved(p: Puzzle) -> bool:
    return p == [1, 2, 3, 4, 5, 6, 7, 8, 0]


# per cada posició del forat, quins índexos cal intercanviar amb ell
SWAPS = [
    [1, 3],
    [0, 2, 4],
    [1, 5],
    [0, 4, 6],
    [1, 3, 5, 7],
    [2, 4, 8],
    [3, 7],
    [4, 6, 8],
    [5, 7],
]


def apply_swap(p: Puzzle, i: int, j: int) -> Puzzle:
    c = p[:]
    c[i], c[j] = c[j], c[i]
    return c


def neighbors(p: Puzzle) -> list[Puzzle]:
    pos0 = p.index(0)
    return [apply_swap(p, pos0, index) for index in SWAPS[pos0]]


def minimum_steps(p: Puzzle) -> Optional[int]:
    """Returns the minimum number of steps to solve the puzzle, or None if impossible"""

    # el set hauria de ser de Puzzles però les llistes són mutables per tant en deso les seves tuples
    visited: set[tuple[int]] = set()
    h = hscore(p)
    q: list[State] = [State(h, 0, h, p)]
    while q:
        s = heapq.heappop(q)
        if solved(s.puzzle):
            # print(len(visited))
            return s.g
        for c in neighbors(s.puzzle):
            tc = tuple(c)
            if tc not in visited:
                h = hscore(c)
                heapq.heappush(q, State(s.g + 1 + h, s.g + 1, h, c))
                visited.add(tc)
    return None


def main() -> None:
    print(minimum_steps(read_puzzle()))


if __name__ == '__main__':
    main()
