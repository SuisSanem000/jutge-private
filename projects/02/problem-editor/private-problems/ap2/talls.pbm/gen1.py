import itertools


for n in range(1, 6):
    for combination in itertools.combinations(range(1, n+4), n):
        for permutation in itertools.permutations(combination):
            for m in range(1, n+1):
                print(m, n, " ", " ".join(map(str, permutation)))
