from yogi import read


def llegir():
    val = read(int)
    if val == -1:
        return None
    esq = llegir()
    dre = llegir()
    return (val, esq, dre)


def amplada(a):
    if a is None:
        return 0

    amp = 1
    L1 = [a]
    L2 = []
    while L1 != []:
        while L1 != []:
            p = L1.pop()
            if p[1] is not None:
                L2.append(p[1])
            if p[2] is not None:
                L2.append(p[2])
        amp = max(amp, len(L2))
        L1, L2 = L2, L1

    return amp


def main():
    m = read(int)

    for i in range(m):
        a = llegir()
        print(amplada(a))


main()
