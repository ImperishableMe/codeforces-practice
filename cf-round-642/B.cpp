#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n, k;
    cin >> n >> k;
    vector< int > a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    int cnt = 0, ans = 0;
    while(a.size() and b.size() and a.back() < b.back() and cnt < k){
        ans += b.back();
        a.pop_back(), b.pop_back(), cnt++;
    }
    for(auto x : a) ans += x;
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