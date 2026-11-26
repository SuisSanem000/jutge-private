import itertools


def print_list(L):
    print(' '.join([str(x) for x in L]))


def gen(n):
    ps1 = list(itertools.permutations(range(n)))
    ps2 = list(itertools.permutations(range(n)))
    for p1 in ps1:
        for p2 in ps2:
            print(n)
            print_list(p1)
            print_list(p2)


for n in range(6):
    gen(n)
