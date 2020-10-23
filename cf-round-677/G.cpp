#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
using PII = pair<int,int>;
using ll = long long int;
vector < PII > g[N] ;
ll const INF = 1e15;

vector < ll > dijkastra(int src, int a, int b){
    vector <ll> d(N + 1, INF);
    d[src] = 0;
    priority_queue < PII, vector < PII > , greater < PII > > pq;
    pq.push({0,src});

    while(pq.size()){
        auto x = pq.top(); pq.pop();
        if(x.first > d[x.second]) continue;
        int u = x.second, c = x.first;
        assert(d[u] == c);

        for(auto &e : g[u]){
            if( (e.first == a or e.first == b) and (u == a or u == b)) continue;
            if( d[e.first] > d[u] + e.second){
                d[e.first] = d[u] + e.second;
                pq.push({d[e.first], e.first});
            }
        }
    }
    return d;
}
int n, m, k;
vector <ll> pair_dist[N] ;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    
    vector < PII > e;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
        e.emplace_back(a, b);
    } 
    for(int i = 1; i <= n; i++){
        pair_dist[i] = dijkastra(i, -1, -1);
    }
    // for(int i = 1; i <= n; i++){
    //     cout << pair_dist[1][i] << " " ;
    // }
    vector < PII > routes;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        routes.emplace_back(a, b);
    }

    ll ans = INF, can;
    for(auto &x : e){
        vector <ll> d1 = dijkastra(x.first, x.first, x.second);
        vector<ll> d2 = dijkastra(x.second, x.first, x.second);

        ll can = 0;
        for(auto &r : routes){
            int u, v;
            tie(u, v) = r;
            can += min( pair_dist[u][v], min( d1[u] + d2[v],  d1[v] + d2[u]));
        }
        ans = min(ans, can);
    }
    cout << ans << '\n';
}