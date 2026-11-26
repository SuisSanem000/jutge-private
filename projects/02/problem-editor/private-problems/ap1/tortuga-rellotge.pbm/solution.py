from turtle_pil import *
from yogi import *


def dibuixa_rellotge():
    penup()
    goto(0, -200)
    pendown()
    circle(200)
    penup()
    goto(0, 0)
    pendown()
    for _ in range(12):
        penup()
        forward(150)
        pendown()
        forward(50)
        penup()
        backward(200)
        pendown()
        right(30)


def dibuixa_busca(llarg, angle):
    right(angle)
    forward(llarg)
    right(150)
    for _ in range(3):
        forward(25)
        right(120)
    left(150)
    backward(llarg)
    right(-angle)


dibuixa_rellotge()
h = read(int)
m = read(int)
dibuixa_busca(90, 360 * h / 12 + 360 * m / 60 / 12 - 90)
dibuixa_busca(140, 360 * m / 60 - 90)

done()
