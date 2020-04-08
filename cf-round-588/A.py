from itertools import permutations
tot,ans = 0,0
def backtrack(pos,sum):
    if pos == 4 :
        global ans
        ans = ans or (2*sum == tot)
        return 
    backtrack(pos+1,sum)
    backtrack(pos+1,sum+li[pos])

li = list(map(int,input().split()))
#print(*li)
tot = sum(li)
backtrack(0,0)
print(["NO","YES"][ans])
li.sort()

for b in permutations(li) : 
    print(*b)