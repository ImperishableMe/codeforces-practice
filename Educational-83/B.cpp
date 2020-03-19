#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>v(n);

    for(int i = 0; i < n; i++) cin >> v[i] ;
    sort(v.begin(),v.end(), greater<int>()) ;

    for(auto x: v) cout << x << " ";
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}