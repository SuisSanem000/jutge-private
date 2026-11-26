import random
import sys

n = int(sys.argv[1])

print(n)
for i in range(n):
    for j in range(n):
        if i == j:
            print(0, end=' ')
        else:
            print(random.randint(1, n), end=' ')
    print()
print()


for i in range(n):
    for j in range(n):
        for k in range(n*n + 1):
            print(i, j, k)
