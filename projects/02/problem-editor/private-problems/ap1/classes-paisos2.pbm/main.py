from yogi import *


def jutge_main() -> None:
    n = read(int)
    paisos: list[Pais] = []
    for _ in range(n):
        nom = read(str)
        capital = read(str)
        np = read(int)
        provincies = [Provincia(read(str), read(str), read(
            int), read(int), read(float)) for _ in range(np)]
        paisos.append(Pais(nom, capital, provincies))

    for x in range(0, 5000, 100):
        print(habitants(paisos, x))


jutge_main()
