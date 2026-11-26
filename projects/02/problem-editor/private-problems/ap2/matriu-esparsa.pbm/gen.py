import random
import sys

n = int(sys.argv[1])
i = random.randint(0, n-1)

print("create a", n)
print("create b", n)

for k in range(n//2):
    j = random.randint(0, n-1)
    x = random.randint(1, 4)
    print("set a", i, j, x)
print("print a")
print("#")

for k in range(n//2):
    j = random.randint(0, n-1)
    x = random.randint(1, 4)
    print("set b", i, j, x)
print("print b")
print("#")

print("add a b")
print("print a")
