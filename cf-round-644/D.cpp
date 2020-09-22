#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, k;
    cin >> n >> k;
    set < ll > divi;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0) divi.insert(i), divi.insert(n/i);
    }
    ll can = n + 1;
    for(auto x : divi){
        if(x <= k) can = x;
    }
    cout << n / can << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}