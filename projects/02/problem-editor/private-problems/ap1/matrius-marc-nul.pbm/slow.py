import yogi


def marc_nul(M: list[list[int]]) -> bool:
    """Indica si la matriu M té un marc nul o no."""

    m, n = len(M), len(M[0])
    for i in range(m):
        for j in range(n):
            s = sum(sum(M[p][q] for q in range(j+1)) for p in range(i+1))
            if s == 0:
                print(i, j)
                return True
    return False


def z(S: list[list[int]], i: int, j: int) -> bool:
    """Retorna S[i][j] però retorna 0 quan i o j són negatius."""

    if i < 0 or j < 0:
        return 0
    return S[i][j]


def main():
    m, n = yogi.read(int), yogi.read(int)
    M = [[yogi.read(int) for _ in range(n)] for _ in range(m)]
    print(marc_nul(M))


main()
