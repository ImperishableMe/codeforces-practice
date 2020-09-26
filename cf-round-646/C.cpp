#include <bits/stdc++.h>
using namespace std;
int const N = 1010;

void solve(){
    int n, x;
    cin >> n >> x;
    vector < int > deg(n + 1, 0);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        deg[a]++, deg[b]++;
    }
    bool win = 0;
    if(n <= 2 or deg[x] == 1 or deg[x] > 1 and (( n - 3 ) & 1) ) win = 1;
    cout << ( win? "Ayush": "Ashish") << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t; while(t--) solve();
}
