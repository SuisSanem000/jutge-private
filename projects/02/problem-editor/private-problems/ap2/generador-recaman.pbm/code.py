from yogi import read, tokens
from typing import Iterator


def recaman(k: int) -> Iterator[int]:
    ...


def recaman_from(k: int, n: int) -> Iterator[int]:
    ...


def recaman_first_completion(k: int, x: int) -> int:
    ...



def main() -> None:
    for command in tokens(str):
        if command == "recaman":
            k, m = read(int), read(int)
            gen = recaman(k)
            print([next(gen) for _ in range(m)])
        elif command == "recaman_from":
            k, n, m = read(int), read(int), read(int)
            gen = recaman_from(k, n)
            print([next(gen) for _ in range(m)])
        elif command == "recaman_first_completion":
            k, x = read(int), read(int)
            print(recaman_first_completion(k, x))
        else:
            assert False


if __name__ == "__main__":
    main()
