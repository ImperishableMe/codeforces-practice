#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair < int,int>;
int const N = 1e5 + 10;
vector<int> g[N] ;
int n;
vector<int> cen;
int sub[N];
void dfs(int u, int p){
    sub[u] = 1;
    bool c = 1;
    for(int v : g[u]){
        if(v == p) continue;
        dfs(v,u);
        sub[u] += sub[v];
        if(sub[v] > n / 2) c = 0;
    }
    if( n - sub[u] > n / 2 ) c = 0;
    if(c) cen.push_back(u);
}

PII dfs2(int u, int p){
    if(g[u].size() == 1) {
        return {u,p};
    }
    for(int v : g[u]){
        if(v == p) continue;
        return dfs2(v,u);
    }
}
void solve(){
    cin >> n;

    for(int i = 0; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    dfs(1,0);
    if(cen.size() == 1){
        cout << cen.back() << " " << g[cen.back()][0] << '\n';
        cout << cen.back() << " " << g[cen.back()][0] << '\n';
    }
    else {
        assert(cen.size() == 2);
        int u = cen.front(), v = cen.back();
        auto x = dfs2(u,v);
        cout << x.first << " " << x.second << '\n';
        cout << v << " " << x.first << '\n';
    }
    cen.clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}