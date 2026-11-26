import yogi


class NoDupsStack:

    ...

    def __init__(self):
        ...

    def push(self, element: int) -> None:
        ...

    def pop(self) -> None:
        ...

    def top(self) -> int:
        ...

    def empty(self) -> bool:
        ...


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