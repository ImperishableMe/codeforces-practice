#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int x;
    cin >> x;
    int ans = 0;
    for(int i = 1; i <= 9; i++){
        if(x % 10 == i) {
            ans += 10 * (i - 1);
        }
    }
    int cnt = 0;
    while( x ) {
        x /= 10;
        cnt++;
        ans += cnt;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}