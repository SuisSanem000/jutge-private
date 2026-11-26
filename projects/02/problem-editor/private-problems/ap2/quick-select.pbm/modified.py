from yogi import read  # type: ignore
from typing import List


# Hoare’s partition.
# Partitions v[l..r] into v[l..q,q+1..r] where q is the returned value
# so that all elements in v[l..q] are smaller or equal than all elements in v[q+1..r].
def partition(v: List[int], l: int, r: int) -> int:
    x = v[l]
    i = l - 1
    j = r + 1
    while True:
        while x < v[(j := j-1)]:
            pass
        while v[(i := i+1)] < x:
            pass
        if i >= j:
            return j
        v[i], v[j] = v[j], v[i]


# Sorts v[l..r] using quick sort.
def quicksort(v: List[int], l: int, r: int) -> None:
    if l < r:
        q = partition(v, l, r)
        quicksort(v, l, q)
        quicksort(v, q + 1, r)


def range_sum(v: List[int], l: int, r: int) -> int:
    s = 0
    for i in range(l, r+1):
        s += v[i]
    return s


def sum_smallest_rec(v: List[int], k: int, l: int, r: int) -> int:
    if k == 0:
        return 0
    q = partition(v, l, r)
    if q-l+1 <= k:
        return range_sum(v, l, q) + sum_smallest_rec(v, k-(q-l+1), q+1, r)
    else:
        return sum_smallest_rec(v, k, l, q)


# Returns the sum of the k smallest elements of v.
def sum_smallest(v: List[int], k: int) -> int:
    n = len(v)
    assert k >= 0 and k <= n
    return sum_smallest_rec(v, k, 0, n-1)


# Just a test
def main() -> None:
    v = [4, 91929, 2, 4, 1]
    k = 3
    print(sum_smallest(v, k))


main()
