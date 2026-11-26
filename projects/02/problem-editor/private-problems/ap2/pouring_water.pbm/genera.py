import random
import sys
from solution import minimum_steps

seed = sys.argv[1]
random.seed(seed)

while True:
    n = 5
    cap = [random.randint(1, 50) for _ in range(n)]
    init = [random.randint(0, cap[i]) for i in range(n)]
    total = sum(init)
    obj = [0 for _ in range(n)]
    for _ in range(total):
        i = -1
        while i == -1 or obj[i] == cap[i]:
            i = random.randint(0, n-1)
        obj[i] += 1
    # 'X' allows no solution
    if (minimum_steps(tuple(init), tuple(cap), tuple(obj)) is not None) or seed[-1] == 'X':
        break

print(n)
print(' '.join(map(str, cap)))
print(' '.join(map(str, init)))
print(' '.join(map(str, obj)))
