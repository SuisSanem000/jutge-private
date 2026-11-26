import fileinput


def quicksort(array: list[str]) -> None:
    stack = list[tuple[int, int]]()
    stack.append((0, len(array) - 1))
    while stack:
        left, right = stack.pop()
        if left < right:
            mid = partition(array, left, right)
            stack.append((left, mid))
            stack.append((mid + 1, right))


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
