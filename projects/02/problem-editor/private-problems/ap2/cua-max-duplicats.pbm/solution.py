import yogi
from collections import deque


class QueueMaxDupes:
    """A queue of ints that allows at most k copies of any element."""

    _k: int
    _deque: deque[int]
    _count: dict[int, int]

    def __init__(self, k: int):
        """Creates an empty queue. Each value may appear at most k times."""
        assert k >= 1
        self._k = k
        self._deque = deque[int]()
        self._count = {}

    def enter(self, element: int) -> None:
        """Adds element to the back of the queue if it has fewer than k copies."""
        if self._count.get(element, 0) < self._k:
            self._deque.append(element)
            self._count[element] = self._count.get(element, 0) + 1

    def leave(self) -> None:
        """Removes the front element. Prec: the queue is not empty."""
        assert not self.empty()
        x = self._deque.popleft()
        self._count[x] -= 1
        if self._count[x] == 0:
            del self._count[x]

    def next(self) -> int:
        """Returns the front element. Prec: the queue is not empty."""
        assert not self.empty()
        return self._deque[0]

    def empty(self) -> bool:
        """Tells if the queue is empty."""
        return len(self._deque) == 0

    def print(self) -> None:
        """Prints the queue."""
        print(*self._deque)


def main() -> None:
    k = yogi.read(int)
    q = QueueMaxDupes(k)
    for command in yogi.tokens(str):
        if command == "enter":
            q.enter(yogi.read(int))
        elif command == "leave":
            q.leave()
        elif command == "next":
            print(q.next())
        elif command == "empty":
            print(q.empty())
        elif command == "print":
            q.print()


if __name__ == "__main__":
    main()
