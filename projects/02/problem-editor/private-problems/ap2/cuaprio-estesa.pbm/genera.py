import random

for n in range(100):
    for i in range(n):
        print("add", i, random.randint(1, n))
    print("print")
    for i in range(n):
        print("update", i, random.randint(1, n))
    print("print")
    for i in range(n):
        print("remove")
    print("print")
    print("empty")