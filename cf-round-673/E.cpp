#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const LOG = 31;
ll inv[LOG][3];

int what_is_here(ll val, int bit){
    return ( val & (1LL << bit)) != 0 ;
}
void dq(vector < ll >& v, int bit){
    if(bit < 0) return ;
    vector < ll > down[2], seen(2, 0);
    ll one = 0, zero = 0;
    for(auto &x : v){
       int h = what_is_here(x, bit);
       if(!h) zero += seen[1];
       else one += seen[0];

       seen[h]++;
       down[h].push_back(x);
    }
    inv[bit][0] += zero;
    inv[bit][1] += one;
    v.clear();
    if(down[0].size()) dq(down[0], bit - 1);
    if(down[1].size()) dq(down[1], bit - 1);
}
void solve(){
    int n;
    cin >> n;
    vector < ll > v(n);
    for(auto &x : v) cin >> x;
    dq( v, 30);
    ll ans = 0, inv_ans = 0;
    for(int i = LOG - 1; i >= 0; i--){
        if(inv[i][1] < inv[i][0]) ans ^= (1LL << i);
        inv_ans += min(inv[i][1], inv[i][0]);
    }
    cout << inv_ans << " " << ans << endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}