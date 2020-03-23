def solve(n) :
    li = list(map(int,input().split()))
    tot = 0
    for i in range(n-1) : 
        tot += li[i] 
        if tot <= 0 :
            return False
    tot = 0
    for i in reversed(range(1,n)) : 
        tot += li[i] 
        if tot <= 0 : 
            return False
    
    return True

t = int(input())

for _ in range(t) : 
    n = int(input())
    print( "YES" if solve(n) else "NO") 
