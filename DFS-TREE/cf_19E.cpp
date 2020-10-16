#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
int const N = 1e4 + 10;
vector<int> g[N];
int good[N], bad[N], lvl[N];
map<PII,int> edge_id;
int odd_cycle_cnt;

void dfs(int u){
    for(int v : g[u]){
        if(lvl[v] == -1){
            lvl[v] = lvl[u] + 1;
            dfs(v);
        }
        else if(lvl[u] < lvl[v] and ((lvl[u] + lvl[v])% 2 == 0)) // different parity
            odd_cycle_cnt++;
    }
}
vector<int> ans;

void dfs2(int u, int tot){
    good[u] = 0;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge_id[{a,b}] = edge_id[{b,a}] = i+1;
    }
    memset(lvl,-1,sizeof lvl);
    int cnt = 0;
    vector<PII> non_bip;
    for(int i = 1 ; i <= n; i++){
        if(lvl[i] == -1){
            lvl[i] = 0;
            odd_cycle_cnt = 0;
            dfs(i);
            if (odd_cycle_cnt)
                cnt++, non_bip.push_back({i,odd_cycle_cnt});
        }
    }
    cout << "hello " << endl;
    for(auto x : non_bip){
        cout << x.first << " " << x.second << endl;
    }
    memset(lvl, -1, sizeof lvl);
    if(non_bip.size() > 1){
        cout << "0\n"; return 0;
    }
    if(non_bip.size() == 0){
        cout << m << "\n";
        for(int i = 1; i <= m; i++) cout << i << " ";
        cout << '\n';
        return 0;
    }
    else{
        lvl[non_bip.back().first] = 0;
        dfs2(non_bip.back().first, non_bip.back().second);
        // dfs2(non_bip.back());
    }
}