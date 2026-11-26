from typing import Iterable, Iterator
from yogi import read, tokens


def filtre(paraules: Iterable[str], k: int) -> Iterator[str]:
    """
    Per cada cadena s, cada cop que s'ha vist k vegades seguides (des de l'últim yield),
    genera s i reinicia el comptador de s.
    """
    comptadors: dict[str, int] = {}
    for paraula in paraules:
        comptadors[paraula] = comptadors.get(paraula, 0) + 1
        if comptadors[paraula] == k:
            yield paraula
            comptadors[paraula] = 0


def main() -> None:
    k = read(int)
    print(*filtre(tokens(str), k))


main()
