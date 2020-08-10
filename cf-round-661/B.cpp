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
		int n;
		cin >> n;
		vector<ll>a(n),b(n);
		ll mn_a = 1e12,mn_b = 1e12;

		for(int i = 0; i < n; i++){
			cin >> a[i];
			mn_a = min(mn_a, a[i]);
		}
		for(int i = 0; i < n; i++) cin >> b[i], mn_b = min(mn_b,b[i]);

		ll ans = 1e12, can ;

		for(auto x : a){
			for(auto y : b){
				can = 0;
				for(int i = 0; i < n; i++){
					if(a[i] < x or b[i] < y) {
						can = 1e12;
						break;
					}
					else {
						can += max(a[i]-x, b[i]-y);
					}
				}
				ans = min(ans,can);
			}
		}		

		cout << ans << '\n';
	}

	return 0;
}