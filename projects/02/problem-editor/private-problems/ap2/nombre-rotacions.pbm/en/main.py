from yogi import *


def main():
    typ = read(str)
    if typ == "explicit":
        for n in tokens(int):
            v = [read(int) for i in range(n)]
            print(number_of_rotations(v))
    elif typ == "implicit":
        for n in tokens(int):
            r, t = read(int), read(int)
            v = [(i - r + n + n) % n for i in range(n)]
            s = 0
            for i in range(t):
                s = (s + number_of_rotations(v)) % 784536
            print(s)


main()
