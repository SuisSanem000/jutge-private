import turtle
import yogi


def square(center_x, center_y, size):
    """draws a square centered at center_x, center_y with size size"""
    turtle.up()
    turtle.goto(center_x - size / 2, center_y + size / 2)
    turtle.down()
    for i in range(4):
        turtle.forward(size)
        turtle.right(90)


def koch(center_x, center_y, size, levels):
    """draws the koch fractal with 4 squares centered at center_x, center_y with size size and levels levels"""
    square(center_x, center_y, size)
    if levels > 1:
        offset = offset = size * 3 / 4
        koch(center_x + offset, center_y + offset, size / 2, levels - 1)
        koch(center_x + offset, center_y - offset, size / 2, levels - 1)
        koch(center_x - offset, center_y - offset, size / 2, levels - 1)


def main():
    # speed up drawing
    turtle.hideturtle()
    turtle.speed(100)

    # do the work
    n, d = yogi.read(int, float)
    koch(0, 0, d, n)

    # save image in a file
    cv = turtle.getcanvas()
    cv.postscript(file="sample%s.eps" % n, colormode='color')


main()
