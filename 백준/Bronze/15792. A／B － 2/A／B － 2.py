from decimal import *
getcontext().prec=2000
a,b=map(Decimal,input().split())
print(f"{a/b:.2000f}")