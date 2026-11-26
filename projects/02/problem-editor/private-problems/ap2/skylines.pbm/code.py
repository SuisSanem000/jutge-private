from yogi import read
from typing import TypeAlias


class Point:
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y


Skyline: TypeAlias = list[Point]


def read_skyline() -> Skyline:
    return [Point(read(int), read(int)) for _ in range(read(int))]


def print_skyline(s: Skyline) -> None:
    print(len(s), end='')
    for p in s:
        print('', p.x, p.y, end='')
    print()


def skyline_superposition(a: Skyline, b: Skyline) -> Skyline:
    ...


def skyline(skylines: list[Skyline]) -> Skyline:
    ...


def main() -> None:
    print_skyline(skyline([read_skyline() for _ in range(read(int))]))


main()
