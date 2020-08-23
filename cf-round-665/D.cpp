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

vector<ll> wt,pf;
int const N = 1e5 + 10;
vector<ll> g[N] ;
int n;
ll sub[N] ;
void clean(){

	for(int i = 0; i <= n; i++) g[i].clear();
	wt.clear();
	pf.clear();
}

void dfs(int u, int p){
	sub[u] = 1;
	//cout << "dfs " << endl;

	for(auto x : g[u]){
		//cout << "hello " << endl;
		if(x != p){
			dfs(x,u);
			sub[u] += sub[x] ;
			wt.push_back(( 1LL*n - sub[x]) * sub[x]) ;
		}
	}

}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		cin >> n;

		for(int i = 1; i <= n - 1; i++){
			int a,b;
			cin >> a >> b;
            g[a].push_back(b);
			g[b].push_back(a);
		}

		int k;
		cin >> k;

		for(int i = 0; i < k; i++){
			ll tmp;
			cin >> tmp;
			pf.push_back(tmp);
		}

		dfs(1,-1);
		sort(all(wt), greater<ll>());
		sort(all(pf));

		ll ans = 0;

		while(pf.size() >= 2 and pf.size() > wt.size()){
			ll tmp = pf.back();
			pf.pop_back();
			tmp = (tmp * pf.back()) % MOD;
			pf.pop_back();
			pf.push_back(tmp);
		}

		reverse(all(pf));

		while(pf.size() < wt.size()){
			pf.push_back(1LL);
		}

		assert(pf.size() == wt.size());


		for(int i = 0; i < wt.size(); i++){
			ans = (ans + wt[i] * pf[i]) % MOD;
		}

		cout << ans << '\n';
		clean();
	}	
	return 0;
}
