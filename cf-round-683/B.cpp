#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n, m;
    cin >> n >> m;
    vector < int > v(n*m);
    int sum = 0, mn = 101010, neg_c = 0;

    for(auto &x : v) {
        cin >> x;
        sum += abs(x);
        if (x < 0) neg_c++;
        mn = min(mn, abs(x));
    }
    if (neg_c & 1) sum -= 2 * abs(mn);
    cout << sum << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}