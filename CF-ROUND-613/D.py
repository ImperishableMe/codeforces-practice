mx = 32

def f(a,pos) :
    if pos < 0  or len(a) == 0: 
        return 0
    #print(pos)

    on = []
    off = []
    for x in a : 
        if x & (1<<pos) :
            on.append(x)
        else :
            off.append(x)
    if len(on) == 0 : 
        return f(off,pos-1)
    if len(off) == 0 : 
        return f(on,pos-1)

    a.clear()
    return (1<<pos) + min(f(on,pos-1),f(off,pos-1))

def solve(n) :
    li = list(map(int,input().split()))
   # print(*li)
    print(f(li,mx))

while True : 
    try :
        n = int(input())
        #print(1<<32)
        solve(n)
    except EOFError:
        break