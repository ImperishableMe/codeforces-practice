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
int const N = 5e5 + 10;

vector<int> g[N];
vector<int> path;
vector<int> dep[N];
vector<bool>mark(N,false);
int n,m;

void clean(int n){

	for(int i = 0; i <= n; i++) {
		g[i].clear();
		dep[i].clear();
	}
	path.clear();
	fill(mark.begin(), mark.begin() + n + 2, false);

}

bool dfs(int u,int d){
	path.push_back(u);

	if(path.size() * 2 >= n){
		return 1; // wait there buddy
	}

	mark[u] = 1;
	dep[d].push_back(u);
	bool done = 0;

	for(auto v : g[u]){
		if(!mark[v]){
			if(!done){
				done |= dfs(v,d+1);
			}
		}
	}
	if(!done) path.pop_back();
	return done;
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//cerr << "Hello" << endl;
	if( dfs(1,0) ){
		cout << "PATH" << '\n';
		cout << path.size() << '\n';
		for(auto x : path) {
			cout << x << " " ;
		}
		cout << "\n" ;
	}
	else {
		vector<PII> pairs;

		for(int i = 0; i < n; i++){
			while(dep[i].size() >= 2){
				int t1 = dep[i].back();
				dep[i].pop_back();
				int t2 = dep[i].back();
				dep[i].pop_back();
				pairs.push_back({t1,t2});
			}
		}
		cout << "PAIRING" << '\n';
		cout << pairs.size() << '\n';

		for(auto x : pairs){
			cout << x.first << " " << x.second << '\n';
		}
	}

	clean(n);
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}