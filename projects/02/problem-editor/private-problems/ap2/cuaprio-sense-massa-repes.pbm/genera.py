# genera entrada que tindria temps quadràtic sense set

import random

n = 100_000

print("3")
for i in range(n):
    print(f'add', random.randint(0, n // 3))

print('size')
print('items')
print('empty')
print('minimum')

for i in range(n//2):
    print(f'remove_minimum')

print('size')
print('items')
print('empty')
print('minimum')
