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


def inorder(t: BST) -> Iterator[int]:
    """Generates all elements of t in inorder (and, thus, in increasing order)."""

    if t is not None:
        yield from inorder(t.left)
        yield t.data
        yield from inorder(t.right)


def common_elements(t1: BST, t2: BST) -> Iterator[int]:
    """Generates all common elements of t1 and t2 in increasing order."""

    # solution based on the merge algorithm
    it1 = inorder(t1)
    it2 = inorder(t2)
    x1 = next(it1, None)
    x2 = next(it2, None)
    while x1 is not None and x2 is not None:
        if x1 < x2:
            x1 = next(it1, None)
        elif x1 > x2:
            x2 = next(it2, None)
        else:
            yield x1
            x1 = next(it1, None)
            x2 = next(it2, None)


def main():
    for _ in range(read(int)):
        print(*common_elements(read_tree(), read_tree()))


if __name__ == "__main__":
    main()
