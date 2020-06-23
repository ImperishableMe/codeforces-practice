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
int const N = 1010;
vector<int> g[N];
int st[N], en[N];
vector<int> dep[N];
int q = 0;
int tmo = 0;

PII query(vector<int>&v){

	q++;
	assert(q <= 11);
	cout << "? " << v.size() << " ";
	for(auto x : v){
		cout << x << " ";
	}
	cout << endl;
	int node,dis;
	cin >> node >> dis ;
	return {node,dis};
}

void dfs(int u,int pr,int d){
	st[u] = ++tmo;

	dep[d].push_back(u);

	for(auto v : g[u]){
		if(v == pr) continue;
		dfs(v,u,d+1);
	}
	en[u] = ++tmo;
}

PII ask(int depth){
	
	if(dep[depth].empty()) return PII(-1,1e9);
	return query(dep[depth]);
}

bool isDescendant(int r,int c)
{
	return st[r] <= st[c] and en[c] <= en[r];
}

void solve(){
	int n;
	cin >> n;
	q = 0;
	tmo = 0;
	for(int i = 0; i < n - 1; i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> v;
	for(int i = 1; i <= n; i++) v.push_back(i);

	PII tmop = query(v);
	int root = tmop.F;
	int dim = tmop.S;

	dfs(root,-1,0);

	int lo = (dim+1)/2,hi = dim, node_a = -1, loo = -1;
	
	

	while(lo <= hi){
		int mid = (lo + hi + 1) / 2;
			//cout << lo << " " << hi << "mid : "<< mid << endl;

		tmop = ask(mid);
		if(tmop.second > dim){
			hi = mid - 1;
		}
		else{
			loo = mid;
			lo = mid + 1;
			node_a = tmop.first;
			//cout << "node_a :" << node_a << " " << lo << " " <<endl;
		}
	}
	int node_b = -1;
	if(loo != dim){
		vector<int> tmop;

		for(auto x : dep[dim-loo]){
			if(!isDescendant(x,node_a)) tmop.push_back(x);
		}
		assert(tmop.size() >= 1);
		PII ans = query(tmop);
		node_b = ans.first;
	}
	else {
		node_b = root;
	}

	cout << "! " << node_a << " " << node_b << endl;
	string _;
	cin >> _ ;

}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < N; i++) g[i].clear();
		for(int i = 0; i < N; i++) dep[i].clear();
		solve();
	}	
	return 0;
}