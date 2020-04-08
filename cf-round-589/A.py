
#print(diff(98766))
l,r = map(int,input().split())
for _ in range(l,r+1):
    if len(set(str(_))) == len(str(_)) :
        print(_)
        exit(0)
print("-1")