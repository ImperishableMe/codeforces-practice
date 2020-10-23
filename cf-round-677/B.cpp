#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector < int > v;
    bool one_f = 0;
    for(int i = 0; i < n; i++){
        int tmp ; cin >> tmp;
        if(tmp == 1) one_f = 1;
        if(!one_f) continue;
        v.push_back(tmp);
    }
    while(v.size() and v.back() == 0) v.pop_back();
    int ans = 0;
    for(auto x : v) ans += x == 0;
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