

def leftmost_lt_first(v: list[int], l: int, r: int) -> int:
    if l == r:
        return l
    m = (l + r)//2
    if v[m] < v[0]:
        return leftmost_lt_first(v, l, m)
    else:
        return leftmost_lt_first(v, m+1, r)


def number_of_rotations(v: list[int]) -> int:
    n = len(v)
    if v[0] <= v[n-1]:
        return 0  # no rotation
    return leftmost_lt_first(v, 0, n-1)
