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


def habitants(paisos: Paisos, x: float) -> int:
    s = 0
    for pais in paisos:
        c = 0
        for provincia in pais.provincies:
            if provincia.pib <= x:
                c += 1
                if c == 2:
                    break
        if c == 2:
            for provincia in pais.provincies:
                s += provincia.habitants
    return s
