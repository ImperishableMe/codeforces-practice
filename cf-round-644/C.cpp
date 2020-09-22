#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector<int> cnt(2,0), v(n);
    for(int &x : v) cin >> x, cnt[x & 1] ++;
    int sim = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++) sim += abs(v[i] - v[j]) == 1;
    }
    if(cnt[0] % 2 == 0 and cnt[1] % 2 == 0) cout << "YES\n";
    else if( sim ) cout << "YES\n";
    else cout <<"NO\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}