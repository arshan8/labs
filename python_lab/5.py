

def binary(left,right,my,k):
    if right<=left:
        print("not found")
    else:
        mid = (left+right)//2
        if(my[mid]==k):
            print(f"found {k} at {mid}")
            return
        elif k<my[mid]:
            return binary(left,mid-1,my,k)
        else:
            return binary(mid+1,right,my,k)
    
def main():
    my=[6,7,4,55.32,12]
    k = int(input("enter number:"))
    my.sort()
    print(my)
    left = 0
    right = len(my)-1
    binary(left,right,my,k)

#if __name__ == "__main__":
#    main()
main()