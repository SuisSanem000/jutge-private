from itertools import permutations

for n in range(1, 9):
    L = range(1, n + 1)
    for p in permutations(L):
        print(*p)