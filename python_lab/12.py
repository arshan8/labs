import turtle
import random

def draw_triangle(color, side_length):
  turtle.fillcolor(color)
  turtle.begin_fill()
  for _ in range(3):
    turtle.forward(side_length)
    turtle.right(120)
  turtle.end_fill()

def draw_sp(level, side_length):
  
  colors = ['red', 'yellow', 'green', 'blue']

  if level == 0:
    draw_triangle(random.choice(colors), side_length)

  else:
    draw_sp(level-1, side_length/2)
    turtle.forward(side_length/2)

    draw_sp(level-1, side_length/2)
    turtle.backward(side_length/2)
    turtle.left(60)
    turtle.forward(side_length/2)
    turtle.right(60)

    draw_sp(level-1, side_length/2)
    turtle.left(60)
    turtle.backward(side_length/2)
    turtle.right(60)

turtle.speed(5000)
# turtle.bgcolor('white')

turtle.penup()
turtle.goto(-300, -150)
turtle.pendown()

draw_sp(5, 600)  # No need for change_depth argument

# turtle.hideturtle()
turtle.mainloop()
