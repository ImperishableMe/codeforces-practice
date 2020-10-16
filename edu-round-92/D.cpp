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

ll bigmod(ll a, ll b){
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}

vector < ll > primes;
vector < bool > marks;

void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	for(int i = 2; i < n; i++){
		if(!marks[i]){
			for(int j = 2*i; j < n; j += i){
				marks[j] = 1;
			}
			primes.push_back(i);
		}
	}
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		ll com = min(r2,r1) - max(l1,l2);
		ll uni = max(r1,r2) - min(l1,l2);
		assert(uni >= 0);
		if(uni == 0) {
			cout << 2 * k << '\n'; continue;		
		}	
		if(com > 0){
			ll ans = 0;
			k -= min(k, n * com);	
			ans += min(k,n * (uni-com));
			k -= min(k, n * (uni - com));
			ans += 2 * k;
			cout << ans << '\n';
		}
		else {
			ll ans = 0;
			com = abs(com);
			ll full_seg = min(k / uni, n);
			k -= full_seg * uni;
			ans += full_seg * (uni + com);
			n -= full_seg;
			if(n and k >= com or !full_seg){
				ans += com + k;
				assert( k <= uni);
			}
			else {
				ans += 2 * k;
			}
			cout << ans << '\n';
		}
	}	
	return 0;
}