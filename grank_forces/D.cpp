#include <bits/stdc++.h>
using namespace std;
using PII = pair <int,int>;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < PII > rob(n), light(m), need;
    for(auto &x : rob) cin >> x.first >> x.second;
    for(auto &x : light) cin >> x.first >> x.second;

    for(auto &x : rob){
        for(auto &y : light){
            need.emplace_back( max(0, y.first - x.first + 1), max(0, y.second - x.second + 1));
        }
    }
    int ans = 1e9 ;
    sort(need.begin(), need.end());
    vector < int > suf_max(need.size() + 1, 0);
    for(int i = (int)need.size() - 1; i >= 0; i--){
        suf_max[i] = max(suf_max[i + 1], need[i].second);
    }
    int cur = 0;
    for(int x = 0; x <= (1e6) + 10; x++){
        int _y = 0;
        while( cur < need.size() and need[cur].first <= x) cur++;

        if(cur < need.size()) _y = suf_max[cur];
        ans = min(ans, x + _y);
    }
    cout << ans << endl;
    return 0;
}