from yogi import tokens, read
from heapq import heappush, heappop


class Medianator:

    _elements: list[int]

    def __init__(self) -> None:
        self._elements = []

    def add(self, element: int) -> None:
        self._elements.append(element)

    def median(self) -> int:
        n = len(self._elements)
        return sorted(self._elements)[(n + 1) // 2 - 1]


def main() -> None:
    s = Medianator()
    for action in tokens(str):
        if action == "add":
            s.add(read(int))
        elif action == "median":
            print(s.median())
        else:
            print("Invalid action")


if __name__ == "__main__":
    main()
