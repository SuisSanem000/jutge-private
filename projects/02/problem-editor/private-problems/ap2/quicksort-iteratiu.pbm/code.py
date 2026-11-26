import fileinput


def quicksort(array: list[str]) -> None:
    quicksort_rec(array, 0, len(array) - 1)


def quicksort_rec(array: list[str], left: int, right: int) -> None:
    if left < right:
        mid = partition(array, left, right)
        quicksort_rec(array, left, mid)
        quicksort_rec(array, mid + 1, right)


def partition(array: list[str], left: int, right: int) -> int:
    pivot = array[left]
    i, j = left - 1, right + 1
    while True:
        while True:
            i += 1
            if array[i] >= pivot: break
        while True:
            j -= 1
            if array[j] <= pivot: break
        if i >= j:
            return j
        array[i], array[j] = array[j], array[i]


def main() -> None:
    for line in fileinput.input():
        array = line.strip().split()
        quicksort(array)
        print(*array)


if __name__ == "__main__":
    main()
