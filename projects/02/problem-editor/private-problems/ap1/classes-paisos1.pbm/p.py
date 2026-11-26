from yogi import *
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
    provs: list[Provincia]


Paisos: TypeAlias = list[Pais]


def pib(paisos: Paisos, inicial: str, densitat: float) -> float:
    s = 0.0
    for pais in paisos:
        if pais.nom[0] == inicial:
            for provincia in pais.provs:
                if provincia.habitants / provincia.area > densitat:
                    s += provincia.pib
    return s


def jutge_main():
    n = read(int)
    paisos: Paisos = []
    for _ in range(n):
        nom = read(str)
        capital = read(str)
        np = read(int)

        provincies = []
        for _ in range(np):
            nom = read(str)
            capital = read(str)
            habitants = read(int)
            area = read(float)
            pib = read(float)
            provincies.append(Provincia(nom, capital, habitants, area, pib))
        paisos.append(Pais(nom, capital, provincies))

    print(pib(paisos, 'A', 10))
    print(pib(paisos, 'A', 20))
    print(pib(paisos, 'A', 30))
    print(pib(paisos, 'A', 40))
    print(pib(paisos, 'E', 10))
    print(pib(paisos, 'E', 20))
    print(pib(paisos, 'E', 30))
    print(pib(paisos, 'E', 40))
    print(pib(paisos, 'C', 40))


jutge_main()
