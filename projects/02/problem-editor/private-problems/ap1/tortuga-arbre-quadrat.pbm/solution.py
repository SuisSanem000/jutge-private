import turtle
import yogi


def draw_open_square(x: float, y: float, size: float) -> None:
    """Draws an open square with the root at (x,y) and side length given by size."""

    turtle.up()
    turtle.goto(x - size / 2, y + size)
    turtle.down()
    turtle.goto(x - size / 2, y)
    turtle.goto(x + size / 2, y)
    turtle.goto(x + size / 2, y + size)


def draw_squared_tree(n: int, x: float, y: float, size: float) -> None:
    """Draws a squared tree of n levels with the root at (x,y) and side length given by size."""

    if n > 0:
        draw_open_square(x, y, size)
        draw_squared_tree(n - 1, x - size / 2, y + size, size / 2)
        draw_squared_tree(n - 1, x + size / 2, y + size, size / 2)


def main() -> None:
    levels, size = yogi.read(int), yogi.read(float)
    turtle.speed(0)
    draw_squared_tree(levels, 0, 0, size)
    turtle.done()


if __name__ == "__main__":
    main()
