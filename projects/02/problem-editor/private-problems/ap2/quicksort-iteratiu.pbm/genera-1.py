import itertools
for n in range(9):
    for l in list(itertools.permutations(list(range(n)))):
        print(*l)