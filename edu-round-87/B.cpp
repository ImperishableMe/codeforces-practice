#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 2e5 + 10;
ll dp[5] ;
string s;

bool can_del(int l , int r){
    return dp[s[l-1] - '1'] > 1;
}
void solve(){
    cin >> s;
    memset(dp, 0, sizeof dp);
    int l = 0;
    int ans = s.size() + 1, c = 0;
    for(int r = 1; r <= s.size() ; r++){
        dp[s[r-1]-'1']++;
        while(can_del( l + 1, r) and l + 1 < r ){
            dp[s[l] - '1']--;
            l++;
        }
        bool can = 1;
        for(int i = 0; i < 3; i++) can &= dp[i] > 0;
        if(can) ans = min(ans, r - l );
    }
    if(ans == s.size() + 1 ) ans = 0;
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