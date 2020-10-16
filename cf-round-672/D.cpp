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
	if(b&1)
		x = (x * a) %MOD;
	return x;
}
int const N = 4e5 + 100;
ll F[N], INV[N];
ll ncr(ll n, ll r){
	if(n < r or r < 0 or n < 0) return 0;
	return F[n] * INV[r] % MOD * INV[n - r] % MOD; 
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, k;
	cin >> n >> k;
	F[0] = 1;
	for(ll i = 1; i < N; i++) F[i] = (F[i - 1] * i) % MOD;
	INV[N - 1] = bigmod( F[N - 1], MOD - 2);
	for(ll i = N - 2; i >= 0; i--) INV[i] = (INV[i + 1] * (i + 1)) % MOD;

	map < int, int > st, en;
	set < int > pts;
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		st[l]++, en[r]++;
		pts.insert(l), pts.insert(r);
	}
	ll ans = 0, active = 0;
	for(auto x : pts){

		for(ll i = 0; i < st[x]; i++){
			ans = ( ans + ncr( active, k - 1) ) % MOD;
			active++;
		}
		for(int i = 0; i < en[x]; i++) active--;
	}
	cout << ans << '\n';
	return 0;
}
