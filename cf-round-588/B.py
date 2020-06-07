import sys
input = sys.stdin.readline

n,k = map(int,input().split())
s = str(input())

if n == 1 :
    pass
else :
    cnt, can_zero  = 0, False
    i = 0;
    while(i < n) :
        if i == 0 :
            if s.index(i) == '1' : continue
            if cnt < k : 
