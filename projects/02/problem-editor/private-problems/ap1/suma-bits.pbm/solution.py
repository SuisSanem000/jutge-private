import yogi


def sequencies(bits: list[int], dif: int, esq: int, dre: int) -> None:
    """
    Escriu totes les seqüències de 2n = len(bits) bits havent fixat les posicions
    0 .. esq - 1 i dre + 1 .. 2n-1 i sabent que dif és la diferència entre la suma
    dels bits d'aquestes dues parts.
    """

    if esq > dre:
        if dif == 0:
            print(*bits)
    elif abs(dif) <= (dre - esq + 1) // 2:
        for vesq in [0, 1]:
            for vdre in [0, 1]:
                bits[esq], bits[dre] = vesq, vdre
                sequencies(bits, dif + vesq - vdre, esq + 1, dre - 1)


def main():
    n = yogi.read(int)
    bits = [0 for _ in range(2*n)]
    sequencies(bits, 0, 0, 2*n-1)


main()
