
from yogi import *

white = dict[str, list[str]]()
black = dict[str, list[str]]()

n = read(int)
for _ in range(n):
    a = read(str)
    b = read(str)
    if a in white:
        white[a].append(b)
    else:
        white[a] = [b]

    if b in black:
        black[b].append(a)
    else:
        black[b] = [a]

a = scan(str)
b = scan(str)
while a is not None:
    if b == '?':
        print(a, "has played white against:")
        for e in sorted(white[a]):
            print(e)
    elif a == '?':
        print(b, "has played black against:")
        for e in sorted(black[b]):
            print(e)
    print()
    a = scan(str)
    b = scan(str)
