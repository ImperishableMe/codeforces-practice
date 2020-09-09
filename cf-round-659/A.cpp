#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

char xchg(char c1, char c2){
    if(c1 == c2 and c1 == 'a') return 'b';
    if(c1 == c2 and c1 == 'b') return 'a';
    return c2;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    string tmp = "";
    for(int i = 0; i < 200; i++) tmp += 'a';
    vector<string> ans(n+1,tmp);
    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < a[i-1]; j++)
            ans[i][j] = ans[i-1][j];
        ans[i][a[i-1]] = xchg(ans[i-1][a[i-1]], ans[i][a[i-1]]);
    }
    for(auto x : ans) cout << x << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}