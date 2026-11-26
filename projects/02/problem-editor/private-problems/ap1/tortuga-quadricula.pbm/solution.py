from turtle_pil import *
from yogi import *


def mygoto(x, y):
    penup()
    goto(x, y)
    pendown()


n = read(int)
m = read(int)

# línies horitzontals
for i in range(n + 1):
    mygoto(0, i*m)
    forward(m * n)

# línies verticals
for i in range(n + 1):
    mygoto(i*m, 0)
    left(90)
    forward(m * n)
    right(90)

done()
