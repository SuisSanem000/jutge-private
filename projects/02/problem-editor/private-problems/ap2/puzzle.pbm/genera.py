import random

p = list(range(9))
random.shuffle(p)
print(*p[0:3])
print(*p[3:6])
print(*p[6:9])
