import random
from collections import deque

print("explicit")
for n in range(20):
    for r in range(n):
        d = deque(range(n))
        d.rotate(-r)

        print(n, end='    ')
        for i in range(n):
            print(d[i], end=' ')
        print()
