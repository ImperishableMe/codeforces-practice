
def is_non_decreasing(l):
    if len(l) <= 1 : return True

    for i in range(1,len(l)):
        if l[i]< l[i-1] :
            return False

    return True
t = int(input())

for _ in range(t):
    n = int(input())
    a = [ int(i) for i in input().split()]
    b = [ int(i) for i in input().split()]

    l,r = [],[]
    
    for i in range(len(a)):
        if b[i] :
            r.append(a[i])
        else :
            l.append(a[i])
    
    ans = True
    if len(l) == 0 and not is_non_decreasing(r):
        ans = False
    elif len(r) == 0 and not is_non_decreasing(l) :
        ans = False

    print("Yes" if ans else "No")
