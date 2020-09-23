#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    if(n == 1) {
        cout << (( v[0] == k)? "YES" : "NO") << '\n';
        return;
    }
    bool k_found = 0, pair_found = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == k) k_found = 1;
        int j = i + 1, j2 = i + 2;
        if(v[i] >= k and ((j < n and v[j] >= k) or (j2 < n and v[j2] >= k))) pair_found = 1;
    }
    cout << ( ( k_found and pair_found) ? "YES" : "NO") << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}