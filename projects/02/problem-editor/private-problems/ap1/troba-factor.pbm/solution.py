from typing import Optional


def factor_mes_petit(n: int) -> Optional[int]:
    assert n >= 2
    d = 2
    while d * d <= n:
        if n % d == 0:
            return d
        d = d + 1
    return None
