import random
import sys

n = int(sys.argv[1])
m = int(sys.argv[2])  # aprox

g: list[set[int]] = [set() for _ in range(n)]

for _ in range(m):
    x = random.randint(0, n-1)
    y = random.randint(0, n-1)
    if x != y:
        g[x].add(y)
        g[y].add(x)

c = 0
for x in range(n):
    for y in g[x]:
        if x < y:
            c += 1

print(n, c)

for x in range(n):
    print("u"+str(x), end=' ')
print()

for x in range(n):
    for y in g[x]:
        if x < y:
            print("u"+str(x), "u"+str(y))

for x in range(n):
    print("u"+str(x))
