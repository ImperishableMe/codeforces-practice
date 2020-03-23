import math 

def solve(n,d) :
    ans = 0
    for x in range(0,10**5):
        tmp = x + math.ceil(d/(x+1))
        if tmp <= n : 
            ans = 1
    print(["YES","NO"][1-ans])

t = int(input())
for _ in range(t):
    solve(*map(int,input().split()) )
    #print(*l)
    #print(list(l))


    
    
