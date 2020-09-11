#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v( n);
        int rp = 0, wp = 0;
        for(int i = 1 ; i <= n; i++){
            cin >> v[i-1] ;
            if(v[i-1] == i) rp++;
            if(v[i-1] != i) wp++;
        }
        while(!v.empty() and v.back() == v.size()) v.pop_back();
        int cnt = 0;
        for(int i = 1; i <= v.size(); i++) {
            if(v[i-1] == i) cnt++;
            else break;
        }
        // cout << v.size() << " " << wp << " " << cnt << endl;
        if(rp == n) cout << "0\n";
        else if(wp == n or wp + cnt == v.size()) cout << "1\n";
        else cout << "2\n";
    }
}