import random
import sys

n = int(sys.argv[1])
i = random.randint(0, n-1)

print("create a", n)
print("create b", n)

for k in range(n):
    j = n-1-k
    x = random.randint(1, 4)
    print("set a", i, j, x)
for k in range(n):
    j = n-1-k
    x = random.randint(1, 4)
    print("set b", i, j, x)
print("add a b")
for j in range(n):
    print("get a", i, j)
