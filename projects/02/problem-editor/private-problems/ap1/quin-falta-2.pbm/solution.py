from yogi import *

n, k = scan(int), scan(int)
while n is not None:
    assert k is not None
    s = set(range(1, n+1))
    for _ in range(k):
        x = read(int)
        if x in s:
            s.remove(x)
    assert len(s) == 1
    for x in s:  # just one iteration
        print(x)
    n, k = scan(int), scan(int)
