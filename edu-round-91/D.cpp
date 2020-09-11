#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    ll x,k,y;
    cin >> x >> k >> y;
    vector<int>a(n), b(m);
    for(int &e : a) cin >> e;
    for(int &e : b) cin >> e;
    vector<int> mark(n,0);
    int l = 0;
    for(int i = 0; i < m; i++){
        while(l < n and a[l] != b[i]) l++;
        if(l >= n) return cout << "-1\n", 0;
        mark[l] = 1;
        l++;
    }
    ll ans = 0;
    vector<int> chk;
    int last = 0;
    a.push_back(0); mark.push_back(1);
    for(int i = 0; i < a.size(); i++){
        if(!mark[i]) chk.push_back(a[i]);
        else{
            ll cnt = 0, tot = chk.size();
            while(chk.size()) cnt += (chk.back() > max(last,a[i])), chk.pop_back();
            if(y * k <= x){
                if(cnt){
                    if(tot < k) return cout << "-1\n",0;
                    ans += (tot - k) * y + x;
                }    
                else {
                    ans += tot * y;
                }
            }
            else {
                if(cnt and tot < k) return cout << "-1\n",0;
                ans += (tot / k) * x + (tot % k) * y;
            }
            last = a[i];
        }
    }
    cout << ans << endl;
}