
import random
import math

c = random.randint(2, 4)
f = random.randint(5, 9)
a = 1
b = a * c
while a < f:
    a = a + 1
    r = str(a) + ' ' + str(b)
