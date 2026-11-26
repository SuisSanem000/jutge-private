from yogi import *


def tuti(paraula: str, objectiu: str) -> bool:
    for lletra in objectiu:
        if lletra not in paraula:
            return False
    return True


def punts(paraula: str, objectiu: str) -> int:
    if len(paraula) < 3 or objectiu[0] not in paraula:
        return 0
    for lletra in paraula:
        if lletra not in objectiu:
            return 0
    if len(paraula) == 3:
        return 1
    elif len(paraula) == 4:
        return 2
    elif tuti(paraula, objectiu):
        return 10 + len(paraula)
    else:
        return len(paraula)


def main() -> None:

    trobades: list[str] = []
    puntuacio = 0
    objectiu = read(str)
    paraula = scan(str)
    while paraula is not None:
        p = punts(paraula, objectiu)
        if p > 0:
            trobades.append(paraula)
            puntuacio += p
        paraula = scan(str)
    for paraula in sorted(trobades):
        print(paraula)
    print('-----')
    print(puntuacio)


main()
