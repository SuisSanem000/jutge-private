from yogi import read, tokens
from typing_extensions import TypeAlias

Frequences: TypeAlias = list[list[int]]


def get_frequences(m: int, n: int) -> Frequences:
    D = 10
    f: Frequences = [ [0 for _ in range(n)] for _ in range(D)]
    for _ in range(m):
        for j in range(n):
            x = read(int)
            f[x][j] += 1
    return f


def show(frec: Frequences) -> None:
    for row in frec:
        print(*row)
    print()


def main() -> None:
    for m in tokens(int):
        n = read(int)
        show(get_frequences(m, n))


if __name__ == "__main__":
    main()