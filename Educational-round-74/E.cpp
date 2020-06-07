#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 21;
ll cnt[N][N] ;
string s;
int n,m;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i + 1 < s.size(); i++){
        cnt[s[i]-'a'][s[i+1]-'a']++;
        cnt[s[i+1]-'a'][s[i]-'a']++;
    }
    vector<ll> dp((1<<m)+100,1e18);
    dp[0] = 0;

    for(int msk = 1; msk < (1<<m); msk++){
        for(int now = 0; now < m; now++){
            if(!(msk&(1<<now))) continue;
            ll tmp = 0;
            int cc = __builtin_popcount(msk);
            for(int nxt = 0; nxt < m; nxt++){
                if(nxt == now) continue;
                if(msk&(1<<nxt)) tmp += cnt[now][nxt] *  cc ;
                else    tmp -= cnt[now][nxt] * cc;
            }
            dp[msk] = min(dp[msk], tmp + dp[msk^(1<<now)]);
        }
    }
    cout << dp[(1<<m)-1] << endl;
    return 0;
}
