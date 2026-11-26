import random
import sys

n = int(sys.argv[1])

print(n)
for i in range(n):
    nom = 's' + str(i)
    dni = i
    dd = 1
    mm = 1
    aa = 2010 + random.choice([0, -1, 1])
    muni = random.choice(['a', 'b'])
    print(nom, dni, dd, mm, aa, muni)
print()

ss = []
for i in range(n):
    if random.choice([False, True]):
        ss.append(i)

print(len(ss))
for s in ss:
    dd = 1
    mm = 1
    aa = 2010 + random.choice([0, -1, 1])
    print(s, random.choice(['S', 'N']), dd, mm, aa)
print()

print(2010)
print('a')
