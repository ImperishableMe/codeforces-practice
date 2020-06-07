MOD = 998244353 
MAX = 5*10**5 + 10
#MAX = 10

pre_mod = [1 for i in range(MAX)]
pre_inv_mod = [1]*MAX


pre_mod[0], pre_mod[1] = 1,1

for i in range(2,MAX) :
    pre_mod[i] = pre_mod[i-1] * i % MOD
    

pre_inv_mod[-1] = pow(pre_mod[-1],MOD-2,MOD)

for i in range(MAX-2,0,-1):
    pre_inv_mod[i] = pre_inv_mod[i+1] *(i+1) % MOD
    

def ncr(n,r):
    if n < r or r < 0 or n < 0:
        return 0

    #print("ncr : {} : {} {}".format(pre_mod[n],pre_inv_mod[r],pre_inv_mod[n-r]))

    return pre_mod[n] * pre_inv_mod[r] % MOD * pre_inv_mod[n-r] % MOD
    

def solve(n,k):
    
    ans = 0

    for lo in range(1,n+1):
        options = n//lo - 1
        need_to_take = k-1
        ans += ncr(options,need_to_take)
        #print("opt :{} need :{} : {} ".format(options,need_to_take,ncr(options,need_to_take)))
        ans %= MOD

    return ans

if __name__ == '__main__' :
    n,k = map(int,input().split())

    ncr(6,2)

    #print(pow(MOD,1000,MOD))
    print(solve(n,k))
