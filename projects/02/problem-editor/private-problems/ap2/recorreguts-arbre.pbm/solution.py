from yogi import read


def llegir():
    val = read(int)
    if val == -1:
        return None
    esq = llegir()
    dre = llegir()
    return (val, esq, dre)


def postordre(a):
    if a is not None:
        postordre(a[1])
        postordre(a[2])
        print(" ", a[0], end='', sep='')


def inordre(a):
    if a is not None:
        inordre(a[1])
        print(" ", a[0], end='', sep='')
        inordre(a[2])


def main():
    a = llegir()

    print("pos:", end='')
    postordre(a)
    print()

    print("ino:", end='')
    inordre(a)
    print()


main()
