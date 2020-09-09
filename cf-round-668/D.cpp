#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 1e5 + 10;
vector<int> g[N] ;
int vis[N] ;
int dist[N] ;

void dfs(int u,int lvl){
    dist[u] = lvl;
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v]) dfs(v,lvl+1);
    }
}
void solve(){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    for(int i = 1; i <= n; i++) g[i].clear();

    for(int i = 0; i < n - 1; i++) {
        int a,b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    fill(vis, vis + n + 1, 0);
    dfs(b,0);
    int x = dist[a] ;
    if(x <= da) {
        cout << "Alice\n"; return ;
    }
    if(da * 2 >= db) {
        cout << "Alice\n"; return;
    }
    int mx_node = max_element(dist + 1, dist + n + 1) - dist;
    fill(vis, vis + n + 1, 0);
    dfs(mx_node, 0);
    int dim = *max_element(dist + 1, dist + n + 1);

    // cout << "dim " << dim << endl;
    if(dim <= 2 * da) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}