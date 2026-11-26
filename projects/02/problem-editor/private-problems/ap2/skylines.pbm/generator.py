import random
import sys

n = int(sys.argv[1])

print(n)
for i in range(n):
    height = random.randint(10, 100)
    width = random.randint(1, 10)
    start = random.randint(1, n)
    print(2, start, height, start + width, 0)
