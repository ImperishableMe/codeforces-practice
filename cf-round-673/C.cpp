#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 3e5 + 100;
vector < int > g[N] ;
int ara[N] ;

int calc(int x){
    int diff = 0;
    for(int i = 1; i < g[x].size(); i++) {
        diff = max(diff, g[x][i] - g[x][i-1]);
    }
    return diff;
}
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) g[i].clear();
    for(int i = 1; i <= n; i++) g[i].push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> ara[i] ;
        g[ara[i]].push_back(i);
    }    
    for(int i = 1; i <= n; i++) g[i].push_back(n + 1);
    vector < int > ans(n + 1, -1);
    int up = n + 1;
    for(int i = 1; i <= n; i++){
        int con = calc(i);
        if(con >= up) continue;
        else {
            for(int j = con; j < up; j++) ans[j] = i;
            up = con;
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}