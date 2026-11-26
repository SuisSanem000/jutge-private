from yogi import read


def llegir():
    val = read(str)
    if val == "-1":
        return None
    esq = llegir()
    dre = llegir()
    return (val, esq, dre)


def escriure(a, c=0):
    if a is not None:
        escriure(a[2], c+10)
        s = c + 10 - len(a[0])
        print(" " * s, end='')
        print(a[0])
        escriure(a[1], c+10)


def main():
    escriure(llegir())


main()
