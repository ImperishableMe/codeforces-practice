#include <bits/stdc++.h>
using namespace std;
int const N = 5e5 + 10;
using PII = pair <int,int>;
vector<PII> g[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,t;
        cin >> a >> b >> t;
        g[b].push_back({a,t});
    }
    int inf = n + 1;
    vector<int> w(n+1,inf), b(n+1, inf), col(n+1), cnt(n+1,0);
    w[n] = b[n] = 0;
    cnt[n] = 3;
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(max(w[u], b[u]) > n ) continue;
        for(auto x : g[u]){
            int v = x.first, type = x.second;
            if(type){
                if(w[v] > n ) w[v] = 1 + max(w[u], b[u]), cnt[v]++;
            }
            else {
                if(b[v] > n) b[v] = 1 + max(w[u], b[u]), cnt[v]++;
            }
            if(cnt[v] == 2){
                q.push(v);
                cnt[v] = 3;
            }
        }
    }
    cout << ( (max(w[1], b[1]) > n)? -1: max(w[1], b[1]) ) << endl;
    for(int i = 1; i <= n; i++) cout << ((w[i] > b[i]) ? '1': '0') ;
    // for(int i = 1; i <= n; i++){
    //     cout << i << " " << w[i] << " " << b[i] << endl;
    // }
    cout << endl;
}