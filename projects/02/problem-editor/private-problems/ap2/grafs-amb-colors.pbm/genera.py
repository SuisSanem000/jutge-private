import sys
import random

n = int(sys.argv[1])
m = int(n * 4)
r = int(sys.argv[2])

colors = ["red", "blue", "green", "yellow", "black"]

print(n)
for i in range(n):
    c = random.choice(colors)
    print("s" + str(i), c)
print(m)
for i in range(m):
    while True:
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        if u != v:
            break
    print("s" + str(u), "s" + str(v))
print()
for i in range(r):
    u = random.randint(0, n - 1)
    v = random.randint(0, n - 1)
    print("s" + str(u), "s" + str(v))
