import turtle

num_sides = int(input("enter no of sides:"))
side_length= int(input("enter lenght:"))
pen_color = input("enter pen color:")
fill_color = input("enter fill color:")

t = turtle.Turtle()
t.color(pen_color)
t.fillcolor(fill_color)

angle = 360/num_sides

t.begin_fill()
for _ in range(num_sides):
    t.forward(side_length)
    t.right(angle)
t.end_fill()

turtle.done()


