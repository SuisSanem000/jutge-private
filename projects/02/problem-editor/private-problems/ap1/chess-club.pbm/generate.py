import random


def random_word():
    s = ''
    n = random.randrange(1, 15)
    for k in range(n):
        s += random.choice("abcdefghijklmnopqrstuvwxyz")
    return s


random.seed(1234)

white = set([])
black = set([])
seen = {}
n = 200000
print(n)
i = 0
while i < n:
    a = random.randrange(0, 1001, 2)
    b = random.randrange(1, 1000, 2)
    k = str(a)+":"+str(b)
    if k not in seen:
        seen[k] = 1
        print(a, b)
        white.add(a)
        black.add(b)
        i += 1

white = list(white)
black = list(black)
for i in range(0, 1000):
    if random.randrange(0, 2) == 0:
        print("?", random.choice(black))
    else:
        print(random.choice(white), "?")
