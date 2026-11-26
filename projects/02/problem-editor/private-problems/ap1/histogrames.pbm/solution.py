import turtle
import yogi

MIDA = 300


def dibuixa_barra(i, amplada, valor):
    turtle.penup()
    turtle.goto(i * amplada, 0)
    turtle.pendown()
    for i in [1, 2]:
        turtle.forward(amplada)
        turtle.left(90)
        turtle.forward(valor)
        turtle.left(90)


def escriu_numero(x, y, numero):
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.write(str(round(numero, 1)))


def main():
    turtle.hideturtle()
    turtle.speed(0)
    barres = yogi.read(int)
    dades = list(yogi.read_many(int))
    amplada = max(dades) / (barres-1)
    comptadors = [0 for i in range(barres)]
    for dada in dades:
        on = int(dada / amplada)
        if on == barres:
            on -= 1
        print(dada, on)
        comptadors[on] += 1

    alcada = max(comptadors)
    for i in range(barres):
        dibuixa_barra(i, MIDA / barres, comptadors[i] * MIDA / alcada)

    for i in range(barres + 1):
        escriu_numero(MIDA / barres * i, -10, amplada*i)


main()
while True:
    pass
