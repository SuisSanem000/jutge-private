import random

n = 1000

for r in range(1000):
    l = [random.randint(0, n) for i in range(random.randint(1, n))]
    print(*l)