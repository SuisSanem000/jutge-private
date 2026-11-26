import random


def tree(h, x):
    if h == 1:
        print(x, -1, -1, end=' ')
    else:
        print(x + 2**(h-1)-1, end=' ')
        tree(h - 1, x)
        tree(h - 1, x + 2**(h-1))


if 0:
    tree(1, 0)
    print()
    tree(2, 0)
    print()
    tree(3, 0)
    print()


print(1)
h = 17
tree(h, 0)
print()
for i in range(10000):
    m = 2**h - 2
    print('    ', random.randint(0, m), random.randint(0, m))
    print('    ', 0, 2**h - 2)
print('    ', -1, -1)
