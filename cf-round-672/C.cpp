#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
vector<int> v, critical;
ll ans = 0;

void insert(int l ){
    if(v[l] > v[l + 1] and v[l] > v[l - 1]) ans += v[l];
    else if(v[l] < v[l + 1] and v[l] < v[l - 1]) ans -= v[l] ;
}
void erase(int l){
    if(v[l] > v[l + 1] and v[l] > v[l - 1]) ans -= v[l];
    else if(v[l] < v[l + 1] and v[l] < v[l - 1]) ans += v[l] ;
}
void solve(){
    int n, q;
    cin >> n >> q;
    ans = 0;
    v.resize(n + 2), critical.resize(n + 2, 0);
    v[0] = v[n + 1] = 0;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        insert(i);
    }
    cout << ans << '\n';
    auto ins = [](int l) {
        if(v[l] > v[l + 1] and v[l] > v[l - 1]) ans += v[l];
        else if(v[l] < v[l + 1] and v[l] < v[l - 1]) ans -= v[l] ;
    };
    while(q--){
        int l, r;
        cin >> l >> r;
        set < int > point_of_interest;
        for(int i = max(1, l-1 ) ; i <= min(n, l + 1); i++) point_of_interest.insert(i);
        for(int i = max(1, r -1 ) ; i <= min(n, r + 1); i++) point_of_interest.insert(i);
        for(auto x : point_of_interest){
            erase(x);
        }
        swap(v[l] , v[r]);
        for(auto x : point_of_interest) ins(x);
        cout << ans << '\n';
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