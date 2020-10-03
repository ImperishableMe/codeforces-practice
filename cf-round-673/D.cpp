#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using tp = tuple < ll, ll, ll>;
void solve(){
    ll n;
    cin >> n;
    vector < ll > v(n + 1);
    ll tot = 0;
    for(int i = 1; i <= n; i++) cin >> v[i], tot += v[i];
    if(tot % n != 0) {
        cout << "-1\n"; return;
    }
    vector < tp > ans;
    ll tar = tot / n;
    int first = 1;
    for(int i = 1; i <= n; i++){
        if(v[i] >= i){
            first = i;
            break;
        }
    }
    if(first != 1) {
        v[first] -= first;
        ans.push_back(make_tuple(first, 1, 1));
        v[1] += first;
    }
    for(int i = 2; i <= n; i++){
        ll need = i - (v[i] % i);
        if(need != i){
            ans.push_back(make_tuple(1, i, need ));            
            v[1] -= need, v[i] += need;
        }
        assert( v[i] % i == 0);
        ans.push_back(make_tuple(i, 1, v[i] / i));
        v[1] += v[i] , v[i] = 0;
    }
    for(int i = 2; i <= n; i++){
        ans.push_back(make_tuple(1, i, tar));
        v[1] -= tar, v[i] += tar;
    }
    // for(int i = 1; i <= n; i++){
    //     cout << v[i] << " " ;
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i++) cout << v[i] << " ";
    // cout << endl;
    for(int i = 1; i <= n; i++) assert(v[i] == tar);
    assert(ans.size() <= 3 * n);
    cout << ans.size() << '\n';
    for(auto x : ans){
        ll a, b, c;
        tie(a,b,c) = x;
        cout << a << " " << b << " " << c << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}