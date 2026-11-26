import yogi


class QueueMaxDupes:

    ...

    def __init__(self, k: int): ...

    def enter(self, element: int) -> None: ...

    def leave(self) -> None: ...

    def next(self) -> int: ...

    def empty(self) -> bool: ...

    def print(self) -> None: ...


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
