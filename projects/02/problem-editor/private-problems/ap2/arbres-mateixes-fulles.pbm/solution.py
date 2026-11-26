from __future__ import annotations
from dataclasses import dataclass
from typing import Iterator
from itertools import zip_longest
from yogi import read


@dataclass
class Node:
    data: int
    left: BinTree
    right: BinTree


BinTree = Node | None


def read_tree() -> BinTree:
    x = read(int)
    if x == -1:
        return None
    else:
        return Node(x, read_tree(), read_tree())


def leaves(t: BinTree) -> Iterator[int]:
    """Generates the leaves of t from left to right."""
    # time: always O(n) where n is the size (number of nodes) of t.

    if t is not None:
        if t.left is None and t.right is None:
            yield t.data
        else:
            yield from leaves(t.left)
            yield from leaves(t.right)


def same_leaves(t1: BinTree, t2: BinTree) -> bool:
    """Tells if two trees have the same leaves from left to right."""
    # time in the worst case: O(min(n1,n2)) where n1 and n2 are the size (number of nodes) of t1 and t2.
    # time in the best case: O(1).

    leaves1 = leaves(t1)
    leaves2 = leaves(t2)
    return all(x == y for x, y in zip_longest(leaves1, leaves2))


def main():
    for _ in range(read(int)):
        t1, t2 = read_tree(), read_tree()
        print(*leaves(t1), ",", *leaves(t2), ",", same_leaves(t1, t2))


if __name__ == "__main__":
    main()
