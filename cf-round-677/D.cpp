#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair <int,int>;

void solve(){
    int n;
    cin >> n;
    map < int, vector < int > > mp;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        mp[tmp].push_back(i+1);
    }
    if(mp.size() == 1){
        cout << "NO\n"; return;
    }
    int a, b;
    a = mp.begin()->second.back();
    b = (next(mp.begin()))->second.back();
    vector < PII > e;
    for(auto x : mp){
        vector <int> &v = x.second;
        int now = a;
        if(v.back() == a) {
            v.pop_back(); now = b;
        }
        for(auto& el : v) e.emplace_back(now, el);
    }
    assert(e.size() + 1 == n);
    cout << "YES\n";
    for(auto &x : e) cout << x.first << " " << x.second << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}