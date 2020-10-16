#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair<int,int>;
int const N = 3e5 + 10;
int x[N], y[N];
vector < PII > g[N] ;
map < int , vector < int > > mx, my;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> x[0] >> y[0] >> x[m + 1] >> y[m + 1];

    for(int i = 1; i <= m; i++) cin >> x[i] >> y[i] , mx[x[i]].push_back(i), my[y[i]].push_back(i);

    auto cmpx = []( int i, int j)->bool {
        return y[i] < y[j] ;
    };
    auto cmpy = []( int i, int j)->bool {
        return x[i] < x[j] ;
    };
    for(auto &v : mx){
        sort( v.second.begin(), v.second.end(), cmpx);
    }
    for(auto &v : my){
        sort( v.second.begin(), v.second.end(), cmpy);
    }
    int ec = 0;
    for(auto it = mx.begin(); it != mx.end(); it++){
        if(it == mx.begin()) continue;
        auto pit = prev(it);
        int cost = it->first - pit->first;
        int ua = it->second.back(), ub = pit->second.back();
        ec++;
        g[ua].emplace_back(ub, cost);            
        g[ub].emplace_back(ua, cost);            
    }
    for(auto it = my.begin(); it != my.end(); it++){
        if(it == my.begin()) continue;
        auto pit = prev(it);
        int cost = it->first - pit->first;
        int ua = it->second.back(), ub = pit->second.back();
        g[ua].emplace_back(ub, cost);            
        g[ub].emplace_back(ua, cost);            
        ec++;
    }
    for(auto &v : mx){
        for(int i = 1; i < v.second.size(); i++){
            ec++;
            int ua = v.second[i], ub = v.second[i - 1];
            g[ua].emplace_back(ub,0);
            g[ub].emplace_back(ua,0);
        }
    }
    for(auto &v : my){
        for(int i = 1; i < v.second.size(); i++){
            ec++;
            int ua = v.second[i], ub = v.second[i - 1];
            g[ua].emplace_back(ub,0);
            g[ub].emplace_back(ua,0);
        }
    }
    auto dist = [](int i, int j)->int {
        return min(abs(x[i] - x[j]), abs(y[i] - y[j]));
    };
    for(int i = 1; i <= m; i++){
        g[0].emplace_back(i, dist(0,i));
        g[i].emplace_back(0, dist(0,i));
        int d_t = abs(x[i] - x[m+1]) + abs(y[i] - y[m+1]);
        g[i].emplace_back(m+1, d_t);
    }
    int dd = abs( x[0] - x[m + 1]) + abs(y[0] - y[m+1]);
    g[0].emplace_back(m + 1, dd);
    g[m + 1].emplace_back(0, dd);
    mx.clear(), my.clear();
    ll inf = 1e12;
    vector < ll > d( m + 5, inf);
    priority_queue< PII, vector < PII > , greater < PII > > pq;
    pq.push({0, 0});
    d[0] = 0;

    // for(int i = 0; i <= m + 1; i++){
    //     cout << i << " : ";
    //     for(auto x : g[i]){
    //         cout << "(" << x.first << "," << x.second << ")" << " " ;
    //     }
    //     cout << endl;
    // }
    while(pq.size()){
        int u,c;
        tie(c,u) = pq.top(); pq.pop();
        if(d[u] < c) continue;
        for(auto pp : g[u]){
            int v, ec;
            tie(v, ec) = pp;
            if( d[v] > d[u] + ec) {
                d[v] = d[u] + ec;
                pq.push({d[v], v});
            }
        }
    }
    cout << d[m + 1] << endl;
}