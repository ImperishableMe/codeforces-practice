from random import shuffle
#tuple (s,f,c,r) 
def can(v, pos) :
    s,f,c,r = buses[pos]
    s -= 1
    f -= 1
    cap = v
    refill_count = 0
    for i in range(s,f):
        diff = (cities[i+1] - cities[i]) * c
        if diff > v: return False
        if diff > cap : 
            cap = v - diff
            refill_count += 1
        else :
            cap -= diff
        #print("i : {} cap : {} refill_count :{}".format(i,cap,refill_count))
    return refill_count <= r 

def binary_search(pos) :
    lo, hi, ans  = 0,10**16, 10**16

    while lo <= hi : 
        mid = (lo + hi) // 2
        if can(mid,pos) :
            ans = min(ans,mid)
            hi = mid -1
        else :
            lo = mid + 1
    return ans

n, m = map(int,input().split())
cities = list(map(int,input().split()))
#print(n,m)
buses = [(0,0,0,0)]*m

for _ in range(m) :
    buses[_] = tuple(map(int,input().split()))

shuffle(buses)

ans = 0
for _ in range(m) :
    if not can(ans,_) : ans = binary_search(_)

print(ans)
    