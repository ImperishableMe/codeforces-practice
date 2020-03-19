#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,k;

vector<ll> powers_to_check(ll k){
    ll bound = 1e16 + 10;
    vector<ll> v;
    ll p = 1;
    while(p < bound) {
        v.push_back(p);
        p *= k;
    }
    return v;
}

void solve(){
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0 ; i < n; i++) cin >> v[i] ;

    map < ll, int > cnt;

    vector<ll> p = powers_to_check(k);
    reverse(p.begin(), p.end());

    for(auto x : v){
        vector < ll > tmp;
        for(auto pp : p) {
            if(pp <= x) x -= pp, tmp.push_back(pp);
        }
        if(x > 0 ) {
            cout << "NO\n";
            return ;
        }
        for(auto y : tmp) cnt[y]++;
    }
    
    for(auto x : cnt) {
        if(x.second > 1 ) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){ solve(); }

    return 0;
}