#include <bits/stdc++.h>
using namespace std;
using PII = pair <int,int>;
int const N = 1e5 + 10;
vector<int> g[N];
int dp[N], lvl[N], up[N], down[N];
vector<PII> ans;
bool possible = true;

void dfs(int u,int p){
    dp[u] = 0;
    for(int v : g[u]){
        if(lvl[v] == -1) {
            lvl[v] = lvl[u] + 1;
            ans.emplace_back(u,v);
            dfs(v,u);
            dp[u] += dp[v];
        }
        else if(lvl[v] > lvl[u]) dp[u]--, ans.emplace_back(v,u);
        else if(lvl[v] < lvl[u]) dp[u]++;
    }
    dp[u]--;
    // cout << u << " " << dp[u] << endl;
    if(lvl[u] and !dp[u]) possible = false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; g[a].push_back(b); g[b].push_back(a);
    }
    memset(lvl, -1, sizeof lvl);
    lvl[1] = 0;
    dfs(1, -1);
    if(possible){
        for(auto x : ans) cout << x.first << " " << x.second << '\n';
        cout << endl;
    }
    else cout << "0\n";
    
    return 0;
}