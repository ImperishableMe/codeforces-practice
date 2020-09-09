#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int par[30];
int Find(int u){
    return par[u] = (par[u] == u)? u : Find(par[u]);
}
void Union(int u, int v){
    int U = Find(u);
    int V = Find(v);
    if(U != V) par[U] = V;
}
void solve(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    set<int> st[30] ;
    for(int i = 0; i < 30 ; i++) par[i] = i;
    for(int i = 0; i < n; i++) {
        int c1 = a[i] - 'a';
        int c2 = b[i] - 'a';
        if (c1 > c2) { cout << "-1\n"; return; }
        if(c1 < c2) st[c2].insert(c1);
    }
    int ans = 0;
    for(int i = 0; i < 20 ; i++){
        set<int> tmp;
        for(int x : st[i]) tmp.insert(Find(x));
        if(!tmp.empty()) ans += tmp.size();
        for(int x : st[i]) Union(x,i);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}