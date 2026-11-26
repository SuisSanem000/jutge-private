from yogi import read


def llegir():
    val = read(int)
    if val == -1:
        return None
    esq = llegir()
    dre = llegir()
    return (val, esq, dre)


def prof(a):
    if a is None:
        return 0
    else:
        return 1 + max(prof(a[1]), prof(a[2]))


def main():
    m = read(int)

    for i in range(m):
        a = llegir()
        print(prof(a))


main()
