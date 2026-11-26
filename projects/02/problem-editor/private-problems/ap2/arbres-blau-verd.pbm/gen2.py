import random


def tree(h, c):
    if h == 0:
        return '-'
    else:
        s = tree(h - 1, 'B' if c == 'G' else 'G')
        return c + s + s


def main():
    H = 20
    print(H)
    for h in range(H):
        t = tree(h, 'B')
        print(t)


main()

# do not forget to add number of lines at the beginning of the output
