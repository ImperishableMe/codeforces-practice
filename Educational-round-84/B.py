import io
import os
import sys
from io import BytesIO
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def solve() :
    n = int(input())
    g = [ list(map(int,input().split()))[1:] for i in range(n)] 
    
    kingdom_left, left = set(range(1,n+1)) , list(range(1,n+1))
    for _ in range(n) :
        for cur in g[_] :
            if  cur in kingdom_left : 
                kingdom_left.remove(cur)
                break
        else :  left.append(_+1)

    if len(left) and len(kingdom_left):
        print("IMPROVE\n{} {}".format(left[-1],kingdom_left.pop()))
    else :
        print("OPTIMAL")

t = int(input())
for _ in range(t) :
    solve()
