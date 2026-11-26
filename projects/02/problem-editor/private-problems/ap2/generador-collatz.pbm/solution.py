from yogi import read, tokens

from typing import Iterator


def collatz_next(n: int) -> int:
    if n % 2 == 0:
        return n // 2
    else:
        return n * 3 + 1


def collatz(n: int) -> Iterator[int]:
    """Generates the Collatz sequence starting at n (n≥1)."""

    yield n
    while n != 1:
        n = collatz_next(n)
        yield n


def collatz_length(n: int) -> int:
    """Returns the length of the Collatz sequence starting at n (n≥1)."""

    return sum(1 for _ in collatz(n))


def collatz_highest(n: int) -> int:
    """Returns the highest value of the Collatz sequence starting at n (n≥1)."""

    return max(collatz(n))


def collatz_highest_position(n: int) -> tuple[int, int]:
    """Returns the position (starting from 0) of the highest value of the Collatz sequence starting at n (n≥1)."""

    return max(enumerate(collatz(n)), key=lambda x: x[1])


def collatz_11(n: int) -> bool:
    """Tells if S(n)[1:] contains some multiple of 11. """

    return any(x % 11 == 0 for x in collatz(collatz_next(n)))


def collatz_first_common(n1: int, n2: int) -> int:
    """Returns the first common elements of the Collatz sequences starting at n1 and n2 (n1, n2≥1)."""

    s1 = set(collatz(n1))
    for x in collatz(n2):
        if x in s1:
            return x
    assert False


def collatz_common_elements(n1: int, n2: int) -> int:
    """Returns the number of common elements in the Collatz sequences starting at n1 and n2 (n1, n2≥1)."""

    return collatz_length(collatz_first_common(n1, n2))


def collatz_union(n1: int, n2: int) -> list[int]:
    """Returns the list (in increasing order but no repetitions) of all elements of the Collatz sequences starting at n1 and n2 (n1, n2≥1)."""

    return sorted(set(collatz(n1)) | set(collatz(n2)))


def collatz_top_numbers() -> Iterator[int]:
    """
    Generates the infinite list of starting values whose maximum trajectory point is greater than that of any smaller starting value (sequence A006884): 1, 2, 3, 7, 15, 27, 255, 447, 639, 703, 1819, 4255, 4591, 9663,...
    """

    i, highest = 1, 0
    while True:
        h = collatz_highest(i)
        if h > highest:
            yield i
            highest = h
        i += 1


def collatz_first_missing(n: int) -> int:
    """
    Return the first missing natural > 0 in S(n).
    """

    s = set(collatz(n))
    i = 2
    while i in s:
        i += 1
    return i


def main() -> None:
    for command in tokens(str):
        if command == 'collatz':
            print(*list(collatz(read(int))))
        elif command == 'collatz_length':
            print(collatz_length(read(int)))
        elif command == 'collatz_highest':
            print(collatz_highest(read(int)))
        elif command == 'collatz_highest_position':
            print(collatz_highest_position(read(int)))
        elif command == 'collatz_11':
            print(collatz_11(read(int)))
        elif command == 'collatz_first_common':
            print(collatz_first_common(read(int), read(int)))
        elif command == 'collatz_common_elements':
            print(collatz_common_elements(read(int), read(int)))
        elif command == 'collatz_union':
            print(*collatz_union(read(int), read(int)))
        elif command == 'collatz_top_numbers':
            print(*[v for v, _ in zip(collatz_top_numbers(), range(read(int)))])
        elif command == 'collatz_first_missing':
            print(collatz_first_missing(read(int)))
        else:
            assert False


main()
