import yogi
import turtle


def cercle(x: float, y: float, m: float) -> None:
    """Pinta un cercle de radi m centrat en x,y."""

    turtle.penup()
    turtle.goto(x, y - m)
    turtle.pendown()
    turtle.circle(m)


def roda_del_temps(x: float, m: float, n: int) -> None:
    """
    Pinta una fractal de la roda del temps centrada en x,0 de mida m amb n nivells.
    Assumeix que la tortuga mira a l'est.
    """

    if n > 0:
        cercle(x, 0, m)
        roda_del_temps(x + m / 2, m / 2, n - 1)
        roda_del_temps(x - m / 2, m / 2, n - 1)


def main():
    turtle.speed(0)
    turtle.hideturtle()
    m = yogi.read(float)
    n = yogi.read(int)
    roda_del_temps(0, m, n)
    turtle.done()


main()
