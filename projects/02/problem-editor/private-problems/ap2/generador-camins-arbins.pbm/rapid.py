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


def _preordre(arbre: Arbre, cami_actual: list[int]) -> Iterator[list[int]]:
    """
    Genera tots els camins des de l'arrel fins a les fulles de l'arbre en preordre
    sabent que el recorregut de l'arbre original és a camí_actual.
    """
    if arbre is not None:
        cami_actual.append(arbre.x)
        if arbre.fe is None and arbre.fd is None:
            yield cami_actual.copy()  # el .copy és per seguretat ja que la llista és mutable
        else:
            if arbre.fe is not None:
                yield from _preordre(arbre.fe, cami_actual)
            if arbre.fd is not None:
                yield from _preordre(arbre.fd, cami_actual)
        cami_actual.pop()


def genera_camins(arbre: Arbre) -> Iterator[list[int]]:
    """Genera tots els camins des de l'arrel fins a les fulles."""
    yield from _preordre(arbre, [])


def llegir_arbre() -> Arbre:
    """Llegeix un arbre en preordre."""
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
