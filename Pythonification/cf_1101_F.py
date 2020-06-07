def solution(l):
    # Your code here
    dp = [ 0 for i in range(len(l)) ] 
    
    for i in range(len(l)):
        for j in range(i):
            if l[i] % l[j] == 0: 
                dp[i] += 1 

#    print(*dp)

    ans = 0
    for i in range(len(l)):
        for j in range(i):
            if l[i] % l[j] == 0 : 
                ans += dp[j] 
    
    return ans

print(solution([1,1,1]))