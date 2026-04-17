import sys


def input():
    return sys.stdin.readline().rstrip()

a,b,m=map(int,input().split())

class Mat:
    def __init__(self, a,b,c,d):
        self.a,self.b,self.c,self.d=a,b,c,d
    def gop(self,p):
        return Mat((self.a*p.a + self.b * p.c)%m,( self.a*p.b + self.b*p.d)%m
                   ,(self.c * p.a + self.d * p.c)%m, (self.c * p.b + self.d*p.d)%m)
    def pow(self,x):
        if x==0:
            return Mat(1,0,0,1)
        elif x==1:
            return self
        else:
            t=self.pow(x//2)
            t=t.gop(t)
            if x%2==0:
                return t
            else:
                return t.gop(self)
    def __str__(self):
        return str(self.a)+' '+str(self.b)+' '+str(self.c)+' '+str(self.d)
M = Mat(a,m-1,1,0)

Mp=M.pow(b-1)
# print(Mp)

print((a*Mp.a+(2)*Mp.b)%m)
