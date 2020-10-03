#include <bits/stdc++.h>
using namespace std;
using PII = pair <int,int> ;
int const N = 5e5 + 10;
PII e[N], queries[N];
int p[N], par[N], proc_help[N]; 
vector < int > dsu[N];
void MERGE(int eid, int qid){
    int u,v;
    tie(u, v) = e[eid];
    int U = par[u], V = par[v];
    if(U == V) {
        if(qid) proc_help[qid] = -1; 
        return;
    }
    if(dsu[U].size() < dsu[V].size()) swap(U,V);

    for(auto &x : dsu[V]) dsu[U].push_back(x), par[x] = U;
    proc_help[qid] =  V;

}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> p[i] ;
    for(int i = 1; i <= m; i++){
        cin >> e[i].first >> e[i].second;
    }
    vector< bool > cant_do(m + 1, 0);
    for(int i = 1; i <= n; i++) par[i] = i, dsu[i].push_back(i);
    for(int i = 1; i <= q; i++){
        cin >> queries[i].first >> queries[i].second;
        if(queries[i].first == 2) cant_do[queries[i].second] = 1; 
    }
    for(int i = 1; i <= m; i++){
        if(!cant_do[i]) MERGE(i, 0);
    }
    for(int i = q; i > 0; i--){
        if(queries[i].first == 1) continue;
        int eid = queries[i].second;
        MERGE(eid, i);
    }
    auto comp = [](int a, int b)-> bool {
        return p[a] < p[b];
    };
    for(int i = 1; i <= n; i++){
        sort(dsu[i].begin(), dsu[i].end(), comp);
    }
    vector < bool > taken(n + 1, 0);
    for(int i = 1; i <= q; i++){
        int type, val;
        tie(type, val) = queries[i];
        if(type == 1){
            int boss = par[val] ;
            vector < int > &v = dsu[boss] ;
            while( v.size() and ( par[v.back()] != boss or taken[v.back()]) ) v.pop_back();
            if(v.size()) {
                cout << p[v.back()] << '\n'; taken[v.back()] = 1;
            }
            else cout << '0' << '\n';
        }
        else {
            if(proc_help[i] == -1) continue;
            int boss = proc_help[i] ;
            for(auto x : dsu[boss]) par[x] = boss;
        }
    }
    return 0;
}