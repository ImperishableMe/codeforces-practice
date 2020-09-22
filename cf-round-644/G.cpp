#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if( n * a != m * b) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    vector< string > g(n);
    vector <int> col(m,b);
    for(int i = 0; i < n; i++){
        int row = 0;
        for(int j = 0; j < m; j++){
            if(row < a and col[j]){
                col[j]--;
                row++; g[i] += '1';
            }
            else g[i] += '0';
        }
        assert(row == a);
    }
    for(int i = 0; i < n; i++)
        cout << g[i] << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}