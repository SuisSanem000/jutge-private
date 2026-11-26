import random

n = 100_000

for _ in range(n):
    print("inserir", random.randint(1, n))

print("mida")

print("entre", 0, n)

for _ in range(n):
    print("esborrar", random.randint(1, n))

print("mida")

print("entre", 0, n)
