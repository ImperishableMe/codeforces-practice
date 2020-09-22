#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 2e6 + 10;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector< ll > v(N, 0), cum(N, 0);
    ll X = b - a + 1 , Y = c - b + 1, Z = d - c + 1;
    for(int y = b; y <= c; y++){
        v[y + a]++, v[y + b + 1]--;
    }
    for(int i = 1; i < N; i++) v[i] += v[i - 1] , cum[i] = cum[i-1] + v[i] ;
    ll ans = (X * Y * Z);
    for(int z = c; z <= d; z++){
        ans -= cum[z];
    }
    cout << ans << endl;
    return 0;
}