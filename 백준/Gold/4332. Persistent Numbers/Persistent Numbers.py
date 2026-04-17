while True:
    n = int(input())
    if n==-1:
        break
    ans = ""
    if n<=9:
        print("1"+str(n))
        continue
    for i in range(9, 1, -1):
        while n%i==0:
            n//=i
            ans+=str(i)
    ans = ans[::-1]
    print(ans if n==1 else "There is no such number.")
