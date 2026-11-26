from typing import Optional


def es_primer(n: int) -> bool:
    if n < 2:
        return False
    d = 2
    while d * d <= n:
        if n % d == 0:
            return False
        d = d + 1
    return True


def semiprimalitat(n: int) -> Optional[tuple[int, int]]:
    p = 2
    while p * p <= n:
        if n % p == 0 and es_primer(p) and es_primer(n // p):
            return p, n // p
        p = p + 1
    return None
