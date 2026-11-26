import random

t = 100
for i in range(t):
    n = random.randint(2, 10000)
    x = random.randint(1, n)
    L: list[int] = []
    for i in range(1, n+1):
        if i != x:
            for _ in range(random.randint(1, 4)):
                L.append(i)
    random.shuffle(L)
    print(n, len(L), ' '.join(map(str, L)))
