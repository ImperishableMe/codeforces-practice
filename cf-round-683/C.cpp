#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair < ll, ll>;

void solve(){
    ll n, w;
    cin >> n >> w;
    vector < PLL > v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    vector < int > inds;
    ll sum = 0;

    for (int i = 0; i < n; i++){
        if (v[i].first >= (w+1)/2 and v[i].first <= w) {
            cout << "1\n";
            cout << v[i].second + 1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        ll tmp = sum + v[i].first;

        if (tmp <= w) {
            sum += v[i].first;
            inds.push_back(v[i].second);
        }
        else break;
    }
    if (sum >= (w+1)/2 and sum <= w) {
        cout << inds.size() << '\n';
        for (auto x : inds) cout << x + 1 << " ";
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}