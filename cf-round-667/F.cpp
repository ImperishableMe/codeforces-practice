#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 210;
ll dp[N][N][N] ;
int n,k;
string s, t;

ll DP(ll pos, ll l, ll prev){
    if(pos == n){
        return 0;
    }
    ll &ret = dp[pos][l][prev] ;
    if(ret != -1) return ret;
    ret = 0;
    if(s[pos] == t[0]) {
        ret = max(ret, DP(pos+1, l , prev + 1));
}
    else if(s[pos] == t[1]) {
        ret = max(ret, DP(pos+1, l, prev) + prev) ;
    }
    ret = max(ret, DP(pos+1, l, prev));
    if(l > 0){
        ret = max(ret, DP(pos+1, l - 1, prev+1));
        ret = max(ret, prev + DP(pos+1, l - 1, prev));
    }
    return ret;
}

int main(){
    cin >> n >> k >> s >> t;
    memset(dp,-1,sizeof dp);
    if(t[0] == t[1]){
        ll cnt = 0;
        for(auto x : s) if(x == t[0]) cnt++;
        cnt = min(n* 1LL, cnt + k);
        cout << cnt * (cnt-1) / 2 << '\n';
        return 0;
    }
    cout << DP(0,k,0) << '\n';
}