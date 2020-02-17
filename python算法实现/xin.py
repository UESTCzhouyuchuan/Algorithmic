import turtle
# turtle.forward(110)
turtle.fillcolor("pink")
turtle.end_fill()
turtle.up()
turtle.speed(10)
turtle.goto(-30, -30)
turtle.down()
turtle.setheading(0)
turtle.begin_fill()
turtle.left(140)
# 1左侧直线部分
turtle.color('orange')
turtle.forward(55)
# 2 左侧弧线部分
turtle.color('red')
for i in range(100):
    turtle.right(2)
    turtle.forward(1)
# 3 右侧弧线部分
turtle.left(120)
for i in range(100):
    turtle.right(2)
    turtle.forward(1)
# 4 右侧直线部分
turtle.color("orange")
turtle.forward(55)
turtle.fillcolor("pink")
turtle.end_fill()
turtle.done()
