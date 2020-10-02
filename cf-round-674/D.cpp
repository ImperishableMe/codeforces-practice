#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector < ll > v(n);
    map < ll, int > cnt;
    cnt[0] = 1;
    for(auto &x : v) cin >> x;
    ll cur = 0, ans = 0;
    for(int i = 0; i < n; i++){
        cur += v[i] ;
        if(cnt.count(cur)) ans++, cnt.clear(), cnt[0] = 1, cur = v[i];
        cnt[cur]++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}