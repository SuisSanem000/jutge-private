import yogi
import turtle


def quadrat(x: float, y: float, m: float) -> None:
    """Pinta un quadrat de mida m⨉m centrat en x,y."""

    turtle.penup()
    turtle.goto(x - m/2, y - m/2)
    turtle.pendown()
    for _ in range(4):
        turtle.forward(m)
        turtle.left(90)


def fractal_poder(x: float, y: float, m: float, n: int) -> None:
    """Pinta un fractal del poder centrat en x,y de mida m amb nivells."""

    if n > 0:
        quadrat(x, y, m)
        fractal_poder(x + m, y + m, m / 3, n - 1)
        fractal_poder(x - m, y - m, m / 3, n - 1)
        fractal_poder(x - m, y + m, m / 3, n - 1)
        fractal_poder(x + m, y - m, m / 3, n - 1)


def main():
    turtle.speed(0)
    turtle.hideturtle()
    m = yogi.read(float)
    n = yogi.read(int)
    fractal_poder(0, 0, m, n)
    turtle.done()

    # save image in a file
    # cv = turtle.getcanvas()
    # cv.postscript(file=f"fractal-{int(m)}-{n}.eps", colormode='color')


main()
