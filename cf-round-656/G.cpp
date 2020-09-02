#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
int const N = 3 * 2e5 + 10;
bool can_do = true;
vector<PII> g[N];
int vis[N];
vector<int> pairs[2];

void dfs(int u){
    for(auto v : g[u]){
        int vv = v.first;
        if(vis[vv] == -1) vis[vv] = vis[u]^v.second, dfs(v.first);
        can_do &= (vis[vv]^vis[u]) == v.second;
    }
    pairs[vis[u]].push_back(u);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        can_do = true;
        for(int i = 0; i < 3*n; i++) g[i].clear();
        vector<vector<int>> a(2, vector<int>(n+1));
        vector< vector<PII> > occur(n);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++) {
                cin >> a[i][j] ; a[i][j]--;
                occur[a[i][j]].push_back({j,i}); 
            }
        }
        for(int i = 0; i < n; i++){
            if(occur[i].size() != 2) can_do = false;
        }
        if(!can_do){
            cout << "-1\n"; continue;
        }

        for(int i = 0; i < n; i++){
            assert(occur[i].size() == 2);
            PII u = occur[i][0], v = occur[i][1];
            if(u.first % n == v.first % n) continue;
            int tp = u.second == v.second;
            g[u.first].push_back({v.first, tp}), g[v.first].push_back({u.first,tp});
        }

/*         for(int i = 0; i < 2*n; i++){
            cout << i << ": " ;
            for(auto x : g[i]) cout << x << " " ;
            cout << endl;
        } */
        fill(vis, vis + n + 1, -1);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                pairs[0].clear(), pairs[1].clear();
                dfs(i);
                if(pairs[0].size() > pairs[1].size()) swap(pairs[0],pairs[1]);
                while(pairs[0].size()) ans.push_back(pairs[0].back()), pairs[0].pop_back();
            }
        }
        if(!can_do) {
            cout << "-1\n" ; continue;
        }
        cout << ans.size() << '\n';
        for(int x : ans) cout << x + 1 << " " ;
        cout << '\n';
    }
}