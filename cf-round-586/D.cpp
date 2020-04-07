#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n),cnt(62,0);

    for(auto &x : v){
        cin >> x ;
        cnt[__builtin_ctzll(x)]++;
    }
    int mx = 0, id = -1;
    for(int i = 0; i < 61; i++)
        if(mx < cnt[i]) mx = cnt[i], id = i;

    cout << n - cnt[id] << endl;
    for(auto x : v){
        if(__builtin_ctzll(x) == id) continue;
        //printf("%lld ",x);
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
