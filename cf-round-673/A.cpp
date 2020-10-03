#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n, k;
    cin >> n >> k;
    vector< ll > v(n);
    for(auto &x : v) cin >> x;
    ll ans = 0;
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++){
        int cnt = 0;
        while(v[i] + v[0] <= k) v[i] += v[0], cnt++;
        ans += cnt;
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