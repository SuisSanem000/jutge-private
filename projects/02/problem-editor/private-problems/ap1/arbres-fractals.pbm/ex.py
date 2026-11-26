import turtle
import yogi


def tree(n, d, a):
    if n > 0:
        turtle.forward(d)
        turtle.right(a)
        tree(n-1, d*3/4, a)
        turtle.left(2*a)
        tree(n-1, d*3/4, a)
        turtle.right(a)
        turtle.backward(d)


def main():
    n = yogi.read(int)
    d = yogi.read(float)
    a = yogi.read(float)
    turtle.left(90)
    turtle.pu()
    turtle.backward(200)
    turtle.pd()
    tree(n, d, a)


main()


f = yogi.read()
turtle.ht()
ts = turtle.getscreen()
ts.getcanvas().postscript(file=f + ".eps")
