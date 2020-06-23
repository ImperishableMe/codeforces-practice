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
		vector<int>v(n*2),odd,even;

		for(int i = 0; i < 2*n; i++){
			cin >> v[i] ;
			if(v[i] & 1) odd.push_back(i);
			else even.push_back(i);
		}
		vector<PII> ans;

		if(odd.size() & 1){
			odd.pop_back();
		}
		while(odd.size() >= 2){
			int a = odd.back();
			odd.pop_back();
			int b = odd.back();
			odd.pop_back();
			ans.emplace_back(a,b);
		}
		while(even.size() >= 2){
			int a = even.back();
			even.pop_back();
			int b = even.back();
			even.pop_back();
			ans.emplace_back(a,b);
		}
		//cout << ans.size() << " " << n << endl;

		while(ans.size() > n - 1) ans.pop_back();
		assert(ans.size() == n - 1);
		for(auto x : ans){
			cout << x.first + 1 << " " << x.second + 1 << '\n';
		}
	}
	
	return 0;
}