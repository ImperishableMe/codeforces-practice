#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    set < int > st[m+1];
    vector<int> whr(n+1);
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp ; st[tmp].insert(i+1);
        whr[i+1] = tmp;
    }
    int ans = 0;
    for(int i = 1; i + 1 <= n; i++){
        if(whr[i] != whr[i+1]) ans++;
    }
    cout << ans << '\n';
    m--;
    while(m--){
        int a,b;
        cin >> a >> b;
        if(st[a].size() < st[b].size()) swap(st[a], st[b]);
        for(auto x : st[b]){
            ans -= st[a].count(x+1) + st[a].count(x-1);
        }
        for(auto x : st[b]) st[a].insert(x);
        cout << ans << '\n';
    }
}