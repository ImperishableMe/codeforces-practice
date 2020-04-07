#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const MOD = 1e9 + 7;
int const N = 1e5 + 10;
vector<ll>x;
ll ans;
vector<int> g[N];
ll gcd(ll a,ll b){
    if(a == 0 or b == 0) return a + b;
    return __gcd(a,b);
}
void dfs(int u,int p,map<ll,int> mp)
{
    map <ll,int> nmp;
    nmp[x[u]]++;
    ans += x[u] ;
    if(ans >= MOD) ans -= MOD;

    for(auto [x,y] : mp) {
        ll g = gcd(x,x[u]);
        ans = (ans + g * y) % MOD;
        nmp[g] += y ;
    }
    for(auto v : g[u]){
        if(v != p)
            dfs(v,u,nmp);
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    x.resize(n+1);

    for(int i = 1; i <= n; i++) cin >> x[i] ;
    //dfs(1,-1,{});
    for(int i = 0;i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,{});
    cout << ans << endl;
    return 0;
}
