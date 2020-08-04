n = int(input())
l = [ int(i) for i in input().split() ]

ans = 0
l += [0,0]

for i in l :
    for j in l:
        for k in l :
            ans = max(ans, i | j | k)

print(ans)