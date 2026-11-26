
import random

a = random.randint(2, 20)
b = random.randint(2, 20)
c = random.randint(2, 20)
d = random.randint(2, 20)


r1 = a + b > c - d

r2 = (a + b) * c > d or a - b < 0

r3 = a >= b and a >= b and a >= c

r4 = (b != c or b >= a) and (a < c or a == b)

r5 = not (c == d + a)
