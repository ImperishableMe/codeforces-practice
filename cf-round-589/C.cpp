#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 10;
vector<ll> primes;
vector<bool>mark(N,0);
int const MOD = 1e9 + 7;


vector<ll> factorize(ll n){
    vector<ll> v;
    for(ll x = 2; x * x <= n; x++){
        if(n % x == 0){
            while(n % x == 0) n /= x;
            v.push_back(x);
        }
    }
    if(n != 1) v.push_back(n);
    return v;
}

ll bigmod(ll a, ll b , ll mod = MOD){
    if(!b) return 1;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b&1) 
        x = (x*a)%MOD;
    return x;
}

int main(){
    ll x,n;
    cin >> x >> n;
    //sieve();
    vector <ll> pd = factorize(x);
    ll ans = 1;
    for(auto x : pd){
        ll tot = n/x;
        ll init = x;
        while(init * 1.0 * x < 2e18 and init * x <= n){
            init *= x;
            tot += (n/init);
        }
        ans = (ans * bigmod(x%MOD,tot)) % MOD;
    }
    cout << ans << '\n';
}