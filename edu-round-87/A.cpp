#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if( a <= b) {
        cout << b << '\n' ; return;
    }
    a -= b ;
    if(c <= d){
        cout << "-1\n"; return ;
    }
    cout << b + ( ( a + ( c - d - 1) ) / (c - d) ) * c << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}