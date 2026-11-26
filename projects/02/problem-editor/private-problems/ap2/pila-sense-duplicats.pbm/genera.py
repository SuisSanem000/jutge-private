# genera entrada que tindria temps quadràtic sense set

import random

n = 100_000

for i in range(n):
    print(f'push {i}')

print()

for i in range(n):
    print(f'push {random.randint(0, n-1)}')
