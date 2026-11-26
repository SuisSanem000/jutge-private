m = 1000
n = 1000

M = [[1 for _ in range(n)] for _ in range(m)]
print(m, n)
for row in M:
    print(*row)
