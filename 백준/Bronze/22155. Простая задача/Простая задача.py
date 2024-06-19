for _ in range(int(input())):
    n,m=map(int,input().split())
    if n<3 and m<3 and n+m<4:
        print("Yes")
    else:print("No")