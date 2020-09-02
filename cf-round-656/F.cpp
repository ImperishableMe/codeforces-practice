#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
int const N = 2e5 + 10;
set<int>g[N], leaves[N] ;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) g[i].clear(), leaves[i].clear();
        vector<int> deg(n+1,0);
        for(int i = 0; i < n - 1; i++){
            int a,b;
            cin >> a >> b; g[a].insert(b); g[b].insert(a);
            deg[a]++, deg[b]++;
        }
        if(k == 1) {
            cout << n - 1 << '\n'; continue;
        }
        set < PII, greater<PII> > st;
        for(int i = 1; i <= n; i++){
            if(deg[i] == 1){
                auto par = *g[i].begin();
                leaves[par].insert(i);
            }
        }
        for(int i = 1; i <= n; i++){
            if(leaves[i].size()) st.insert({leaves[i].size(),i});
        }
        int ans = 0;
        while(true){
            auto top = *st.begin();  st.erase(st.begin());
            if(top.first < k) break;
            int cnt = 0;
            int u = top.second;
            while(cnt < k){
                auto now = *leaves[u].begin(); leaves[u].erase(now);
                st.erase({leaves[now].size(), now});
                g[u].erase(now);
                leaves[now].erase(u);
                cnt++;
            }
            st.insert({leaves[u].size(), u});
            if(g[u].size() == 1){
                auto v = *g[u].begin();
                st.erase({leaves[v].size(), v});
                leaves[v].insert(u);
                st.insert({leaves[v].size(), v});
            }
            ans++;
        }   
/*         while(!can_delete.empty()){
            auto now = *can_delete.begin();
            int cnt = 0;
            while(cnt < k){
                int cur = *leaves[now].begin();
                g[now].erase(cur);
                g[cur].erase(now);
                leaves[now].erase(cur);
                if(leaves[cur].count(now)) leaves[cur].erase(now);
                cnt++;
            }
            if(leaves[now].size() < k) can_delete.erase(now);
            if(!leaves[now].size()) {
                for(auto x : g[now]) {
                    if(leaves[now].count(x)) continue;
                    leaves[x].insert(now);
                    if(leaves[x].size() >= k) can_delete.insert(x);
                }
            }
            ans++;
        } */
        cout << ans << endl;
    }
}