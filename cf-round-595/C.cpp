#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ll>po;
    po.push_back(1);
    ll cur = 1;
    while(cur*3.0 < 5e18){
        cur *= 3;
        po.push_back(cur);
    }
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 5e18;
        ll cur = 0;
        for(int i = (int)po.size()-1; i >= 0; i--){
            if(cur+po[i] >= n){
                ans = min(ans,cur+po[i]);
                //cur = 0;
            }else{
                cur += po[i] ;
            }
        }
        cout << ans << '\n';
    }

}
