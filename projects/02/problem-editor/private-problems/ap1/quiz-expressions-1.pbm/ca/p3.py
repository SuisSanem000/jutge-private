
import random

x = random.randint(2, 9)
y = random.randint(2, 9)
z = random.randint(2, 9)

r1 = str(x + y == y + z)
r2 = str(x + y != y + z)
r3 = str(x + y > y + z)
r4 = str(x < y < z)
r5 = str(x <= y <= z)
