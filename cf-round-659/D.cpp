#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n), bit(31, 0);
    for(auto &x : v) cin >> x;
    for(auto x : v){
        int cnt = 0;
        while(x) bit[cnt] += x & 1, x >>= 1, cnt++;
    }
    for(int i = 30 ; i >= 0; i--){
        if(bit[i] % 2 == 0) continue;
        // cout << i << " " << bit[i] << endl;
        int l = n - bit[i] ;
        if(bit[i] % 4 == 1) cout << "WIN\n";
        else if(bit[i] % 4 == 3){
            cout << (l&1? "WIN":"LOSE") << '\n';
        }
        return ;
    }
    cout << "DRAW\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}