#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 3; i <= n; i += 2){
        ans += (1LL * 4 * i - 4) * ( i / 2) ;
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