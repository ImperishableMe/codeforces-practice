import sys
input = sys.stdin.readline
N = 2*10**5 + 10
st,en = [0]*N, [0]*N
p = [-1]*N
g = [ [] for _ in range(N)]
dist = [0]*N
stack = []
def isPar(u,v) :
    return st[u] <= st[v] and en[v] <= en[u] 

def dfs():
    vis = [False]*N
    stack.append((1,-1,0))
    
    T = 0
    while stack :
        u,pr,d = stack[-1]
        if not vis[u] :
            vis[u] = True
            st[u] = T
            T += 1
            p[u] = pr
            dist[u] = d
            for v in g[u] : 
                if v == pr : continue
                stack.append((v,u,d+1))
        else :
            en[u] = T
            T += 1
            stack.pop()
n,m = map(int,input().split())
for _ in range(n-1) :
    u, v = map(int,input().split())
    g[u].append(v)
    g[v].append(u)
dfs()
for _ in range(m):
    li = list(map(int,input().split()))[1:]
    for i in range(len(li)) : 
        #print("{} par {}".format(li[i],par[]))
        if p[li[i]] != -1 : li[i] = p[li[i]]
        else : li[i] = 1
    down = li[0] 
    for el in li :
        if dist[down] < dist[el] : down = el
    ok = True
    #print(li)
    for el in li : 
        ok = ok and isPar(el,down)
    print(["NO","YES"][ok])

