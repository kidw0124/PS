N=int(input())
ans=0
b=0
import math
tmp=int(input())
for _ in range(N-1):
    c=input()
    d=int(input())
    if c=='+':
        if b==0:
            ans = ans + tmp
        else:
            ans=ans-tmp
        b=0
        tmp = d
    if c=='*':
        tmp = tmp*d
    if c=='/':
        tmp = tmp//d
    if c=='-':
        if b==0:
            ans = ans + tmp
        else:
            ans=ans-tmp
        b=1
        tmp=d
if b==0:
    ans = ans + tmp
else:
    ans=ans-tmp
print(ans)