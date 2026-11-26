import yogi
from dataclasses import dataclass


"""
Aquí teniu una implementació d'una cua de prioritat per
emmagatzemar textos amb una prioritat associada.
La prioritat és un enter, i la cua de prioritat manté els
elements en un min heap.
"""


@dataclass
class _Pair:
    """A dataclass to represent an element and its priority in the heap."""
    priority: int
    element: str


class PriorityQueue():
    """
    A priority queue of strings with integer priorities.
    """

    _heap: list[_Pair]

    def __init__(self) -> None:
        """Create an empty priority queue."""
        self._heap = []

    def add(self, element: str, priority: int) -> None:
        """Add an element to the priority queue with some priority. Prec: element is not already in the queue."""
        self._heap.append(_Pair(priority, element))
        self._push_up(len(self._heap) - 1)

    def minimum(self) -> str:
        """Get the minimum element from the priority queue. Prec: priority queue is not empty."""
        assert not self.empty()
        return self._heap[0].element

    def remove(self) -> str:
        """Remove the minimum element from the priority queue. Prec: priority queue is not empty."""
        assert not self.empty()
        min_element = self._heap[0].element
        self._heap[0] = self._heap[-1]
        self._heap.pop()
        self._push_down(0)
        return min_element

    def __len__(self) -> int:
        """Return number of elements in the priority queue."""
        return len(self._heap)

    def empty(self) -> bool:
        """Check if the priority queue is empty."""
        return len(self._heap) == 0

    def _push_up(self, index: int) -> None:
        """Restore heap property by moving element up the heap."""
        if index == 0: return

        parent_index = (index - 1) // 2
        # If current element has lower priority than parent, swap them
        if self._heap[index].priority < self._heap[parent_index].priority:
            self._heap[index], self._heap[parent_index] = self._heap[parent_index], self._heap[index]
            self._push_up(parent_index)

    def _push_down(self, index: int) -> None:
        """Restore heap property by moving element down the heap."""
        if index >= len(self._heap): return
        left_child = 2 * index + 1
        right_child = 2 * index + 2
        # Find the smallest among parent and children
        smallest = index
        if left_child < len(self._heap) and self._heap[left_child].priority < self._heap[smallest].priority:
            smallest = left_child
        if right_child < len(self._heap) and self._heap[right_child].priority < self._heap[smallest].priority:
            smallest = right_child

        # If smallest is not the parent, swap and continue pushing
        if smallest != index:
            self._heap[index], self._heap[smallest] = self._heap[smallest], self._heap[index]
            self._push_down(smallest)

    def print(self) -> None:
        """Print the elements of the priority queue in order. Just to help debugging and checking."""
        print("{", end=" ")
        for pair in sorted(self._heap, key=lambda pair: pair.element):
            print(pair.element, ':', pair.priority, end=" ", sep="")
        print("}")


"""
Aprofitant la implementació de la cua de prioritat anterior, implementeu una extensió que permeti
actualitzar la prioritat d'un element existent a la cua de prioritat. Totes les operacions
han de tenir una complexitat O(log n), on n és el nombre d'elements a la cua de prioritat extesa.
"""

class ExtendedPriorityQueue():
    """
    A priority queue of strings with integer priorities, with the ability to update priorities.
    """

    ...

    def __init__(self) -> None:
        """Create an empty priority queue."""
        ...

    def add(self, element: str, priority: int) -> None:
        """Add an element to the priority queue with some priority. Prec: element is not already in the queue."""
        ...

    def minimum(self) -> str:
        """Get the minimum element from the priority queue. Prec: priority queue is not empty."""
        ...

    def remove(self) -> str:
        """Remove the minimum element from the priority queue. Prec: priority queue is not empty."""
        ...

    def __len__(self) -> int:
        """Return number of elements in the priority queue."""
        ...

    def empty(self) -> bool:
        """Check if the priority queue is empty."""
        ...

    def update(self, element: str, new_priority: int) -> None:
        """Update the priority of an element in the extended priority queue. Prec: element exists in the queue."""
        ...

    def print(self) -> None:
        """Print the elements of the priority queue in order. Just to help debugging and checking."""
        ... # seguiu la implementació de PriorityQueue


def main() -> None:
    pq = ExtendedPriorityQueue()
    for command in yogi.tokens(str):
        if command == "add":
            pq.add(yogi.read(str), yogi.read(int))
        elif command == "remove":
            pq.remove()
        elif command == "empty":
            print(pq.empty())
        elif command == "minimum":
            print(pq.minimum())
        elif command == "update":
            pq.update(yogi.read(str), yogi.read(int))
        elif command == "print":
            pq.print()


if __name__ == "__main__":
    main()