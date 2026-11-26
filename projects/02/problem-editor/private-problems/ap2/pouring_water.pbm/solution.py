import sys
from typing import TypeAlias, Optional
from dataclasses import dataclass, field
from collections import deque
from yogi import read
import time


Containers: TypeAlias = tuple[int]


@dataclass
class State:
    containers: Containers
    pours: list[Containers]


def read_containers() -> tuple[Containers]:
    n = int(input())
    cap = tuple(read(int) for _ in range(n))
    init = tuple(read(int) for _ in range(n))
    obj = tuple(read(int) for _ in range(n))
    return (init, cap, obj)


def pour(containers: Containers, i: int, j: int, d: int):
    l = list(containers)
    l[i] -= d
    l[j] += d
    return tuple(l)


def minimum_steps(init: Containers, cap: Containers, obj: Containers) -> Optional[int]:
    """Returns the minimum number of steps to solve the pancakes, or None if impossible"""
    n = len(init)
    visited: set[Containers] = set()
    q: deque[State] = deque([State(init, [])])
    visited.add(init)
    while q:
        s = q.popleft()
        if all(obj[i] == -1 or s.containers[i] == obj[i] for i in range(n)):
            # print("Solution pours:", s.pours, file=sys.stderr)
            # print("Number of explored states:", len(visited), file=sys.stderr)
            return len(s.pours)
        for i in range(n):
            for j in range(n):
                d = min(cap[j]-s.containers[j], s.containers[i])
                if i != j and d > 0:  # pour from i to j
                    containers = pour(s.containers, i, j, d)
                    if containers not in visited:
                        pours = s.pours + [(i, j)]
                        q.append(State(containers, pours))
                        visited.add(containers)
    # print("Number of explored states:", len(visited), file=sys.stderr)
    return None


def main() -> None:
    # t = time.time()
    sol = minimum_steps(*read_containers())
    # print("Solved in", round(time.time() - t, 2), "seconds", file=sys.stderr)
    # print("", file=sys.stderr, flush=True)
    print(sol if sol is not None else -1)


if __name__ == '__main__':
    main()
