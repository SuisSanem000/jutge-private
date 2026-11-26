import yogi
import heapq


class Bag:

    _k: int # maximum number of duplicates allowed
    _heap : list[int]      # heap of elements
    _counters : dict[int, int]    # count each element in the heap

    def __init__(self, k: int):
        """Create an empty bag with a maximum of k duplicates. O(1)."""
        assert k >= 0
        self._k = k
        self._heap = []
        self._counters = {}

    def add(self, x: int):
        """Add x into the bag. O(log n)."""
        if x not in self._counters:
            self._counters[x] = 0
        if self._counters[x] < self._k:
            self._counters[x] += 1
            heapq.heappush(self._heap, x)

    def empty(self) -> bool:
        """Tells if the bag is empty. O(1)."""
        return len(self._heap) == 0

    def size(self) -> int:
        """Return the number of elements in the bag. O(1)."""
        return len(self._heap)

    def items(self) -> int:
        """Return the number of different elements in the bag. O(1)."""
        return len(self._counters)

    def minimum(self) -> int:
        """Return the smallest element in the bag. Prec: The bag is not empty. O(1)."""
        assert not self.empty()
        return self._heap[0]

    def remove_minimum(self) -> int:
        """Remove and return the smallest element in the bag. Prec: The bag is not empty. O(log n)"""
        assert not self.empty()
        x = self._heap[0]
        heapq.heappop(self._heap)
        self._counters[x] -= 1
        if self._counters[x] == 0:
            del self._counters[x]
        return x


def main() -> None:
    bag = Bag(yogi.read(int))
    for command in yogi.tokens(str):
        if command == "add":
            bag.add(yogi.read(int))
        elif command == "remove_minimum":
            print(bag.remove_minimum())
        elif command == "minimum":
            print(bag.minimum())
        elif command == "size":
            print(bag.size())
        elif command == "empty":
            print(bag.empty())
        elif command == "items":
            print(bag.items())
        else:
            assert False


if __name__ == "__main__":
    main()
