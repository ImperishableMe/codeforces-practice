t = int(input())

for _ in range(t):

    n = int(input())

    a = [ int(i) for i in input().split() ]
    b = [ int(i) for i in input().split() ]

    pos = True

    for i in range((n+1)//2) :
        sa = set()
        sb = set()
        sa.add(a[i])
        sa.add(a[n-i-1])
        sb.add(b[i])
        sb.add(b[n-i-1])
        
        # print(sa)
        # print(sb)

        if sa != sb :
            pos = False
        

    print("Yes" if pos else "No")