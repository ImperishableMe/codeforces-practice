#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n;
    cin >> n;
    vector < ll > fact(20 + 1, 1);
    for(int i = 1; i <= 20; i++) fact[i] = fact[i-1] * i;
    ll half = n / 2;
    ll hf = 1, ff = 1;
    for(int i = 1; i <= n; i++){
        if(i <= half) hf *= i;
        ff *= i;
    }
    cout << ( ff / hf / hf / 2 ) * fact[n/2 - 1] * fact[n/2 - 1] << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
        solve();
}