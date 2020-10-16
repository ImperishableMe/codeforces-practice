#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 10;
int t[N];
int Q(int pos){
    int ret = 0;
    while(pos){
        ret += t[pos] ;
        pos -= (pos & -pos);
    }
    return ret;
}
void update(int pos, int val){
    for( ; pos < N; pos += (pos & -pos)) t[pos] += val;
}
int K_th(int cum){
    int ans = 0, tot = 0;
    for(int pos = 20; pos >=0 ; pos--){
        if( (1 << pos) >= N) continue;
        if( tot + t[ ans ^ (1 << pos) ] < cum ) ans ^= ( 1 << pos ), tot += t[ans] ;
    }
    return ans + 1;
}
int k_b(int cum){
    int lo = 1, hi = N - 1, ret = N - 1;
    while(lo <= hi){
        int mid = ( lo + hi + 1) / 2;
        if( Q(mid) >= cum) ret = min(ret, mid), hi = mid - 1;
        else lo = mid + 1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        update(tmp, 1);
    }
    while(q--){
        int tmp;
        cin >> tmp;
        if( tmp > 0 ){
            update(tmp, 1);
        }
        else {
            tmp *= -1;
            int kpos = K_th(tmp);
            // cout << kpos << endl;
            update(kpos, -1 );
        }
    }

    for(int i = 1; i <= n; i++){
        if( Q(i) ) return cout << i << endl, 0;
    }
    cout << "0\n";
}