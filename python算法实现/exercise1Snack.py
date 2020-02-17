# 蟒蛇绘图

import turtle


def drawSnake(rad, angle, len, neckrad):
    mycolor = ["blue", 'red', 'black', 'green', 'yellow']
    youclor = ['black', 'green', 'yellow', 'red', 'blue']
    for i in range(len):
        turtle.pencolor(mycolor[i])
        turtle.circle(rad, angle)
        turtle.pencolor(youclor[i])
        turtle.circle(-rad, angle)
    turtle.pencolor("green")
    turtle.circle(rad, angle/2)
    turtle.pencolor("blue")
    turtle.fd(rad)
    turtle.pencolor("red")
    turtle.circle(neckrad+1, 180)
    turtle.pencolor("black")
    turtle.fd(rad*2/3)


def main():
    turtle.setup(1300, 800, 0, 0)
    turtle.write("蟒蛇", font=("Arial", 10, "normal"))
    turtle.goto(0, -30)
    pythonsize = 20
    turtle.pensize(pythonsize)
    turtle.seth(-40)
    drawSnake(40, 80, 5, pythonsize/2)


main()
