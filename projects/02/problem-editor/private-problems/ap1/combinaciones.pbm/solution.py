from yogi import read, tokens
from typing import Optional
from typing_extensions import TypeAlias

Llista: TypeAlias = list[Optional[int]]

def make_combinations(lst: Llista, i: int, n: int, k: int) -> None:
    '''
    Writes in ascending order all the combinations of size len(lst) formed by the
    n first even numbers s.t. their sum is less than or equal to k
    '''
    if i == len(lst):
        print(*lst)
    else:
        for j in range(n):
            k_prime = k - (2*j + 1)
            if  k_prime >= 0:  # if k_prime - (len(lst) - (i + 1)) >= 0: # lookahead
                lst[i] = 2*j + 1
                make_combinations(lst, i + 1, n, k_prime)

def main() -> None:
    for p in tokens(int):
        n, k = read(int), read(int)
        lst = [None for _ in range(p)]
        make_combinations(lst, 0, n, k)
        print('-' * (2*p - 1))

if __name__ == "__main__":
    main()