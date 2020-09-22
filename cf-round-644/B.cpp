#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    ll ans = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans = min(ans, llabs(v[i] - v[j]));
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