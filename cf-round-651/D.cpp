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

vector<ll> v;
ll n,k;
bool can(ll x)
{
	// odd position check 
	int taken = 0;

	for(int i = 0;i < n; i++){
		if(taken & 1){
			taken++;
		}
		else{
			if(v[i] > x) continue;
			taken++;
		}
		if(taken >= k) return 1;
	}
	// even check
	taken = 0;

	for(int i = 0; i < n; i++){
		if(taken & 1){
			if(v[i] > x) continue;
			taken++;
		}
		else{
			taken++;
		}
		if(taken >= k) return 1;
	}
	return 0;
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);	
	
	cin >> n >> k;
	v.resize(n);	
	for(auto& x : v) cin >> x;

	ll lo = 0, hi = 1e9 + 10;
	ll ans = hi;

	while(lo <= hi){
		ll mid = (lo+hi)/2;
		if(can(mid)){
			ans = min(ans,mid);
			hi = mid - 1;
		}
		else 
			lo = mid + 1;
	}
	cout << ans << endl;
	
	return 0;
}