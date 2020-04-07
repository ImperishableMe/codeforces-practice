#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;
int const MOD = 1e9 + 7;

ll bigmod(ll a,ll b){
    if(!b) return 1;
    ll x = bigmod(a,b/2);x = (x*x)% MOD;
    if(b&1) x = (x*a)%MOD; 
    return x;
}
ll d,m;

ll dp[50] ;
ll msb;

ll DP(int pos){
    //if(pos = =0)
    if(pos == msb) {   
        return (2 + d - (1LL<<msb) + m) % m;
    }
    ll &ret = dp[pos] ;

    if(ret != -1){
        return ret;
    }
    ret = 0;
    ret = DP(pos+1);
    ll cnt = 1;
    if(pos) cnt = 1LL<<(pos);
    ret = (ret + cnt * DP(pos+1)) % m;
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        msb = 0;
        cin >> d >> m;
        for(int i = 0; i < 31; i++){
            if((1LL<<i)&d)
                msb = i;
        }
        cout <<  ((DP(0) - 1 + m) % m)<< '\n';
    }
    return 0;
}
