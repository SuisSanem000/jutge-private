import fileinput


def median(v: list[int]) -> int:
    # correct but too slow
    n = len(v)
    return sorted(v)[n // 2]


def main() -> None:
    for line in fileinput.input():
        print(median([int(x) for x in line.split()]))


if __name__ == '__main__':
    main()
