#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;

typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define F first
#define S second
#define all(v) (v).begin(),(v).end()

ostream& operator<<(ostream & os, PLL h){
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}


ll const MOD = 1e9 + 7;

ll bigmod(ll a, ll b){
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}
ll INV(ll a){
    return bigmod(a , MOD - 2);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    ll ans = 0, num = 0;
    ll n = s.size(), r = 0, l = 0, r_add = 0, last = 0;
    vector < ll > po(s.size() + 1, 1);

    for(int i = 1; i <= s.size(); i++) po[i] = ( po[i-1] * 10) % MOD;

    for(int i = n - 1; i >= 0; i--){
        l = 1LL * i * (i + 1) / 2 % MOD;
        ans = (ans + l * po[r] % MOD * (s[i] - '0') % MOD ) % MOD;
        if(r) last = (last + r * po[r-1] % MOD) % MOD;
        ans = ( ans + last * (s[i] - '0') % MOD ) % MOD;
        r++;
    }
    cout << (ans + MOD) % MOD << '\n';
    return 0;
}
