import sys
input=sys.stdin.readline

while True:
    a=input().rstrip()
    if a=='.':
        break
    stk = []
    for x in a:
        if x=='(' or x=='{' or x=='[':
            stk.append(x)
        elif x==')' or x=='}' or x==']':
            if len(stk)==0:
                print("no")
                break
            if x==')':
                y=stk.pop()
                if y!='(':
                    print("no")
                    break
            if x==']':
                y=stk.pop()
                if y!='[':
                    print("no")
                    break
            if x=='}':
                y=stk.pop()
                if y!='}':
                    print("no")
                    break
    else:
        if len(stk)==0:print("yes")
        else: print("no")