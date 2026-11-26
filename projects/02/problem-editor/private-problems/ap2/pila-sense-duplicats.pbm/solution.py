import yogi


class NoDupsStack:
    """A stack of ints that does not allow duplicates. """

    _stack : list[int]      # list of elements in the stack
    _elements : set[int]    # set of elements in the stack

    def __init__(self):
        """Creates an empty stack without duplicates."""
        self._stack = []
        self._elements = set()

    def push(self, element: int) -> None:
        """Pushes an element to the stack, if it is not already there."""
        if element not in self._elements:
            self._stack.append(element)
            self._elements.add(element)

    def pop(self) -> None:
        """Pops the top element from the stack. Prec: the stack is not empty."""
        assert not self.empty()
        element = self._stack.pop()
        self._elements.remove(element)

    def top(self) -> int:
        """Returns the top element from the stack. Prec: the stack is not empty."""
        assert not self.empty()
        return self._stack[-1]

    def empty(self) -> bool:
        """Tells if the stack is empty."""
        return len(self._stack) == 0


def main() -> None:
    s = NoDupsStack()
    for command in yogi.tokens(str):
        if command == "push":
            s.push(yogi.read(int))
        elif command == "pop":
            s.pop()
        elif command == "top":
            print(s.top())
        elif command == "empty":
            print(s.empty())

if __name__ == "__main__":
    main()