from yogi import tokens, read
from heapq import heappush, heappop


class Medianator:
    """Class to store a collection of intergers with operations to add elements and get their median."""

    _lower: list[int]  # MaxHeap to store the lower half of the elements (negated)
    _higher: list[int]  # MinHeap to store the higher half of the elements

    def __init__(self) -> None:
        """Creates an empty collection."""

        self._lower = []
        self._higher = []

    def add(self, element: int) -> None:
        """Adds an element to the collection"""

        if len(self._lower) == 0:
            # Add the element to the lower heap
            heappush(self._lower, -element)
        else:
            # Add the element to the appropriate heap
            if element <= -self._lower[0]:
                heappush(self._lower, -element)
            else:
                heappush(self._higher, element)
            # Balance the heaps if necessary
            if len(self._lower) > len(self._higher) + 1:
                heappush(self._higher, -heappop(self._lower))
            elif len(self._higher) > len(self._lower):
                heappush(self._lower, -heappop(self._higher))

    def median(self) -> int:
        """Gets the median of the elements in the collection"""

        assert len(self._lower) != 0, "No elements"
        return -self._lower[0]


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
