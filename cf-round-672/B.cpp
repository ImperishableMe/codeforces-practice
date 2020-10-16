#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    multiset < ll > s;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    ll ans = 0;
    for(int pos = 32; pos >= 0; pos--){
        ll cnt = 0;
        for(auto it = s.begin(); it != s.end(); ){
            if( (*it) & (1LL<< pos) ) cnt++, it = s.erase(it);
            else it++;
        }
        ans += (cnt * (cnt - 1) / 2);
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