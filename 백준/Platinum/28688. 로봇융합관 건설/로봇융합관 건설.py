import sys
def input():
    return sys.stdin.readline().strip()
def print(a):
    sys.stdout.write(str(a)+'\n')
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    if n<3 or m<3 or (n*m%2==1):
        print("First")
    else:print("Second")
        