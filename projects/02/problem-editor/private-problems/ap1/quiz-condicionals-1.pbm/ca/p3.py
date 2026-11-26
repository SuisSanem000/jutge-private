
import random

x = random.randint(3, 9)
y = random.randint(3, 9)
z = random.randint(3, 9)

a = x
b = y
c = z
if (a + b) % 2 == 0:
    p = a
    q = b
elif (a + b) % 3 == 0:
    p = c ** 2
    q = a - b
else:
    p = 2
    q = p
