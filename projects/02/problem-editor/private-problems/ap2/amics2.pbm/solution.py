from yogi import *


def main()->None:

    n, m = read(int), read(int)
    members = [read(str) for _ in range(n)]
    friends = { p : set[str]() for p in members }
    for _ in range(m):
        x, y = read(str), read(str)
        friends[x].add(y)
        friends[y].add(x)
    for u in tokens(str):
        s = friends[u].copy()
        for x in friends[u]:
            s |= friends[x]
        s.discard(u)
        print(len(s))


if __name__ == "__main__":
    main()
