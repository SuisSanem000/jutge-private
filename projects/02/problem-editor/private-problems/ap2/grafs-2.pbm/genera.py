import math
import sys
import random

n = int(sys.argv[1])
m = int(n*math.log(n))

print(n)
for i in range(n):
    print("s"+str(i))
print(m)
for i in range(m):
    while True:
        u = random.randint(0, n-1)
        v = random.randint(0, n-1)
        if u != v:
            break
    print("s"+str(u), "s"+str(v))
print()
u = random.randint(0, n-1)
v = random.randint(0, n-1)
print("s"+str(u), "s"+str(v))
