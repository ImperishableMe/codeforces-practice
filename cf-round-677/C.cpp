#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector < int > v(n);
    for(auto &x : v) cin >> x;
    int mx = *max_element(v.begin(), v.end());
    int ind = -1;
    for(int i = 0; i < n; i++){
        if(v[i] == mx){
            if( (i and v[i - 1] < mx) or (i + 1 != n and v[i+1] < mx))
                ind = i + 1 ;
        }
    }
    cout << ind << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}