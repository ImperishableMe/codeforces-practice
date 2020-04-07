#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector< vector<ll> > v(n,vector<ll>(n));

    for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++) cin >> v[i][j];
    vector < ll > ans(n);
    ans[0] = (v[1][0]*v[0][2]) / v[1][2] ;
    ans[0] = (ll)(sqrt(ans[0]) + 1e-9);

    for(int i = 1; i < n; i++){
        ans[i] = v[0][i] / ans[0] ;
    }
    for(auto x : ans) cout << x << " " ;
    cout << endl;
    return 0;
}
