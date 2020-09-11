#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        set < ll > divi;
        for(ll i = 1; i * i <= n; i++) if(n % i == 0) divi.insert(i), divi.insert(n/i);
        divi.erase(n);
        ll ans = n, ind = -1;
        for(auto x : divi){
            ll lcm = (x * (n - x) / __gcd(x,n-x));  
            if(lcm < ans) ans = lcm, ind = x;
        }
        cout << ind << " " << n - ind << "\n";
    }
}