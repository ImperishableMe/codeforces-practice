#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair<int,int>;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    if(n == 1) {
        cout << v.back() << '\n';
        return ;
    }
    int mx = *max_element(v.begin(), v.end());
    sort(v.begin(), v.end());
    cout << v.back() << " ";
    int gcd = v.back();
    v.pop_back();
    vector<int> vis(v.size(), 0);
    int ind = -1, can = 0;

    int cnt = 0;
    while(cnt < v.size()){
        int can = 0, ind = -1;
        for(int i = 0; i < v.size(); i++){
            if(vis[i]) continue;
            int g = __gcd(gcd, v[i]);
            if(g >= can) {
                can = g, ind = i;
            }
        }
        cout << v[ind] << " ";
        vis[ind] = 1;
        gcd = __gcd(gcd, v[ind]);
        cnt++;
    }

    cout << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}