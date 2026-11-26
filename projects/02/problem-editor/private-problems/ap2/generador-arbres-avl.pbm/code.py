from __future__ import annotations
from typing import Optional, Iterator, TypeAlias
from dataclasses import dataclass
from yogi import tokens


@dataclass
class Node:
    lf: Tree
    rt: Tree


Tree: TypeAlias = Optional[Node]


def toString(t: Tree) -> str:
    if t is None:
        return "-"
    return f"({toString(t.lf)}{toString(t.rt)})"


def all_trees_of_size(n: int) -> Iterator[Tree]:
    if n == 0:
        yield None
    else:
        for i in range(n):
            for lf in all_trees_of_size(i):
                for rt in all_trees_of_size(n - i - 1):
                    yield Node(lf, rt)


def all_avl_trees_of_height(h: int) -> Iterator[Tree]:
    ...


def main():
    for h in tokens(int):
        print(h)
        for s in sorted(map(toString, all_avl_trees_of_height(h))):
            print(s)


if __name__ == '__main__':
    main()
