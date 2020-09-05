#include <bits/stdc++.h>
using namespace std;
int const N = 4010;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(2*n);
        for(int i = 0; i <  2*n; i++) cin >> v[i] ;
        vector<int> imp;
        imp.push_back(0);
        int mx = v[0];
        for(int i = 1; i < 2 * n;i++) {
            if( v[i] > mx ) mx = v[i], imp.push_back(i);
        }
        map <int, int > cnt;
        for(int i = 1; i < imp.size(); i++) cnt[imp[i]-imp[i-1]]++;
        vector<int> need(2*n+5, 0), vis(2*n+5, 0);
        vis[0] = true;
        for(auto x : cnt){
            int val = x.first , q = x.second;
            fill(need.begin(),need.end(), 0);
            for(int i = 0; i <= 2*n; i++){
                if(!vis[i] and i >= val and vis[i - val] and need[i-val] < q)
                    vis[i] = true, need[i] = need[i-val] + 1;
            }
        }
        cout << (vis[n] ? "YES":"NO") << '\n';
    }
}