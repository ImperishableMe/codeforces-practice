#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    ll neg = 0, pos = 0;
    for(int x : v){
        if( x > 0 ) pos += x;
        else if(x < 0){
            if(pos >= abs(x)) pos -= abs(x);
            else {
                ll cnt = min(pos, llabs(x));
                pos -= cnt;
                neg += (llabs(x) - cnt);
            }
        }
    }
    cout << neg << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}