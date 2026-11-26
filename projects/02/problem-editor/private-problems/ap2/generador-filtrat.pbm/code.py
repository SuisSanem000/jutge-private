from typing import Iterable, Iterator
from yogi import read, tokens


def filtre(paraules: Iterable[str], k: int) -> Iterator[str]: ...


def main() -> None:
    k = read(int)
    print(*filtre(tokens(str), k))


main()
