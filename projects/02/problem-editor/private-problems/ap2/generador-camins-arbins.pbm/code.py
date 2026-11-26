from __future__ import annotations
from dataclasses import dataclass
from typing import Iterator
from yogi import read


@dataclass
class Node:
    x: int
    fe: Arbre
    fd: Arbre


Arbre = Node | None


def genera_camins(arbre: Arbre) -> Iterator[list[int]]: ...


def llegir_arbre() -> Arbre:
    x = read(int)
    if x == -1:
        return None
    return Node(x, llegir_arbre(), llegir_arbre())


def main() -> None:
    arbre = llegir_arbre()
    for cami in genera_camins(arbre):
        print(*cami)


if __name__ == "__main__":
    main()
