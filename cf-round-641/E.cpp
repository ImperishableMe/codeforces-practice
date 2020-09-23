#include <bits/stdc++.h>
using namespace std;
using PII = pair < int, int >;

int const N = 1010;
vector<string> g;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int cid[N][N], vis[N][N], dist[N][N];
vector<int> comps;

int dfs(int x, int y, int c){
    vis[x][y] = 1;
    cid[x][y] = c;
    int sz = 1;
    for(int i = 0; i < 4; i++){
        int _x = x + dx[i] , _y = y + dy[i] ;
        if(_x < 0 or _x >= g.size() or _y < 0 or _y >= g[0].size()) continue;
        if(vis[_x][_y]) continue;
        if(g[_x][_y] == g[x][y] ) sz += dfs(_x, _y, c);
    }
    return sz;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    g.resize(n);
    for(auto &x : g) cin >> x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j]){
                int sz = dfs(i, j, comps.size());
                comps.push_back(sz);
            }
        }
    }
    // cout << "COMPS : " ;
    // for(auto x : comps) cout << x << " " ;
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << cid[i][j] << " \n"[j + 1 == m];
    //     }
    // }
    memset(vis, 0, sizeof vis);
    memset(dist, -1, sizeof dist);
    queue <PII> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( comps[cid[i][j]] > 1){
                q.push( {i,j});
                vis[i][j] = 1, dist[i][j] = 0;
            }
        }
    }
    while( q.size()){
        auto u = q.front();
        q.pop();
        int x = u.first, y = u.second;
        for(int i = 0; i < 4; i++){
            int _x = x + dx[i], _y = y + dy[i] ;
            if(_x < 0 or _x >= g.size() or _y < 0 or _y >= g[0].size()) continue;
            if(vis[_x][_y]) continue;
            vis[_x][_y] = 1;
            dist[_x][_y] = dist[x][y] + 1;
            q.push({_x, _y});
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dist[i][j] << " \n"[j + 1 == m];
    //     }

    while(t--){
        long long x, y, p;
        cin >> x >> y >> p;
        x--, y--;
        if(dist[x][y] > p or dist[x][y] == -1) {
            cout << g[x][y] << '\n';
        }
        else {
            p -= dist[x][y];
            cout << ((p & 1)? (char)('1' - g[x][y] + '0') : g[x][y]) << '\n';
        }
    }    
}