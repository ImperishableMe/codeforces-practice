#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector< int > v(n + 1) , dp(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> v[i] ;
    dp[1] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i], 1);
        for(int j = 2 * i ; j <= n ; j += i){
            if( v[j] > v[i] ) dp[j] = max(dp[j] , 1 + dp[i]);
        }
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}