import random

c = 0


def tree():
    global c
    if (c <= 5 or random.random() < p) and c <= 100:
        c += 1
        return [c, tree(), tree()]
    else:
        return []


def pr(t):
    if len(t) == 0:
        print(-1, end=' ')
    else:
        print(t[0], end=' ')
        pr(t[1])
        pr(t[2])


def test():
    global c
    c = 0
    t = tree()
    pr(t)
    print()
    for i in range(c):
        print(' ', random.randint(1, c), random.randint(1, c))
    print(' -1 -1')
    print()


n = 100
p = 0.5
print(n)
print()
for i in range(n):
    test()
