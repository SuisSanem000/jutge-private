import yogi
...


class Bag:

    ...

    def __init__(self, k: int):
        ...

    def add(self, x: int):
        ...

    def empty(self) -> bool:
        ...

    def size(self) -> int:
        ...

    def items(self) -> int:
        ...

    def minimum(self) -> int:
        ...

    def remove_minimum(self) -> int:
        ...


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
