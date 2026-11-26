import fileinput

def partition(v: list[int], l: int, r: int) -> int:
    x = v[l]
    i = l - 1
    j = r + 1
    while True:
        j -= 1
        while x < v[j]:
            j -= 1
        i += 1
        while v[i] < x:
            i += 1
        if i >= j:
            return j
        v[i], v[j] = v[j], v[i]


def quicksel(v: list[int], l: int, r: int, k: int) -> int:
    if l == r:
        return v[l]
    else:
        q = partition(v, l, r)
        if k <= q:
            return quicksel(v, l, q, k)
        else:
            return quicksel(v, q + 1, r, k)


def mediana(v: list[int]) -> int:
    n = len(v)
    return quicksel(v, 0, n - 1, n // 2)



def mediana_lenta(v: list[int]) -> int:
    n = len(v)
    return sorted(v)[n // 2]


def main() -> None:
    for line in fileinput.input():
        lst = [int(x) for x in line.split()]
        # assert mediana(lst) == mediana_lenta(lst), lst
        print(mediana(lst))


if __name__ == '__main__':
    main()