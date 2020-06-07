#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>p(n+1);
        for(int i = 1 ; i <= n; i++) cin >> p[i] ;
        vector<int>mark(n+1,0);
        vector<int>ans(n+1,0);
        vector<int> found;
        int cnt = 0;
        int st = 1;
        for(int i = 1; i <= n; i++){
            if(!mark[i]){
                vector<int>cycle;
                int _p = i;
                while(!mark[_p]){
                    mark[_p] = 1;
                    cycle.push_back(_p);
                    _p = p[_p] ;
                }
                for(auto x : cycle) ans[x] = cycle.size();
                cycle.clear();
            }
        }
        for(int i = 1; i <= n; i++) cout << ans[i] << " " ;
        cout << endl;
    }

}
