import sys

n = int(sys.argv[1])

print(2*n, 2*n)
for i in range(2*n):
    if i % 2 == 0:
        print('O.' * n)
    else:
        print('.O' * n)
