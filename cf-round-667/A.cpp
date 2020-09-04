#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans = 0, m = abs(a-b);
        for(int i = 10;  i > 0; i--){
            ans += m / i;
            m = m % i;
        }
        cout << ans << '\n';
    }
}