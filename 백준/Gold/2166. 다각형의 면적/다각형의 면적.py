import sys
input = sys.stdin.readline

class POINT:
    def __init__(self,x,y):
        self.x,self.y=x,y

def __main__():
    n=int(input())
    point = []
    for i in range(n):
        x,y=map(int,input().split())
        point.append(POINT(x,y))
    point.append(point[0])
    S=0
    for i in range(n):
        S+=point[i].x*point[i+1].y
        S-=point[i+1].x*point[i].y
    print(f'{abs(S)/2:.1f}')
__main__()