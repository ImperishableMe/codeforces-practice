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

int const N = 2e5 + 10;

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n>>k;
		
		vector<ll> v(n);
		for(int i = 0; i < n; i++) cin >> v[i] ;
		vector<ll> w(k);
		for(int i = 0;i < k;i++)
			cin >> w[i] ;

		sort(w.begin(), w.end(), greater<ll>());
		sort(v.begin(), v.end());
		
		ll ans = 0;

		while(!w.empty() and w.back() == 1){
			ans += 2*v.back();
			v.pop_back();
			w.pop_back();
		}
		reverse(v.begin(),v.end());
		//reverse(w.begin(),w.end());

		for(int i = 0; i < w.size(); i++){
			int cnt = w[i]-1;
			ans += v.back();
			while(cnt) v.pop_back(), cnt--;
		}
		for(auto x : v){
			ans += x;
		}
		cout << ans << '\n';
		
	}
	return 0;
}