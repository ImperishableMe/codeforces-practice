import sys
input = sys.stdin.readline
n = int(input())
s = str(input().strip())
L,R,LS,RS = 0,0,0,0

for ch in s[:n//2] :
    if ch == '?' : L += 1
    else : LS += int(ch)
for ch in s[n//2:] : 
    if ch == '?' : R += 1
    else : RS += int(ch)


diff = LS - RS
ans = ((R-L)//2)*9 == diff

print(['Monocarp','Bicarp'][ans])



#print(['NO','YES'][])