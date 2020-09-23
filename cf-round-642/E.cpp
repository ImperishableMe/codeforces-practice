#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
vector <int> pref, dp;
int n,k;
string s;

int cnt(int l, int r){
    if( l > r or l > n) return 0;
    r = min(r, n);
    return pref[r] - pref[l - 1] ;
}
void solve(){
    cin >> n >> k;
    pref.resize(n + 10), dp.resize(n + 10);    
    fill(pref.begin(), pref.end(), 0);
    fill(dp.begin(), dp.end(), n + 100);
    cin >> s;
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + ( s[i] == '1');
        // cout << " ind " << i + 1 << " " << pref[i + 1] << endl;
    }
    dp[n] = s[n-1] == '0';

    for(int i = n - 1; i > 0; i--){
        // cout << i << " " <<  cnt(i + 1, i + k - 1) << endl;
        dp[i] = (s[i - 1] == '0') + cnt(i + 1, i + k - 1);
        if(i + k <= n) dp[i] += dp[i + k];
        // cout << i << " " << dp[i] << endl;
        dp[i] = min(dp[i] , (s[i-1] == '0') + cnt(i + 1, n));
    }
    int ans = pref[n];
    for(int i = 1; i <= n; i++){
        ans = min(ans, cnt(1, i - 1) + dp[i] );
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