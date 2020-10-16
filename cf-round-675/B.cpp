#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 110;
bool vis[N][N];
void solve(){
    int n, m;
    cin >> n >> m;
    vector < vector < ll > > a(n , vector < ll> (m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    ll ans = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j]) continue;
            multiset < ll > ms;
            if(! vis[i][j] ) ms.insert(a[i][j]), vis[i][j] = 1;
            if(! vis[n-1-i][j] ) ms.insert(a[n-1-i][j]), vis[n-1-i][j] = 1;
            if(! vis[i][m-1-j] ) ms.insert(a[i][m-1-j]), vis[i][m-1-j] = 1;
            if(! vis[n-1-i][m-1-j] ) ms.insert(a[n-1-i][m-1-j]), vis[n-1-i][m-1-j] = 1;
            ll val = *ms.begin();
            if(ms.size() > 1) val = *next(ms.begin());
            for(auto x : ms) ans += abs(x - val);
        }
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