#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n;
    cin >> n;
    ll t = 0, f = 0, s = 0;
    t = n / 3; n %= 3;
    if(n == 2){
        if(t) {
            t--, f++;
        }
        else {
            cout << "-1\n"; return;
        }
    }
    else if(n == 1){
        if(t > 1) {
            t-= 2, s++;
        }
        else {
            cout << "-1\n"; return;
        }
    }
    cout << t << " " << f << " " << s << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
