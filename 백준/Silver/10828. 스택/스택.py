import sys
input=sys.stdin.readline
class Stack:
    def __init__(self):
        self.dat = []
        self.len = 0
    def size(self):
        return self.len
    def empty(self):
        return self.size() == 0
    def push(self,a):
        self.dat.append(a)
        self.len += 1
    def pop(self):
        if self.empty():
            return -1
        self.len -= 1
        return self.dat.pop()
    def top(self):
        if self.empty():
            return -1
        return self.dat[-1]
    def peek(self):
        return self.top()
n = int(input())
a = Stack()
for i in range(n):
    op = input().split()
    if op[0]=='push':
        a.push(int(op[1]))
    elif op[0]=='pop':
        print(a.pop())
    elif op[0]=='top':
        print(a.top())
    elif op[0]=='size':
        print(a.size())
    else:
        print(1 if a.empty() else 0)