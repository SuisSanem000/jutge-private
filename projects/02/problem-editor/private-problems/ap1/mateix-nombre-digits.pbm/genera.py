import random

for x in range(100):
    for y in range(100):
        print(x, y)

for r in range(1000):
    x = random.randint(0, 1000)
    y = random.randint(0, 1000)
    print(x, y)

for r in range(1000):
    x = random.randint(0, 1000000)
    y = random.randint(0, 1000000)
    print(x, y)
