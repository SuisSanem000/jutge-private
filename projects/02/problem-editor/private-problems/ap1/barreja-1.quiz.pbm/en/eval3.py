a = random.randint(1, 6)
b = random.randint(1, 10)
c = random.randint(1, 2) == 1
d = random.randint(1, 2) == 1
e = random.randint(1, 19)
f = random.randint(1, 4)

s1 = not (a * b > 9) != c or (c != d and (e // b >= f))
s2 = not s1
