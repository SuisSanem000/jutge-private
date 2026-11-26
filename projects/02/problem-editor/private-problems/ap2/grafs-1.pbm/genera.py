import math
import sys
import random

n = int(sys.argv[1])
m = int(n*math.log(n))

print(n, m)
print()
for i in range(m):
    while True:
        u = random.randint(0, n-1)
        v = random.randint(0, n-1)
        if u != v:
            break
    print(u, v)
print()
print(random.randint(0, n-1), random.randint(0, n-1))
