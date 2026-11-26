import turtle
import yogi


def sierpinski(m, n):
    if n == 1:
        for i in range(3):
            turtle.forward(m)
            turtle.left(120)
    else:
        sierpinski(m / 2, n - 1)
        turtle.forward(m / 2)
        sierpinski(m / 2, n - 1)
        turtle.backward(m / 2)
        turtle.left(60)
        turtle.forward(m / 2)
        turtle.right(60)
        sierpinski(m / 2, n - 1)
        turtle.left(60)
        turtle.backward(m / 2)
        turtle.right(60)


def main():
    m, n = yogi.read(float, int)

    # presentation
    turtle.hideturtle()
    turtle.speed(0)
    turtle.up()
    turtle.goto(-m/2, -m/2)
    turtle.down()

    sierpinski(m, n)

    # save image in a file
    turtle.getcanvas().postscript(file="%s.eps" % n, colormode='color')


main()
