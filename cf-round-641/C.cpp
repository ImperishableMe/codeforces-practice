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
map < int, vector< int > > cnt;
int const N = 2e5 ;

void do_it(ll n){
	for(auto p : primes){
		if( p * p > n ) break;
		if(n % p == 0){
			int c = 0;
			while(n % p == 0) n /= p, c++;
			cnt[p].push_back(c);
		}
	}
	if(n != 1) cnt[n].push_back(1);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	sieve( N + 10);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		do_it(tmp);
	}
	// for(auto &x : cn
	// 	sort(all(x.second)greater< int >() );
	// }
	ll ans = 1;
	for(auto x : cnt) {
		vector< int > &v = x.second;
		ll p = x.first;
		if((int) v.size() < n - 1) continue;
		sort(all(v));
		int c = 0;
		if(v.size() == n) c = v[1];
		else c = v[0] ;
		while(c) ans *= p, c--;
	}
	cout << ans << '\n';
	return 0;
}
