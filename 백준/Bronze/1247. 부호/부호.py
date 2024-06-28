for _ in range(3):
    n=int(input())
    arr=[]
    for __ in range(n):arr.append(int(input()))
    if sum(arr)>0:print("+")
    elif sum(arr)==0:print("0")
    else:print("-")