#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Q(int l1, int r1, int l2, int r2){
    cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << endl;
    for(int i = l1; i <= r1; i++) cout << i << " ";
    cout << endl;
    for(int i = l2; i <= r2; i++) cout << i << " ";
    cout << endl;
    cnt++;
    assert(cnt <= 50);
    string s;
    cin >> s;
    if(s.front() == 'F') return 1;
    if(s.front() == 'S') return -1;
    else return 0;
}
void solve(){
    int k;
    cin >> n >> k;
    int rnd = min(25, n - 1);
    set < int > st;
    while(rnd){
        while(true){ 
            int rn = rng() % n; rn++;
            if( rn != 1 and st.find(rn) == st.end()) {
                st.insert(rn); rnd--;
                break;
            }
        }
    }
    for(auto x : st){
        int val = Q(1, 1, x, x);
        if(val == -1){
            cout << "! 1" << endl;
            return;
        }
    }
    int i, lo = -1, hi = -1;
    for( i = 1; (1 << i) <= n; i++){
        int ret = Q(1 , 1<<(i-1), (1<<(i-1)) + 1, 1 << i);
        if(ret == 1){
            lo = (1 << ( i - 1)) + 1;
            hi = 1 << i;
            break;
        }
        assert( ret != -1);
    }
    i--;
    if( lo == -1) lo = (1 << i) + 1, hi = n;
    while(lo < hi){
        int mid = ( lo + hi) / 2;
        int len = mid - lo + 1;
        int ret = Q(1, len, lo, mid);
        if(ret == 1) hi = mid;
        else lo = mid + 1;
    }
    cout << "! " << lo << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cnt = 0;
    }
}