#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    map < int , int > cnt;
    deque < int > dq;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }
    int ans = 0, left = 0;
    for(int i = 1; i <= n; i++){
        int can = ( left + cnt[i] ) / i ;
        ans += can;
        left = ( left + cnt[i]) % i;
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