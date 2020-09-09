#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set <char> st[k+1];
    for(int i = 0; i < k; i++){
        for(int j = i ; j < n ; j += k){
            if(s[j] != '?') st[i].insert(s[j]);
        }
    }
    bool can = true;
    vector<int> cnt(2,0);
    for (int i = 0; i < k; i++)
        if (st[i].size() == 2)
            can = false;
        else if(st[i].size() == 1){
            cnt[*st[i].begin()-'0']++;
        }
    if(cnt[0] * 2 > k or cnt[1] * 2 > k ) can = false;

    cout << ((can)?"YES":"NO") << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}