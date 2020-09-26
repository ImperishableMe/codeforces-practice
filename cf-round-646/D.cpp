#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
int cnt = 0;
vector < int > g[N] ;

int Q(int l, int r) {
    cnt++;
    assert(cnt <= 12);
    cout << "? " << r - l + 1 << " " ;
    for(int i = l; i <= r; i++) cout << i << " ";
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve(){
    cnt = 0;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) g[i].clear();
    vector< vector < int > > s(k);
    for(int i = 0; i < k; i++){
        int sz;
        cin >> sz;
        while(sz--){
            int x; cin >> x;
            s[i].push_back(x);
            g[x].push_back(i);
        }
    }
    int mx = Q(1, n);
    int lo = 1, hi = n;
    while(lo < hi){
        int mid = ( lo + hi)>> 1;
        int now = Q(lo, mid);
        if( now < mx) lo = mid + 1;
        else hi = mid; 
    }
    assert( g[lo].size() <= 1);
    if(g[lo].empty()) {
        cout << "! ";
        for(int i = 1; i <= k; i++) cout << mx << " ";
        cout << endl;
    }
    else {
        vector< int > ans(k, mx);
        int st = g[lo].front();
        set < int > ask; for(int i = 1; i <= n; i++) ask.insert(i);
        for(int x : s[st]){ 
            ask.erase(x);
        }
        cout << "? " << ask.size() << " ";
        for(auto x : ask) cout << x << " ";
        cout << endl;
        cin >> ans[st] ;
        cout << "! " ;
        for(int i = 0; i < k; i++) cout << ans[i] << " ";
        cout << endl;
    }
    string sis;
    cin >> sis;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}