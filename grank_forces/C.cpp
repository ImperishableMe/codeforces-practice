#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll n, l;
vector < int > a;

bool can(double t){
    double l1 = 0, l2 = 0, v1 = 1, v2 = 1, t1 = 0, t2 = 0;
    int pos = 0;
    double last = 0;
    for(int i = 0; i < n; i++){
        if(t1 + ( a[i] - last) / v1 <= t){
            t1 += (a[i] - last) / v1;
            l1 += a[i] - last;
            last = a[i];
            v1++;
        }
        else {
            break;
        }
    }
    l1 += (t - t1) * v1;
    last = l;
    for(int i = n - 1; i >= 0; i--){
        if(t2 + (last - a[i]) / v2  <= t) {
            t2 += ( last - a[i] ) / v2;
            l2 += (last - a[i]);
            last = a[i] ;
            v2++;
        }
        else {
            break;
        }
    }
    l2 += (t - t2) * v2;

    return l1 + l2 >= l;
}
void solve(){
    cin >> n >> l;
    a.resize(n);
    for(auto &x : a) cin >> x;
    double lo = 0, hi = l;
    int cnt = 100;
    while(cnt--){
        double mid = (lo + hi) / 2;
        if(can(mid))        hi = mid;
        else                lo = mid;
    }
    cout << fixed << setprecision(9) << lo << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t ; while(t--) solve();
    return 0;
}