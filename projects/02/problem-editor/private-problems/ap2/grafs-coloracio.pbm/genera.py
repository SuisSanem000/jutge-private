import math
import sys
import random

r = int(sys.argv[1])
n = int(sys.argv[2])
m = int(n*math.log(n))

for i in range(r):
    E = set()
    while len(E) != m:
        u = random.randint(0, n-1)
        v = random.randint(0, n-1)
        E.add((min(u, v), max(u, v)))

    print(n, m)
    for (u, v) in E:
        print(' ', u, v)
