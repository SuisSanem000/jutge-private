import yogi


def marc_nul(M: list[list[int]]) -> bool:
    """Indica si la matriu M té un marc nul o no."""

    # L'algorisme consisteix en calcular una matriu S tal que
    # S[i,j] és el marc de (i,j) usant el principi d'inclusió/exclusió.
    # Si es troba algun S[i,j] == 0, ja se sap que hi ha un marc nul
    # i ja es pot indicar (cerca).

    m, n = len(M), len(M[0])
    S = [[M[i][j] for j in range(n)] for i in range(m)]
    for i in range(m):
        for j in range(n):
            S[i][j] += z(S, i, j - 1) + z(S, i - 1, j) - z(S, i - 1, j - 1)
            if S[i][j] == 0:
                return True
    return False


def z(S: list[list[int]], i: int, j: int) -> int:
    """Retorna S[i][j] però retorna 0 quan i o j són negatius."""

    if i < 0 or j < 0:
        return 0
    return S[i][j]


def main():
    m, n = yogi.read(int), yogi.read(int)
    M = [[yogi.read(int) for _ in range(n)] for _ in range(m)]
    print(marc_nul(M))


main()
