import random
import sys


seed = sys.argv[1]
n = 30
p = list(range(1, n+1))
random.shuffle(p)

print(n)
print(*p)
