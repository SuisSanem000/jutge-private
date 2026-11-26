a = random.randint(1, 5)
aux = random.randint(1, 2) == 1
if aux:
    b = round(random.uniform(1, 15), 2)
else:
    b = random.randint(1, 15)

c = round(random.uniform(1, 25), 2)
d = round(random.uniform(1, 10), 2)
e = round(c / d, 2)
f = b // a


s1 = b / a != f
s2 = not s1
