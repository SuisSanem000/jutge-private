import yogi
from typing import TypeAlias, Optional
from dataclasses import dataclass

@dataclass
class Node:
    color: str
    esq: "Arbre"
    dre: "Arbre"

Arbre: TypeAlias = Optional[Node]

def llegir_arbre(entrada: str) -> Arbre:
    """Construeix un arbre a partir del seu recorregut en preordre."""
    it = iter(entrada)

    def llegir() -> Arbre:
        color = next(it)
        if color == "-":
            return None
        return Node(color, llegir(), llegir())

    return llegir()

def es_verd_blau(arbre: Arbre) -> tuple[bool, int]:
    """Comprova si l'arbre és verd-blau i retorna la seva alçada blava."""
    if arbre is None:
        return True, 0
    if arbre.color == "G":
        if arbre.esq is not None and arbre.esq.color == "G":
            return False, 0
        if arbre.dre is not None and arbre.dre.color == "G":
            return False, 0
    esq_ok, esq_blaus = es_verd_blau(arbre.esq)
    if not esq_ok:
        return False, 0
    dre_ok, dre_blaus = es_verd_blau(arbre.dre)
    if not dre_ok:
        return False, 0
    if esq_blaus != dre_blaus:
        return False, 0
    return True, esq_blaus + (arbre.color == "B")

def main() -> None:
    n = yogi.read(int)
    for entrada in yogi.tokens(str):
        arbre = llegir_arbre(entrada)
        valid, alcada = es_verd_blau(arbre)
        if valid:
            print(alcada)
        else:
            print("no")

if __name__ == "__main__":
    main()

