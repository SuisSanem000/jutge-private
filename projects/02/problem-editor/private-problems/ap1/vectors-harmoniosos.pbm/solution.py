import yogi
import sys

# compta tots els vectors harmoniosos de n bits
# en el vector v, de llargada n, sabent que les seves
# i primeres posicions estan fixades i que en aquelles
# posicions hi ha zeros 0s uns 1s.


def comptar(n, d, v, i, zeros, uns):
    if i == n:
        print(v, file=sys.stderr)
        return 1
    else:
        c = 0
        if abs(uns - (zeros + 1)) <= d:
            v[i] = 0
            c += comptar(n, d, v, i + 1, zeros + 1, uns)
        if abs((uns + 1) - zeros) <= d:
            v[i] = 1
            c += comptar(n, d, v, i + 1, zeros, uns + 1)
        return c


def main():
    n, d = yogi.scan(int), yogi.scan(int)
    while n is not None and d is not None:
        v = [None] * n
        print(comptar(n, d, v, 0, 0, 0))
        n, d = yogi.scan(int), yogi.scan(int)


main()
