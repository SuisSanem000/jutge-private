import itertools
import random


def print_list(L):
    print(' '.join([str(x) for x in L]))


def gen(n):
    print(n)
    l1 = list(range(n))
    l2 = list(range(n))
    random.shuffle(l1)
    random.shuffle(l2)
    print_list(l1)
    print_list(l2)


gen(750000)
