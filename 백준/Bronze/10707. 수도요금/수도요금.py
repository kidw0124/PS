A = int(input())
B = int(input())
C = int(input())
D = int(input())
P = int(input())

cost_A = A * P
if P > C :
    cost_B = B + (P - C) * D
else:
    cost_B = B

print(min([cost_A ,cost_B]))