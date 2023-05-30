import math

d,k=map(int,input().split())
ans=1
if d%4==2 and k%2==0 and k>2:
    ans=2
g=math.gcd(d,k)
while g!=1:
    g=math.gcd(d,k)
    ans*=g
    k//=g
print(ans*d)
