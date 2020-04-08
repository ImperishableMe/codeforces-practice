#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 300;
int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b , ll mod = MOD){
    if(!b) return 1;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b&1) 
        x = (x*a)%MOD;
    return x;
}
ll dp[N][N];
ll nc[N][N];

ll ncr(int n,int r){
    if(n < r) return 0;
    if(n == r or r == 0) return 1;
    ll &ret = nc[n][r];
    if(ret != -1) return ret;
    ret = 0;
    ret = (ncr(n-1,r)+ncr(n-1,r-1)) ;
    if(ret >= MOD) 
        ret -= MOD;
    return ret;
}
ll n,k;
ll p1[N],p2[N];

ll power(ll x,ll b){
    if(b < 0) return 0;
    if(x == k) return p1[b] ;
    else if(x == k-1) return p2[b];
    assert(false);
    //return bigmod(x,b);
}
ll DP(int row,int bc){
    if(row == n + 1){
        return bc == n ;
    }
    ll &ret = dp[row][bc] ;
    if(ret  != -1) return ret;
    ret = 0;
    for(int cov = bc; cov <= n; cov++){
        if(cov == bc){
            ret += ( power(k,cov) - power(k-1,cov) + MOD ) * power(k-1,n-cov) % MOD *DP(row+1,cov) % MOD;
            ret %= MOD;
        }
        else {
            int ex = cov - bc;
            ret += ncr(n-bc,ex)*(power(k,cov-ex))%MOD*(power(k-1,n-cov))%MOD *DP(row+1,cov) % MOD;
            ret %= MOD;
        }
    }
    return ret;
}
int main(){
    memset(nc,-1,sizeof nc);
    memset(dp,-1,sizeof dp);
    cin >> n >> k;

    p1[0] = p2[0] = 1;
    for(int i = 1; i < N; i++)
        p1[i] = (p1[i-1]*k)%MOD, p2[i] = (p2[i-1]*(k-1)) %MOD;

    cout << DP(1,0) << endl;
}