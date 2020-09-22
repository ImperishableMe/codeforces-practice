#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll a, b;
    cin >> a >> b;
    if( a < b) swap(a,b);
    cout << max(2 * b,a) * max(2 * b,a) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}