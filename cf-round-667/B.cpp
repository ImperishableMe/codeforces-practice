#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll c1 = max(x, a - n);
        ll c2 = max(y, b - n);
        if( c1 > c2) swap(x,y), swap(a,b);
        ll tmp = min(n,a-x);
        a -= tmp;
        n -= tmp;
        b -= min(n, b - y);
        cout << a * b << '\n';
    }
}