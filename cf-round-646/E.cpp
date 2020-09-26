#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 2e5 + 10;
ll dp[N], one_zero[N], zero_one[N], has[N], want[N], cost[N];
vector < int > g[N];
ll const inf = 1e18;
multiset < ll > ancestor_cost;
ll ans;
void dfs(int u, int p){
    ancestor_cost.insert(cost[u]);
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v,u);
        one_zero[u] += one_zero[v];
        zero_one[u] += zero_one[v];
    }
    int mn = min(one_zero[u], zero_one[u]);
    ans += 2LL * mn * (*ancestor_cost.begin());
    one_zero[u] -= mn, zero_one[u] -= mn;
    ancestor_cost.erase( ancestor_cost.find(cost[u]));
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i] >> has[i] >> want[i];
        if(has[i] == 0 and want[i] == 1) zero_one[i] = 1;
        else if(has[i] == 1 and want[i] == 0) one_zero[i] = 1;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1,-1);
    if(one_zero[1] or zero_one[1]){
        cout << "-1\n";
    }
    else cout << ans << '\n';
}