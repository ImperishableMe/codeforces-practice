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

#define F first
#define S second


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
ll const MX = 1e5 + 10;

ll bigmod(ll a, ll b, ll m = MOD){
	if(!b) return 1;
	ll x  = bigmod(a,b/2,m);

	x = (x * x)% m;
	if(b&1)
		x = (x * a) % m;
	return x;
}

ll modinv(ll num){
	return bigmod(num,MOD-2);
}

PLL M = {1e9 + 9, 1e9 + 21};

ll n,p;
PLL pair_big_mod(ll a, PLL b)
{
	return PLL(bigmod(p,a,b.F), bigmod(p,a,b.S));
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		ll ans = 0;
		
		cin >> n >> p;

		vector<int>v(n);

		for(int i = 0; i < n; i++) cin >> v[i] ;

		PLL s = PLL(0,0);

		sort(v.rbegin(),v.rend());

		for(auto x : v){
			if(ans == 0 and s == PLL(0LL,0LL)) {
				s = s + pair_big_mod(x,M);
				s = s % M;
				ans += bigmod(p,x);
				ans %= MOD;
			}
			else {
				s = s + M - pair_big_mod(x,M);
				s = s % M;
				ans = (ans - bigmod(p,x) + MOD) % MOD ;
				//ans %= MOD;
			}
		}
		cout << ans << '\n';
	}
		
	return 0;
}