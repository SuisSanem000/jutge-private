import random
import sys

n = int(sys.argv[1])

lletres = ['a', 'b', 'c', 'd', 'e']

paraules = set()
for i in range(n):
    l = random.randint(1, 12)
    paraula = ''.join([random.choice(lletres) for i in range(l)])
    if random.randint(0, 100) >= 50:
        paraula = paraula.upper()
    paraules.add(paraula)

paraules = list(paraules)
random.shuffle(paraules)
print(len(paraules))
for paraula in paraules:
    print(paraula)
