t = int(input())
for _ in range(t) :
    n,k = map(int,input().split())
    ans = n - (k-1)*(k-1)
    print(["YES","NO"][not(ans & 1 and ans > (2*k-3))])
    