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
int const N = 1e5 + 10;

vector<PLL>g[N];
int sub[N], wgt[N] ;

multiset < PLL > ms;
ll sum, e_c ;


int dfs(int u,int pr){

	if(g[u].size() == 1 and u != 1){
		return 1;
	}
	int ret = 0;
	for(auto x : g[u]){
		int v = x.first;
		if(v == pr) continue;

		int tmp = dfs(v,u);
		ret += tmp;
		sum += tmp * x.second;
		sub[e_c] = tmp;
		wgt[e_c] = x.second;
		ms.insert({(x.second - x.second/2)*tmp, e_c});
		e_c++;
	}
	return ret;
}


int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll n,s;
		cin >> n >> s;
		ms.clear();
		for(int i = 0; i < n - 1; i++){
			int a,b,w;
			cin >> a >> b >> w;
			g[a].push_back({b,w});
			g[b].push_back({a,w});
		}

		sum = e_c = 0;
		dfs(1,-1);
		ll ans = 0;
		while(sum > s ) {
			ans++;
			assert(!ms.empty());
			auto end_it = prev(ms.end());
			PLL now = *end_it;
			sum -= end_it->first;
			wgt[now.second] /= 2;
			ms.erase(end_it);

			ll tmp = wgt[now.second];
			if(tmp > 0){
				ms.insert({(tmp-tmp/2)*sub[now.second], now.second});
			}
		}

		cout << ans << '\n';

		for(int i = 0; i <= n; i++) g[i].clear();

	}	
	return 0;
}