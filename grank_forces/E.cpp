#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using tp = tuple < int, int, ll> ;
int const N = 3e5 + 100;
int par[N];
ll ans = 0 ;
int GET(int p){
    return par[p] = (par[p] == p)? p : GET(par[p]);
}
void Union(tp e){
    ll u, v, c;
    tie(u, v, c) = e;
    int U = GET(u), V = GET(v);
    if(U == V){
        ans += c; return;
    }
    par[U] = V;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m ;
    cin >> m >> n;
    vector < ll > a(m + 1), b(n + 1);
    for(int i = 1; i <= m; i++){
        cin >> a[i] ;
    }
    for(int i = 1; i <= n; i++) cin >> b[i] ;
    for(int i = 1; i <= n + m + 1; i++) par[i] = i;
    vector < tp > edges;
    for(int i = 1; i <= m; i++){
        int s;
        cin >> s;
        while(s--){
            int x ; cin >> x;
            edges.emplace_back(i, x + m, a[i] + b[x] );
        }
    }
    auto cmp = [](tp a, tp b)-> bool {
        return get<2>(a) > get<2>(b);
    };
    sort(edges.begin(), edges.end(), cmp);
    
    for(auto &x : edges){
        Union(x);
    }
    cout << ans << '\n';
}