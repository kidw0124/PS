a,b,c=map(int,input().split())
if(a>b):a,b=b,a
print(1/(1/a*(1-c*0.01)+1/b*c*0.01))