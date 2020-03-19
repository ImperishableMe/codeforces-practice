#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll const MOD = 998244353;
int const N = 2e5 + 100;
ll fact[N] ;

ll big_mod(ll a, ll b){
    if(!b) return 1;
    ll x = big_mod(a,b/2);
    x = ( x * x ) % MOD;
    if(b & 1) return (x*a) % MOD;
    return x;
}
ll ncr(ll n,ll r){
    return (fact[n] * big_mod(fact[n-r], MOD - 2) % MOD * big_mod(fact[r], MOD - 2) % MOD) % MOD;
}
void solve(ll n,ll m){
    if(n < 3 or m < n) { cout << "0\n"; return ;}
    
    cout << ((ncr(m,n-1) * (n-2) % MOD * big_mod(2,n-3) % MOD) % MOD ) << endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;

    for(int i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % MOD;

    ll n,m;
    //cout << big_mod(2,10 )
    while(cin >> n >> m) {
        solve(n,m);
    }
    return 0;
}