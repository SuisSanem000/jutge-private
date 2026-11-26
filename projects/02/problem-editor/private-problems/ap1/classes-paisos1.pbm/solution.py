from dataclasses import dataclass
from typing import TypeAlias


@dataclass
class Provincia:
    nom: str
    capital: str
    habitants: int
    area: int
    pib: float


@dataclass
class Pais:
    nom: str
    capital: str
    provincies: list[Provincia]


Paisos: TypeAlias = list[Pais]


def pib(paisos: Paisos, inicial: str, densitat: float) -> float:
    s = 0.0
    for pais in paisos:
        if pais.nom[0] == inicial:
            for provincia in pais.provincies:
                if provincia.habitants / provincia.area > densitat:
                    s += provincia.pib
    return s
