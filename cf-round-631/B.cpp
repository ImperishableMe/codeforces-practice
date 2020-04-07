#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;
int const MOD = 1e9 + 7;

ll bigmod(ll a,ll b){
    if(!b) return 1;
    ll x = bigmod(a,b/2);x = (x*x)% MOD;
    if(b&1) x = (x*a)%MOD; 
    return x;
}

bool can(int l1,int l2, vector<int> &v){
    assert(v.size() == l1 + l2);

    vector<bool>has1(l1+1,0), has2(l2+1,0);

    for(int i = 0;i < l1; i++){
        if(v[i] > l1 or has1[v[i]]) return  0;
        has1[v[i]] = 1;
    }
    for(int i = l1; i < l1 + l2; i++){
        if(v[i] > l2 or has2[v[i]]) return  0;
        has2[v[i]] = 1;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        vector < int > v(n);

        for(int i = 0; i < n; i++) cin >> v[i] ;
        int mx = *max_element(v.begin(), v.end());
        int l1 = mx , l2 = n - mx;

        vector<PII> ans;
        if(l1 and l2 and can(l1,l2,v)){
            ans.emplace_back(l1,l2);
        }
        if(l1 and l2 and l1 != l2 and can(l2,l1,v)) ans.emplace_back(l2,l1);

        cout << ans.size() << '\n';

        for(auto x : ans)
            cout << x.first << " " << x.second << '\n';   
    }
    return 0;
}