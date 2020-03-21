import math 

t = int(input())

for _ in range(t):
    n,d = map(int,input().split())
    ans = 0
    for x in range(0,10**5):
        tmp = x + math.ceil(d/(x+1))
        if tmp <= n : 
            ans = 1
    print(["YES","NO"][1-ans])
    
