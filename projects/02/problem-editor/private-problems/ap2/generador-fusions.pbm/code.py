from yogi import read, tokens
from typing import Iterator


def collatz(n: int) -> Iterator[int]:
    ...


def collatz_length(n: int) -> int:
    ...


def collatz_highest(n: int) -> int:
    ...


def collatz_highest_position(n: int) -> tuple[int, int]:
    ...


def collatz_11(n: int) -> bool:
    ...


def collatz_first_common(n1: int, n2: int) -> int:
    ...


def collatz_common_elements(n1: int, n2: int) -> int:
    ...


def collatz_union(n1: int, n2: int) -> list[int]:
    ...


def collatz_top_numbers() -> Iterator[int]:
    ...


def collatz_first_missing(n: int) -> int:
    ...


def main() -> None:
    """Main program"""

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
