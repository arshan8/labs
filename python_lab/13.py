import turtle as t


def koch(length,level):
    if level == 0:
        t.forward(length)
    else:
        koch(length/3,level-1)
        t.right(60)

        koch(length/3,level-1)
        t.left(120)

        koch(length/3,level-1)
        t.right(60)
        
        koch(length/3,level-1)

t.speed(5000)
# turtle.bgcolor('white')



for i in range(6):
    koch(200,1)
    t.right(60)
t.mainloop()
