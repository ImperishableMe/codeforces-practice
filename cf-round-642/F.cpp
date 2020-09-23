#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll const INF = 1e18;

ll diff_calc(ll a, ll b){
    if(a < b) return INF;
    return a - b;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector< vector<ll> > a(n, vector<ll> (m)), dp(n, vector<ll> (m));
    for(auto &x : a) {
        for(auto &y : x) cin >> y;
    }
    ll ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll cur_init = a[i][j] - i - j;
            dp[0][0] = diff_calc( a[0][0], cur_init);
            for(int k = 0; k < n; k++){
                for(int l = 0; l < m; l++){
                    if(!k and !l) continue;
                    dp[k][l] = diff_calc( a[k][l], cur_init + k + l);
                    if(dp[k][l] == INF) continue;
                    ll c1 = INF, c2 = INF;
                    if(k) c1 = dp[k - 1][l];
                    if(l) c2 = dp[k][l - 1];
                    if(min(c1, c2) == INF) dp[k][l] = INF;
                    else dp[k][l] += min(c1, c2);
                }
            }
            ans = min(ans, dp[n-1][m-1]);
        }
    } 
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}