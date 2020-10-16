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

void solve(){
	int n;
	cin >> n;
	int _n = n;
	vector < int > pd;
	for(auto x : primes) {
		if( 1LL * x * x > n) break;
		if(_n % x == 0) {
			while( _n % x == 0) _n /= x;
			pd.push_back(x);
		}
	}
	if(_n != 1) pd.push_back(_n);
	set < int > divi;
	for(ll i = 2; i * i <= n; i++){
		if(n % i == 0){
			divi.insert(i), divi.insert(n / i);
		}
	}
	divi.insert(n);
	if(pd.size() == 1){
		for(auto x : divi) cout << x << " ";
		cout << '\n';
		cout << "0\n";
		return;
	}
	assert( pd.size() >= 2);

	if(pd.size() == 2){
		vector < int > two;
		for(auto x : divi){
			if(x % pd[0] == 0 and x % pd[1] == 0)  two.push_back(x);
		}
		if( two.size() == 1){
			cout << pd[0] << " " << pd[0] * pd[1] << " " << pd[1] << '\n';
			cout << "1\n";
		}
		else {

			divi.erase(pd[0]);
			divi.erase(pd[1]);
			//divi.erase(pd[0] * pd[1]);
			while( two.size() > 2) two.pop_back();
			divi.erase(two[0]);
			divi.erase(two[1]);

			cout << pd[0] << " ";
			for(auto x : divi){
				if( x % pd[0] == 0) {
					cout << x << " ";
					divi.erase(x);
				}
			}
			cout << two[0] << " ";
			for(auto x : divi) cout << x << " ";
			cout << pd[1] << " ";
			cout << two[1] << "\n";
			cout << "0\n";
		}
		return;
	}
	
	for(int i = 0; i < pd.size() ; i++){
		divi.erase(pd[i]);
		divi.erase( pd[i] * pd[ ( i + 1) % pd.size()]);
	}
	map < int, vector < int > > g;
	// cout << "divi :" << endl;
	// for(auto x : divi) {
	// 	cout << x << endl;
	// }
	for(auto x : divi){
		int _x = x;
		for(auto y : pd){
			if(x % y == 0) g[y].push_back(x);
		}
	}
	for(int i = 0; i < pd.size(); i++){
		cout << pd[i] << " ";
		for(auto x : g[pd[i]]){
			if( divi.find(x) != divi.end() ) {
				cout << x << " ";
				divi.erase(x);
			}
		}
		cout << pd[i] * pd[ ( i + 1) % pd.size() ] << ' ';
	}
	cout << '\n';
	cout << "0\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	sieve(1e5 + 10);
	while(t--){
		solve();
	}
	return 0;
}
