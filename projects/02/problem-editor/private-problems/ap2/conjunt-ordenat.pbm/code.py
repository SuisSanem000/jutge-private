from __future__ import annotations
from typing import Iterator
import yogi


class ConjuntOrdenat:

    ...

    def __init__(self): ...

    def inserir(self, x: int) -> None: ...

    def conte(self, x: int) -> bool: ...

    def esborrar(self, x: int) -> None: ...

    def entre(self, x: int, y: int) -> Iterator[int]: ...

    def __len__(self) -> int: ...


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
