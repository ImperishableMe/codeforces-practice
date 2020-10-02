#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n;
    cin >> n;
    ll ans = 1e18;
    int up = sqrt(n + 10) + 1;
    for(ll i = 1; i <= up ; i++){
        ans = min(ans, i - 2 + (n + i - 1) / i);
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