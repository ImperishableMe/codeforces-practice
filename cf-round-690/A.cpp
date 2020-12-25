#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    
    vector < int >  ans;
    deque < int > dq;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        dq.push_back(tmp);
    }
    bool forward = 1;
    while (dq.size()) {
        
        if (forward){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        else {
            ans.push_back(dq.back());
            dq.pop_back();
        }
        forward ^= 1;
    }

    for (auto x : ans) cout << x << " ";
    cout  << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}