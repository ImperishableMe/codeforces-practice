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
ll const MOD = 998244353 ;

ll bigmod(ll a, ll b){
	if(!b) return 1;
	ll x  = bigmod(a,b/2);
	x = (x * x)%MOD;
	if(b&1)	x = (x * a) %MOD;
	return x;
}
ll INV(ll a){
	if( a < 0) return 0;
	return bigmod(a, MOD - 2);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector < ll > v(n), pref(n,0);
	ll tot = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		tot += v[i];
	}
	sort( all(v) );
	for(int i = 0 ; i < n; i++) pref[i] = (i ? pref[i-1] : 0) + v[i] ;
	while(m--){
		ll a, b;
		cin >> a >> b;
		ll sml = lower_bound(all(v), b) - v.begin();
		ll big = n - sml;
		sml--;
		ll ans = 0;
		if( big >= a){
			ll s_s = (sml >= 0 ? pref[sml] : 0);
			ll b_s = tot - s_s;
			s_s %= MOD, b_s %= MOD;
			ans = ( b_s * (big - a) % MOD * INV( big ) % MOD + s_s * ( big + 1 - a ) % MOD * INV (big + 1) % MOD ) % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}
