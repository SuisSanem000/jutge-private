from yogi import read
from dataclasses import dataclass
from typing import Optional


@dataclass
class Estudiant:
    nom: str
    dni: int
    nota: float
    preferencies: list[str]
    assignacio: Optional[str]


def llegir_estudiant() -> Estudiant:
    return Estudiant(read(str), read(int), read(float), read(str).split(','), None)


def llegir_estudiants() -> list[Estudiant]:
    return [llegir_estudiant() for _ in range(read(int))]


@dataclass
class Titulacio:
    nom: str
    places: int
    nota_de_tall: float


def llegir_titulacio() -> Titulacio:
    return Titulacio(read(str), read(int), 0.0)


def llegir_titulacions() -> list[Titulacio]:
    return [llegir_titulacio() for _ in range(read(int))]


def assignar(estudiants: list[Estudiant], titulacions: list[Titulacio]) -> None:
    dic = {titulacio.nom: titulacio for titulacio in titulacions}
    estudiants.sort(key=lambda e: (-e.nota, e.dni))
    for estudiant in estudiants:
        for preferencia in estudiant.preferencies:
            titulacio = dic[preferencia]
            if titulacio.places > 0:
                estudiant.assignacio = preferencia
                titulacio.places -= 1
                titulacio.nota_de_tall = estudiant.nota
                break   # ben posat
    print('---')


def escriure_assignacio(estudiants: list[Estudiant]) -> None:
    estudiants.sort(key=lambda e: e.dni)
    for estudiant in estudiants:
        print(estudiant.dni, estudiant.nom, estudiant.assignacio)
    print('---')


def escriure_notes_de_tall(titulacions: list[Titulacio]) -> None:
    titulacions.sort(key=lambda e: (-e.nota_de_tall, e.nom))
    for titulacio in titulacions:
        print(titulacio.nom, titulacio.nota_de_tall, titulacio.places)


def main() -> None:
    estudiants = llegir_estudiants()
    titulacions = llegir_titulacions()
    assignar(estudiants, titulacions)
    escriure_assignacio(estudiants)
    escriure_notes_de_tall(titulacions)


if __name__ == '__main__':
    main()
