import turtle
import yogi


d = yogi.read(float)
turtle.penup()
turtle.goto(0, -d/2)
turtle.pendown()
turtle.circle(d)
