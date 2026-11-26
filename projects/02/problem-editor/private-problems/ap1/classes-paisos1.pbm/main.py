from yogi import *


def jutge_main() -> None:
    n = read(int)
    paisos: Paisos = []
    for _ in range(n):
        nom = read(str)
        capital = read(str)
        np = read(int)
        provincies = [Provincia(read(str), read(str), read(
            int), read(int), read(float)) for _ in range(np)]
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
