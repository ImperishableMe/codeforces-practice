#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll n, A, R, M;
vector<ll> h;
ll cost(int border){
    ll up = 0, down = 0;
    for(auto x : h){
        if(x > border) down += x - border;
        else up += border - x;
    }
    ll c = min(up, down) * M;
    tie(up, down) = make_pair(up - min(up, down), down - min(down, up));
    if(up) c += up * A;
    else c += down * R;
    return c;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> A >> R >> M;
    h.resize(n);
    M = min(M, A + R);
    for(int i = 0; i < n; i++) cin >> h[i] ;
    sort(h.begin(), h.end());
    int lo = h[0], hi = h.back();

    while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(cost(mid) > cost(mid + 1)) lo = mid + 1;
        else hi = mid;  
    }
    cout << cost(lo) << '\n';
    return 0;
}