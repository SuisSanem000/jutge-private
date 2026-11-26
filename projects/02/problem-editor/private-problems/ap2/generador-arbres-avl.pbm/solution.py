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


def all_avl_trees_of_height(h: int) -> Iterator[Tree]:
    if h == 0:
        yield None
    elif h == 1:
        yield Node(None, None)
    else:
        for hl, hr in [(h - 1, h - 1), (h - 2, h - 1), (h - 1, h - 2)]:
            for lf in all_avl_trees_of_height(hl):
                for rt in all_avl_trees_of_height(hr):
                    yield Node(lf, rt)


def main():
    for h in tokens(int):
        print(h)
        for s in sorted(map(toString, all_avl_trees_of_height(h))):
            print(s)


if __name__ == '__main__':
    main()
