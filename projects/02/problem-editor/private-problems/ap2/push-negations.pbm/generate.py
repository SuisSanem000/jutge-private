#!/usr/bin/python

import random


def expr():
    if random.randint(0, 100) < 50:
        return 'abcdefghijklmnopqrstuvwxzy'[random.randint(0, 25)]
    else:
        a = random.randint(0, 2)
        if a == 0:
            return "(" + expr() + "*" + expr() + ")"
        elif a == 1:
            return "(" + expr() + "+" + expr() + ")"
        elif a == 2:
            return "!" + expr()


for i in range(100):
    print(expr())
