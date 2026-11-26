from __future__ import annotations
from dataclasses import dataclass
from typing import Iterator
from yogi import read


@dataclass
class Node:
    data: int
    left: BST
    right: BST


BST = Node | None


def read_tree() -> BST:
    x = read(int)
    if x == -1:
        return None
    else:
        return Node(x, read_tree(), read_tree())


def common_elements(t1: BST, t2: BST) -> Iterator[int]:
    ...


def main():
    for _ in range(read(int)):
        print(*common_elements(read_tree(), read_tree()))


if __name__ == "__main__":
    main()
