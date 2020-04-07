#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    map<ll,int> cnt;
    vector<ll>b(n),a(n);
    for(auto &x : a) cin >> x, cnt[x]++;
    for(auto &x : b) cin >> x;
    vector<int>taken_id, not_taken;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt[a[i]] > 1 ) taken_id.emplace_back(i) , ans += b[i];
        else not_taken.emplace_back(i);
    }
    for(auto x : not_taken){
        bool pos = 0;
        for(auto y : taken_id){
            if((a[x] & a[y]) == a[x] ) pos = 1;
        }
        if(pos) ans += b[x] ;
    }
    cout << ans << endl;
    return 0;
}
