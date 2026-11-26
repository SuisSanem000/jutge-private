m = 1000
n = 1000

M = [[1 for _ in range(n)] for _ in range(m)]
p, q = m*3//4, n*3//4
M[p][q] = - (p+1) * (q+1) + 1
print(m, n)
for row in M:
    print(*row)
