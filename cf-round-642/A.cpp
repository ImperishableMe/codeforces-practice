#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, m;
    cin >> n >> m;
    if(n == 1) cout << "0\n";
    else if( n < 3) cout << m << '\n';
    else cout << 2 * m << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}