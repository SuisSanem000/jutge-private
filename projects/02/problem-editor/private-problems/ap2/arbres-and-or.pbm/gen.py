import random

VARS = "abcde"


def rnd_formula(n):
    if n == 1:
        return random.choice(VARS)
    op = random.choice(["AND", "OR", "NOT"])
    if op == "NOT":
        return "NOT(" + rnd_formula(n-1) + ")"
    else:
        return op + "(" + rnd_formula(n-1) + "," + rnd_formula(n-1) + ")"


n = 4
t = 10

print(rnd_formula(5))
for _ in range(t):
    for v in random.sample(VARS, random.randint(3, 5)):
        print(v + ' ', end='')
    print()
