#!/usr/bin/python

import random


def expr():
    if random.randint(0, 100) < 50:
        return str(random.randint(0, 1))
    else:
        a = random.randint(0, 2)
        if a == 0:
            return "(" + expr() + "*" + expr() + ")"
        elif a == 1:
            return "(" + expr() + "+" + expr() + ")"
        elif a == 2:
            return "!" + expr()


print(expr())
