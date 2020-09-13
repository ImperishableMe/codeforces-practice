#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll const N = 1e5 + 10;
ll t[N] ;

void update(int pos, ll val){
    for( ; pos < N ; pos += (pos & -pos) ) t[pos] += val;
}
ll Q(int pos){
    ll r = 0;
    for( ; pos ; pos -= (pos & -pos) ) r += t[pos];
    return r;
}
ll ans(ll k){
    ll a1 = Q(1);
    return (a1 + k + ( (a1 + k)%2 + 2 ) % 2 )/ 2;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n; 
    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i] , update(i, v[i]), update(i+1, -v[i]);
    int q;
    cin >> q;
    ll k = 0;
    for(int i = 2; i <= n; i++){
        k += max(0LL, v[i] - v[i-1]);
    }
    cout << ans(k) << '\n';
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        if(l > 1){
            ll cur = Q(l);
            ll bef = Q(l-1);
            if(cur > bef) k -= cur - bef;
            k += max(0LL, cur + x - bef);
        }
        if(r < n){
            ll cur = Q(r), nxt = Q(r + 1);
            if(nxt > cur) k -= nxt - cur;
            k += max(0LL, nxt - cur - x);
        }
        update(l, x); update(r + 1, -x);
        cout << ans(k) << '\n';
    }
}