my_list = []
n = int(input("total items in list:"))
for i in range(n):
    q = int(input(f"enter {i+1} element"))
    my_list.append(q)

for i in my_list:
    if i%8==0:
        print(i, end=',')

