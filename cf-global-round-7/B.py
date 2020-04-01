import sys
input = sys.stdin.readline
mx = 0
input()
for el in map(int,input().split()) :
    print(el + mx); mx = max(mx,el+mx)



        

