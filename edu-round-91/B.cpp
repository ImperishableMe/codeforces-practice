#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    char ch[] = {'R','P','S'};
    map < char, int > ind ;
    ind['R'] = 0, ind['P'] = 1, ind['S'] = 2;

    string s;
    cin >> s;
    map < char, int> cnt;
    for(auto x : s) cnt[x]++;
    char c ;
    int how = 0;
    for(auto x : cnt){
        if(x.second > how) how = x.second, c = x.first;
    }
    char ans =  ch [ (ind[c] + 1) % 3] ;
    string ss;
    while(ss.size() < s.size()) ss += ans;
    cout << ss << '\n';


}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}