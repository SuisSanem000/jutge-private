# author: Jordi Petit

import sys


def read(typ=str):

    def tokenizer():
        for line in sys.stdin.readlines():
            for word in line.split():
                yield word
        while True:
            yield None

    if not hasattr(read, "tokens"):
        read.tokens = tokenizer()

    token = next(read.tokens)
    if token is None:
        return None
    return typ(token)


if __name__ == "__main__":
    s = 0
    x = read(int)
    while x is not None:
        s += x
        x = read(int)
    print(s)
