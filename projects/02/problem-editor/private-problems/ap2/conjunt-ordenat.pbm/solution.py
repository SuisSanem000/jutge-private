from __future__ import annotations
import yogi
from dataclasses import dataclass
from typing import Iterator, TypeAlias


@dataclass
class _Node:
    x: int
    fe: _ABC
    fd: _ABC


_ABC: TypeAlias = _Node | None  # arbre binari de cerca


class ConjuntOrdenat:

    _arrel: _ABC
    _nombre: int

    def __init__(self):
        """Crea un conjunt ordenat buit."""
        self._arrel = None
        self._nombre = 0

    def inserir(self, x: int) -> None:
        """Insereix l'element x al conjunt."""
        self._arrel = self._inserir(self._arrel, x)

    def conte(self, x: int) -> bool:
        """Retorna True si l'element x conte al conjunt, False en cas contrari."""
        return self._conte(self._arrel, x)

    def esborrar(self, x: int) -> None:
        """Esborra l'element x del conjunt."""
        self._arrel = self._esborrar(self._arrel, x)

    def entre(self, x: int, y: int) -> Iterator[int]:
        """Retorna un iterador per a iterar sobre els elements del conjunt que estan entre x i y en ordre creixent."""
        return self._entre(self._arrel, x, y)

    def __len__(self) -> int:
        """Retorna el nombre d'elements del conjunt."""
        return self._nombre

    def _inserir(self, arbre: _ABC, x: int) -> _ABC:
        if arbre is None:
            self._nombre += 1
            return _Node(x, None, None)
        elif x < arbre.x:
            arbre.fe = self._inserir(arbre.fe, x)
        elif x > arbre.x:
            arbre.fd = self._inserir(arbre.fd, x)
        return arbre

    def _conte(self, arbre: _ABC, x: int) -> bool:
        if arbre is None:
            return False
        elif x < arbre.x:
            return self._conte(arbre.fe, x)
        elif x > arbre.x:
            return self._conte(arbre.fd, x)
        else:
            return True

    def _esborrar(self, arbre: _ABC, x: int) -> _ABC:
        if arbre is None:
            return None
        elif x < arbre.x:
            arbre.fe = self._esborrar(arbre.fe, x)
        elif x > arbre.x:
            arbre.fd = self._esborrar(arbre.fd, x)
        else:
            if arbre.fe is None:
                self._nombre -= 1
                return arbre.fd
            elif arbre.fd is None:
                self._nombre -= 1
                return arbre.fe
            else:
                min_dret = self._valor_node_minim(arbre.fd)
                arbre.x = min_dret.x
                arbre.fd = self._esborrar(arbre.fd, min_dret.x)
        return arbre

    def _valor_node_minim(self, arbre: _Node) -> _Node:
        while arbre.fe is not None:
            arbre = arbre.fe
        return arbre

    def _entre(self, arbre: _ABC, x: int, y: int) -> Iterator[int]:
        if arbre is not None:
            if arbre.x > x:
                yield from self._entre(arbre.fe, x, y)
            if x <= arbre.x <= y:
                yield arbre.x
            if arbre.x < y:
                yield from self._entre(arbre.fd, x, y)


def main() -> None:
    conjunt = ConjuntOrdenat()
    for comanda in yogi.tokens(str):
        if comanda == "inserir":
            conjunt.inserir(yogi.read(int))
        elif comanda == "conte":
            print(conjunt.conte(yogi.read(int)))
        elif comanda == "esborrar":
            conjunt.esborrar(yogi.read(int))
        elif comanda == "entre":
            print(*list(conjunt.entre(yogi.read(int), yogi.read(int))), sep=", ")
        elif comanda == "mida":
            print(len(conjunt))


if __name__ == "__main__":
    main()
