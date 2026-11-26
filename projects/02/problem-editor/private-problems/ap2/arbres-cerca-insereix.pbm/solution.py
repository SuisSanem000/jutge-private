from yogi import scan


def insereix(abc, x):
    if abc is None:
        return (x, None, None)
    elif abc[0] == x:
        return abc
    elif x < abc[0]:
        return (abc[0], insereix(abc[1], x), abc[2])
    else:
        return (abc[0], abc[1], insereix(abc[2], x))


def preordre(a):
    if a is not None:
        print(a[0])
        preordre(a[1])
        preordre(a[2])


def main():
    abc = None
    x = scan(int)
    while x is not None:
        abc = insereix(abc, x)
        x = scan(int)
    preordre(abc)


main()
