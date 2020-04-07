#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 3e5 + 10;
ll dp[N][2];
vector<ll>v,cost;
ll DP(int pos,int last){
    if(pos == v.size()) return 0;
    if(dp[pos][last] != -1) return dp[pos][last] ;
    ll &ret = dp[pos][last] ;
    ret = 2e18;
    if(v[pos-1] + last == v[pos]){
        ret = min(ret, cost[pos-1] + DP(pos+1,0));
        ret = min(ret,cost[pos] + DP(pos+1,1));
    }

}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        //vector < ll > v(n);
        v.resize(n), cost.resize(n);
        for(int i = 0; i <= n;i++){
            for(int j = 0; j < 2; j++) dp[i][j] = -1;
        }
        for(int i = 0;i < n; i++) cin >> v[i] >> cost[i];
        cout << min(DP(0,0),cost[i] + DP(0,1)) << '\n';
    }
    return 0;
}
