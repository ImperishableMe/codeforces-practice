#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, x;
    cin >> n >> x;
    if(n <= 2) {
        cout << "1\n"; return;
    }
    cout << 1 + ( n - 2 + x - 1) / x << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}