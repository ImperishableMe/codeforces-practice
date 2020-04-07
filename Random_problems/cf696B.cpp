#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
vector < double > st(N);
vector < int > g[N] ;
vector < int > sub(N,0);
void dfs(int u,int path = 1, double expected = 0){
    //sub[u] = 1;
    
    if(g[u].size() == 1) {
        dfs(g[u].back(),path+1,expected);
    }
    else {
        double tot = sub[u] - 1;
        //;
        for(auto v : g[u]) {
            dfs(v,path+1,expected + (tot - sub[v])/2.0) ;
        }
    }

    st[u] = path + expected;
}
void _sub(int u){
    sub[u] = 1;
    for(auto v : g[u]) {
        _sub(v);
        sub[u] += sub[v] ;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int p;
        cin >> p;
        g[p].push_back(i+2);
    }
    _sub(1);
    dfs(1);
    for(int i = 1; i <= n; i++) 
        cout << setprecision(10) << fixed << st[i] << " " ;
    cout << endl;

    return 0;
}