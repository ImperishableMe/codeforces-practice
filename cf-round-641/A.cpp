#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, k;
    cin >> n >> k;
    if(n & 1){
        for(int i = 2; i <= n; i++){
            if(n % i == 0){
                cout << n + (k - 1) * 2 + i << '\n';
                return ;
            }
        }
    }
    else cout << n + 2 * k << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}