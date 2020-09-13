#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int mex(set < int > &s){
    int m = 0;
    while(s.find(m) != s.end()) m++;
    return m;
}
void solve(){
    int n;
    cin >> n;
    vector<int> cnt(110, 0);
    set < int > a , b;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for(int i = 0; i < 110; i++){
        if(cnt[i] >= 2) a.insert(i), b.insert(i);
        else if(cnt[i] == 1) a.insert(i); 
    }
    cout << mex(a) + mex(b) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}