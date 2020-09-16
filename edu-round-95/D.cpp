#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    set < ll > p;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp; p.insert(tmp);
    }
    multiset < ll , greater< ll > > diff;
    ll mx = -1;
    for(auto it = p.begin() ; it != p.end(); it++){
        auto nit = next(it);
        if(nit == p.end() ) continue;
        diff.insert(*nit - *it);
        mx = max(mx, *nit - *it);
    }
    cout << *prev(p.end()) - *p.begin() - ((mx == -1)? 0 : mx) << '\n';
    while(q--){
        int t, v;
        cin >> t >> v;
        // cout << " hell : " << t << " " << v << endl;
        // cout << "p size() " << p.size() << endl;
        if(t){
            if(p.empty()) p.insert(v);
            else {
                auto pore = p.upper_bound(v);
                if(pore != p.end()){
                    diff.insert( *pore - v);
                    if(pore != p.begin()) {
                        diff.insert(v - *prev(pore));
                        diff.erase(diff.find(*pore  - *prev(pore)));
                    }
                }
                else {
                    assert(pore != p.begin());
                    diff.insert( v - *prev(pore) );
                }
                p.insert(v);
            }
        }
        else {
            auto now = p.find(v);
            if(next(now) != p.end()){
                diff.erase( diff.find(*next(now) - *now) );
                if( now != p.begin()) {
                    diff.insert( *next(now) - *prev(now));
                }
            }
            if(now != p.begin()) {
                diff.erase( diff.find( v - *prev(now)));
            }
            p.erase(now);
        }
        if(p.size()){
            int c = *prev(p.end()) - *p.begin();
            if(diff.size()) c -= *diff.begin();
            cout << c << '\n';
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}