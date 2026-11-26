
def number_of_rotations(v: list[int]) -> int:
    n = len(v)
    j = 1
    while j < n:
        j *= 2
    i = 0
    while j > 0:
        if i+j < n and v[i+j] > v[0]:
            i += j
        j //= 2
    return (i + 1) % n
