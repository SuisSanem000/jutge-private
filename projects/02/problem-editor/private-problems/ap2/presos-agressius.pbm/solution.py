from yogi import read, tokens


def can_place(sorted_prison_cells: list[int], prisoners: int, dist: int) -> bool:
    """Check if it is possible to place prisoners with at least distance dist."""
    
    count = 1
    last_position = sorted_prison_cells[0]

    for i in range(1, len(sorted_prison_cells)):
        position = sorted_prison_cells[i]
        if position - last_position >= dist:
            count += 1
            last_position = position
            if count == prisoners:
                return True
    return False


def max_min_distance(prison_cells: list[int], prisoners: int) -> int:
    """Find the maximum minimum distance for placing prisoners in cells."""

    sorted_prison_cells = sorted(prison_cells)
    left = 0
    right = sorted_prison_cells[-1] - sorted_prison_cells[0]
    result = 0

    while left <= right:
        mid = (left + right) // 2
        if can_place(sorted_prison_cells, prisoners, mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1

    return result


def main() -> None:
    for N in tokens(int):
        K = read(int)
        prison_cells = [read(int) for _ in range(N)]
        print(max_min_distance(prison_cells, K))


if __name__ == "__main__":
    main()
