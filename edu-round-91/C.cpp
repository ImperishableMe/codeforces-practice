#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 1e5 + 10;
int dp[N], cnt[N], val[N];
int n, x;

int DP(int pos){
    if(pos >= n) return 0;
    int &ret = dp[pos] ;
    if(ret != -1) return ret;
    ret = DP(pos+1);
    int jump = (x + val[pos] - 1) / val[pos];
    if(pos + jump <= n){
        ret = max(ret, 1 + DP(pos + jump));
    }
    return ret;
}
void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> val[i] ;
    sort(val, val + n);
    fill(dp, dp + n + 5, -1);
    cout << DP(0) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}