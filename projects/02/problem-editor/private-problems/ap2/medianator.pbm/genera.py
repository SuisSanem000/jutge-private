import random

n = 20_000

for i in range(n):
    r = random.randint(1, n)
    print(f'add {r} median')
