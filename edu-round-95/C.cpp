#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 2e5 + 10;
ll dp[2][N], a[N];
int n;
ll DP(int is_you, int pos){
    if(pos >= n) return 0;
    ll &ret = dp[is_you][pos];
    if(ret != -1) return ret;
    if(pos < n){
        ret = DP(is_you ^ 1, pos + 1 ) + ( a[pos] && !is_you );
    }
    if(pos + 1 < n) {
        ret = min( ret, DP( is_you ^ 1, pos + 2) + ( a[pos] && !is_you)
            + ( a[pos + 1] && !is_you) );
    }
    return ret;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] ;
    for(int i = 0; i < n + 10; i++) dp[0][i] = dp[1][i] = -1;
    cout << DP(0, 0) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}