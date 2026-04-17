n,m=map(int,input().split())
if m>0:
    print(n//m)
    print(n%m)
else:
    print(-(n//(-m)))
    print(n%(-m))