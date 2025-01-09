from decimal import *
getcontext().prec=100
getcontext().rounding=ROUND_HALF_UP
PI=Decimal("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170680")
def sin(x):
	x=x%(2*PI)
	st=x
	num=x
	en=0
	i=1
	facto=1
	while st!=en:
		en=st
		i+=2
		facto*=-i*(i-1)
		num*=x**2
		st+=num/facto
	return st
A,B,C = map(Decimal,map(int,input().split()))
st=(C-B)/A
en=(C+B)/A
while en-st>Decimal(1e-25):
	now=(st+en)/2
	if A*now+B*sin(now)<C:
		st=now
	else:
		en=now
print(round(st, 6))