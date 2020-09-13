#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
bool cmp(ll a, ll b){
    return labs(a) > labs(b);
}
void solve(){
    int n;
    cin >> n;
    vector<ll> v(n), vp, vn;
    ll neg = 0;
    for(ll &x : v) {
        cin >> x , neg += (x <= 0);
        if(x >= 0) vp.push_back(x);
        else vn.push_back(x);
    }
    if(neg == n){
        sort(v.rbegin(), v.rend());
        ll ans = 1;
        for(int i = 0; i < 5; i++) ans *= v[i] ;
        cout << ans << '\n';
        return ;
    }
    ll ans = -1e18;
    sort(vn.begin(), vn.end());
    sort(vp.rbegin(), vp.rend());

    for(int i = 0; i <= min(5,(int)vn.size()); i += 2){
        ll c1 = 1;
        for(int j   = 0; j < i ; j++) c1 *= vn[j] ;
        int p = 5 - i;
        if(p > vp.size()) continue;
        for(int x = 0; x < p; x++) c1 *= vp[x];

        ans = max(ans,c1);
    }
    reverse(vn.begin(), vn.end());
    reverse(vp.begin(), vp.end());
    for(int i = 1; i <= min(5, (int)vn.size()); i+= 2){
        ll c1 = 1;
        for(int j = 0; j < i; j++) c1*= vn[j] ;
        int p = 5 - i;
        if(p > vp.size()) continue;
        for(int x = 0; x < p; x++) c1 *= vp[x];
        ans = max(ans, c1);
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