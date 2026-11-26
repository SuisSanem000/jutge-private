
from yogi import read, tokens

from typing import Iterator


def recaman(k: int) -> Iterator[int]:
    """Generates the k-Recaman sequence."""

    generated = set[int]()
    last = 0
    n = 0
    while True:
        yield last
        generated.add(last)
        n += 1
        if last - n - k > 0 and not last - n - k in generated:
            last = last - n - k
        else:
            last = last + n + k


def recaman_from(k: int, n: int) -> Iterator[int]:
    """Generates the k-Recaman sequence starting from a_n."""

    seq = recaman(k)
    for _ in range(n):
        next(seq)
    return seq


def recaman_first_completion(k: int, x: int) -> int:
    """Returns the first n such that {a_0,...a_n} contains all natural numbers in {0,...,x}."""

    seq = recaman(k)
    numbers = set(range(x+1))
    n = -1
    while len(numbers) != 0:
        n += 1
        last = next(seq)
        numbers.discard(last)
    return n



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