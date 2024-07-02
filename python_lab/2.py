my_string = input("enter string:")
my_set = set(my_string)
print()
for a in my_set:
    count = 0
    for i in my_string:
        if i==a:
            count+=1
    print(f"{a} occurs {count} times")
    
