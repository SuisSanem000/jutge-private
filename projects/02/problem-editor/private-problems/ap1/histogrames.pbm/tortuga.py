import turtle

turtle.speed(0)
turtle.hideturtle()
for i in range(4):
    turtle.forward(300)
    turtle.left(90)
turtle.penup()
turtle.goto(150, 150)
turtle.pendown()
turtle.write('Hola')

while True:
    pass
