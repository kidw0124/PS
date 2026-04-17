import sys
import math
def input():
    return sys.stdin.readline().strip()
def print(a,end='\n'):
    sys.stdout.write(str(a)+end)

arr = []
n,m = 0, 0

def f():
    global arr, n, m
    cycles = []
    visited = [False]*n
    period = [0]*n
    for i in range(n):
        if not visited[i]:
            cycle = []
            j = i
            while not visited[j]:
                visited[j] = True
                cycle.append(j)
                j = arr[j]-1
            if cycle:
                l = len(cycle)
                for k in cycle:
                    period[k] = l
                cycles.append(cycle)
    ret = 0
    for i in range(n):
        p = m%period[i]
        now = i
        for j in range(p):
            now = arr[now]-1
        ret += (now+1)*(i+1)
    return ret

def __main__():
    global arr, n, m
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    q = int(input())
    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            arr[query[1]-1], arr[query[2]-1] = arr[query[2]-1], arr[query[1]-1]
        else:
            print(f())


__main__()
