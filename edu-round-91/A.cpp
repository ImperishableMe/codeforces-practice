#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector<int>p(n);
    for(auto &x : p) cin >> x;
    for(int i = 0; i < n; i++){
        int can = p[i] , ind = i;
        for(int j = i + 1; j < n; j++){
            if(p[j] < can and can > p[i] ) {
                cout << "YES\n";
                cout << i + 1 << " " << ind + 1 << " " << j + 1 << '\n';
                return ;
            }
            if(p[j] > can ) can = p[j] , ind = j;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}