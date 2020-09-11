#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll const M = 998244353;

ll bigmod(ll a, ll b){
    if(!b) return 1;
    ll x = bigmod(a,b/2);
    x = (x * x) % M;
    if(b&1) x = (x * a) % M;
    return x;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll>v(n), pref(n,0);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end(), greater<ll>());
    for(int i = 0; i < n; i++) pref[i] = (i?pref[i-1]:0) + v[i] ;
    ll ans = 0;
    for(int k = 1; k <= n; k++){
        ans = 0;
        for(int j = k; j < n; j += k){
            ll r = min(n,j + k), l = j;
            ans += (pref[r-1] - pref[l-1]) * (j/k);
        }
        ans %= M;
        cout << ans * bigmod(n,M-2) % M << " " ;
    }
    cout << endl;
}