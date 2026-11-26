from yogi import tokens, read


class Medianator:
    ...

    def __init__(self) -> None:
        ...

    def add(self, element: int) -> None:
        ...

    def median(self) -> int:
        ...


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
