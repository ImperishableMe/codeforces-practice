#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair<int,int>;

void solve(){
    ll n;
    cin >> n;
    vector < PII > ord;
    priority_queue< ll > pq;
    for(int i = 0; i < n; i++){
        pq.push(i+1);
    }
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ord.emplace_back(a,b);
        pq.push( (a + b + 1) / 2);
    }
    cout << pq.top() << '\n';
    assert(ord.size() + 1 == n);
    for(auto x : ord) cout << x.first << " " << x.second << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}