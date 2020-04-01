import sys
input = sys.stdin.readline

n,k = map(int,input().split())
p = list(map(int,input().split()))
bp = [0]*(n+1)
taken = []
for id in range(n): bp[p[id]] = id

st, cnt, ans_sum = n,0,0
while cnt < k : 
    cnt += 1
    taken.append(bp[st])
    ans_sum += st
    st -= 1

taken.sort()

ans = 1
mod = 998244353
for _ in range(len(taken)) : 
    if _ == 0 : continue
    ans = (ans * (taken[_]-taken[_-1])) % mod

print("{} {}".format(ans_sum,ans))
