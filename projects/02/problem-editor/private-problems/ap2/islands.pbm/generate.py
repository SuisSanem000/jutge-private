import random


def gen(s):
    n = random.randint(1, s)
    m = random.randint(1, s)
    print(n, m)
    for i in range(n):
        for j in range(m):
            if random.random() > 0.5:
                print('.', end='')
            else:
                print('O', end='')
        print()
    print()


for i in range(100):
    gen(10)
    gen(100)
