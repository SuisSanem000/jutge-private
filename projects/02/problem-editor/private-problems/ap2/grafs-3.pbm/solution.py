import yogi
from yogi import read


def busca(mapa, vist, n, m, f, c):
    if f < 0 or f >= n or c < 0 or c >= m or vist[f][c]:
        return False
    vist[f][c] = True
    if mapa[f][c] == 't':
        return True
    if mapa[f][c] == 'X':
        return False
    return busca(mapa, vist, n, m, f + 1, c) or busca(mapa, vist, n, m, f - 1, c) or busca(mapa, vist, n, m, f, c + 1) or busca(mapa, vist, n, m, f, c - 1)


def main():
    n = read(int)
    m = read(int)
    mapa = [None] * n
    vist = [None] * n
    for i in range(n):
        mapa[i] = read(str)
        vist[i] = [False] * m
    f = read(int)
    c = read(int)
    print("yes" if busca(mapa, vist, n, m, f-1, c-1) else "no")


main()
