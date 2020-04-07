#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int const N = 2e5 + 10;
int const LG = 21;
PII sp[N][LG];
int _log2[N];
PII get_min(int l,int r){
    int p = _log2[r-l+1];
    return min(sp[l][p],sp[r-(1<<p)+1][p]);
}
int depth(int l,int r){
    if(l > r) return 0;
    if(l == r) return 1;
    if(l + 1 == r) return 2;
    PII mid = get_min(l,r);
    return max(depth(l,mid.second-1),depth(mid.second+1,r)) + 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    _log2[1] = 0;
    for(int i = 2; i < N; i++) _log2[i] = _log2[i/2] + 1;
    int n;
    cin >> n;
    if(n == 1){
        return cout << "0 0" << endl,0;
    }
    vector<int>p(n);
    int one = -1;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        if(p[i] == 1) one = i;
    }
    rotate(p.begin(),p.begin()+one,p.end());
    for(int i = 1; i < n; i++) sp[i][0] = PII(p[i],i);
    for(int lg = 1; lg < LG; lg++){
        for(int i = 1; i < n; i++){
            if(i + (1<<(lg-1)) < n)
                sp[i][lg] = min(sp[i][lg-1],sp[i+(1<<(lg-1))][lg-1]);
        }
    }
    int lo =1, hi = n - 1;
    int ans = n-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        int d1 = depth(1,mid);
        int d2 = depth(mid+1,n-1);
        if(d1 >= d2) ans = min(ans,mid), hi = mid - 1;
        else lo = mid+1;
    }
    int c1 = max(depth(1,ans),depth(ans+1,n-1)) + 1;
    int c2 = max(depth(1,ans-1),depth(ans,n-1)) + 1;
    //cout << ans << " " << c1 << " " << c2 << endl;
    if(c1 > c2) {
        swap(c1,c2);
    }
    else ans++;
    one += ans;
    one = (one + 2*n) % n;
    cout << c1 << " " << one << endl;
    return 0;
}
