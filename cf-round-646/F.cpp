#include <bits/stdc++.h>
using namespace std;
int const N = 2010;
int const inf = 1e9;
int dp[N][N], cums[27][N], cumt[27][N] ;
int n;
int _count(int wh, char ch, int l, int r){
    if(l > r) return 0;
    r = min(r, n);
    l = min(l, n);
    if(wh == 1) return cums[ch - 'a'][r] - cums[ch - 'a'][l - 1];
    return cumt[ch - 'a'][r] - cumt[ch - 'a'][l - 1];
}
void solve(){
    cin >> n;
    memset(cums, 0, sizeof cums);
    memset(cumt, 0, sizeof cumt);
    string s,t;
    cin >> s >> t;
    map < char, int > cnt;
    for(auto &x : s) cnt[x]++;
    for(auto &x : t) cnt[x]--;
    for(auto x : cnt){
        if( x.second != 0) {
            cout << "-1\n"; return;
        }
    }
    s = '#' + s, t = '#' + t;
    for(int ch = 0; ch < 27; ch++){
        for(int i = 1; i <= n; i++){
            cums[ch][i] = cums[ch][i - 1] + (s[i] -'a' == ch );
            cumt[ch][i] = cumt[ch][i - 1] + (t[i] - 'a' == ch);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(!i) {
                dp[i][j] = 0; continue;
            }
            dp[i][j] = inf;
            int &r = dp[i][j];
            r = min(r, dp[i - 1][j] + 1);
            if(s[i] == t[j]) r = min(r, dp[i-1][j-1]);
            if(_count(1,t[j], i + 1, n) > _count(2, t[j], j + 1, n)){
                r = min(r, dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][n] << '\n';

}
int main(){
    ios::sync_with_stdio(0), cin.tie(0); 
    int t; cin >> t; while(t--) solve();
}