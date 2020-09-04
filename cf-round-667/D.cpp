#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int cnt_dig(ll n){
    int cnt = 0;
    while(n) n /= 10, cnt++;
    return cnt;
}
ll sum(ll n){
    int s = 0;
    while(n) s += n % 10, n /= 10;
    return s;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, s;
        cin >> n >> s ;
        ll ds = sum(n);
        if(ds <= s) {
            cout << "0\n";
        }
        else {
            ll num = 0, tmp = cnt_dig(n);
            ll mod = 10, t_n = n;
            while(sum(n) > s){
                num += mod - (n % mod);
                n += mod - (n % mod);
                mod *= 10;
            }
            cout << num << '\n';
        }
    }
}