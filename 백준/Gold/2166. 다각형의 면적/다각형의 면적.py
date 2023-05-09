import sys
input = sys.stdin.readline
def __main__():
    n=int(input())
    point = []
    for i in range(n):
        point.append(tuple(map(int,input().rstrip().split())))
    point.append(point[0])
    S=0
    for i in range(n):
        S+=point[i][0]*point[i+1][1]
        S-=point[i+1][0]*point[i][1]
    print(f'{abs(S)/2:.1f}')
__main__()