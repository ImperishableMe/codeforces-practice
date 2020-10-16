#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair < int,int >;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    multiset < PII > ms;
    vector < int > v;
    s += '#';
    for(int i = 0; i < n; ){
        int j = i;
        while(i < n && s[j] == s[i]) i++;
        ms.insert({v.size(), i - j});
        v.push_back(i - j);
    }
    ll ans = 0;
    for(int i = 0; i < v.size(); i++){
        
        while( ms.size() and (*ms.begin()).first < i) ms.erase(ms.begin());

        if(v[i] > 1){
            ans++; ms.erase({i, v[i]});
        }   
        else if(v[i] == 1){
            while( ms.size() and (*ms.begin()).second == 1) ms.erase(ms.begin());
            if(ms.empty()){
                ans++, i++;
            }
            else {
                auto top = *ms.begin();
                assert( top.first > i);
                v[top.first]--;
                ms.erase(ms.begin());
                ms.insert({top.first, v[top.first]});
                ans++;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}