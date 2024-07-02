time = int(input("time worked in hours:"))
wage = int(input("wage:"))
if time>60:
    print(f"salary is {2*time*wage}")
elif time>40:
    print(f"salary is {1.5*time*wage}")
else:
    print(f"salary is {time*wage}")