#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 55;
string g[N];
int row[N][N], col[N][N];
void solve(){
    int n;
    cin >> n;
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    for(int i = 0; i < n; i++){
        cin >> g[i] ;
    }
    for(int r = n - 1; r >= 0; r--){
        for(int c = n - 1; c >= 0; c--){
            if(g[r][c] == '1'){
                if(r == n - 1 or g[r + 1][c] == '1' or c == n - 1 or g[r][ c + 1] == '1') continue;
                cout << "NO\n";
                return;
            }   
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}