#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, k;
    cin >> n >> k;
    assert(n > 1);
    ll ans = 0;
    vector < ll > v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    ans += v.back();
    v.pop_back();
    while(k and v.size()) ans += v.back(), v.pop_back(), k--;

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