#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const M = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < ll > power(n + 10, 1);
    vector < vector < ll > > pref(n + 10, vector < ll > (5, 0));

    string s;
    cin >> s;
    for(auto & x: s)
        if(x == '?') x = 'd';
    
    for(int ch = 1; ch <= 4; ch++){
        for(int i = 1; i <= n; i++){
            pref[i][ch] = pref[i-1][ch] + ( ch == (s[i-1] - 'a' + 1));
        }
    }
    for(int i = 1; i < n + 5; i++){
        power[i] = ( power[i-1] * 3) % M;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1 or i == n) continue;
        if(s[i-1] == 'a' or s[i-1] == 'c') continue;
        ll a = pref[i-1][1];
        ll lq = pref[i-1][4];
        ll c = pref[n][3] - pref[i][3], rq = pref[n][4] - pref[i][4] ;
        ll left_way = a * power[ lq ] ;
        if(lq) left_way += lq * power[lq - 1] ;
        left_way %= M;
        ll right_way = c * power[ rq ];
        if(rq) right_way += rq * power[ rq - 1];
        right_way %= M;
        ans = (ans + left_way * right_way) % M;
    }
    cout << ans << endl;
}