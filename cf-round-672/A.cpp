#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    vector  < int > v(n);
    for(int &x : v) cin >> x;

    for(int i = 1; i < n; i++){
        cnt += (v[i] < v[i-1]);
    }
    if(cnt == n - 1) {
        cout << "NO\n";
    }
    else cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}