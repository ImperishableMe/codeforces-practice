
def solve(A,B) : 
    second = 9
    ans = 0
    while second <= B : 
        ans += A 
        second = second * 10 + 9
    print(ans)

t = int(input())

for _ in range(t) :
    solve(*map(int,input().split()))