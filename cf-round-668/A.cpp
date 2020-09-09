#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector<int>p(n);
    for(auto &x : p) cin >>x;
    reverse(p.begin(), p.end());
    for(auto x : p) cout << x << " ";
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}