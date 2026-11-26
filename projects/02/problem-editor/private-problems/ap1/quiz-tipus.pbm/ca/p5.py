import random

a1 = random.randint(11, 99)
b1 = random.randint(11, 99)


a2 = random.randint(11, 99)
b2 = random.randint(11, 99)
r2 = int(a2 / b2)

x1 = float(str(random.randint(11, 99)) + '.' + str(random.randint(11, 99)))
y1 = float(str(random.randint(11, 99)) + '.' + str(random.randint(11, 99)))
r1 = int(x1 + y1)

a4 = random.randint(11, 99)
b4 = random.randint(a4-1, a4+1)
r4 = int(a4 == b4)

a5 = random.randint(11, 99)
b5 = random.randint(11, 99)
c5 = random.randint(2, 4)
r5 = ((a5 + b5) // c5)
