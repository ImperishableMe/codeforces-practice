#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair <int,int>;

void solve(){
    int n;
    cin >> n;

    vector <PII> v(n);
    vector <int> L, R;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v[i] = {l, r};
        L.push_back(l);
        R.push_back(r);
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int ans = n + 1;

    for (auto [l, r] : v) {
        int del_l = upper_bound(R.begin(), R.end(), l-1) - R.begin();
        int del_r = lower_bound(L.begin(), L.end(), r+1) - L.begin();
        del_r = n - del_r;
        ans = min(ans, del_r + del_l);
    }

    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}