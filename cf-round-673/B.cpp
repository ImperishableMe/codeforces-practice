#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, T;
    cin >> n >> T;
    vector< ll > v(n);
    // if(T == 0){ 
    //     return;
    // }
    
    for(auto &x : v) cin >> x;
    map < ll, int > col;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] * 2 == T) cnt++;
        if(v[i] > T) col[v[i]] = 1;
        else if( col.count(T - v[i])) col[v[i]] = 1 - col[T - v[i]];
        else col[v[i]] = 0;
    }
    int cur = 0;
    vector < int > ans(n);
    for(int i = 0; i < n ; i++){
        if(v[i] * 2 == T){
            if(cur * 2 < cnt) ans[i] = 0;
            else ans[i] = 1;
            cur++;
        }
        else ans[i] = col[v[i]];
        cout << ans[i] << " ";
    }
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