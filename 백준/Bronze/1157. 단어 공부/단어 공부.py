s = input().upper()
cnts = [0] * 27
for i in range(0, 26):
    cnts[i] = s.count(chr(i+65))
max = max(cnts) 
if cnts.count(max) >= 2: 
    print('?')
else:
    print(chr(cnts.index(max)+65))