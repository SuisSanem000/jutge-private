
def cartesian_product(a: set[int], b: set[int]) -> set[tuple[int, int]]:
    s: set[tuple[int, int]] = set()
    for x in a:
        for y in b:
            s.add((x, y))
    return s
