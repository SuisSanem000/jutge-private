import random

n = 500000
for r in range(10):
    L = [random.randint(1, n) for _ in range(n)]
    print(*L)