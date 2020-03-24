
def solve():
    input()
    s = str(input())
    
    s = s.lstrip('P')
    #print(s.split('A'))
    ans = max ( map(lambda x : len(x) ,s.split('A')) )
    print(ans)

t = int(input())
for _ in range(t): 
    solve()
