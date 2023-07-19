import sys
input=sys.stdin.readline

class term:
    def __init__(self,coef=0,exp=0):
        self.coef = coef
        self.exp = exp
    def f(self,x):
        return self.coef*pow(x,self.exp,1000000007) % 1000000007

class polynom:
    def __init__(self, n=0):
        self.terms = [term() for _ in range(n)]
    def f(self,x):
        ret = 0
        for a in self.terms:
            ret += a.f(x)
            ret %= 1000000007
        return ret
    def diff(self):
        ret = polynom()
        for a in self.terms:
            if a.exp>0:ret.terms.append(term(a.coef*a.exp,a.exp-1))
        return ret
n = int(input())
poly = polynom(n)
for i in range(n):
    poly.terms[i].coef, poly.terms[i].exp = map(int, input().split())
print(poly.diff().f(2) % 1000000007)