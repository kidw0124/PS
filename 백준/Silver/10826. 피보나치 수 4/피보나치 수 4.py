a=int(input())
ans=[0,1]
for i in range(2,a+1):
    if i%2==0:
        ans[0]=ans[0]+ans[1]
    else:
        ans[1]=ans[0]+ans[1]
print(ans[a%2])