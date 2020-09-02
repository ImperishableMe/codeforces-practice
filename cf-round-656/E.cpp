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
int const N = 2e5 + 10;
vector<int>g[N];
int col[N] ;
bool can_do;
void dfs(int u, stack<int> &st){
	col[u] = 1;
	for(int v : g[u]){
		if(col[v] == 1) can_do = 0;
		else if(col[v] == 2) continue;
		else dfs(v,st);
	}
	col[u] = 2;
	st.push(u);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<PII> edge[2];
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 0; i < m; i++){
			int t, a, b;
			cin >> t >> a >> b;
			edge[t].emplace_back(a,b);
			if(t) g[a].push_back(b);
		}
		stack < int > top_sort;
		can_do = true;
		fill(col + 0, col + n + 1, 0);
		for(int i = 1; i <= n && can_do; i++){
			if(col[i]) continue;
			dfs(i, top_sort);
		}
		if(!can_do) {
			cout << "NO\n";
			continue;
		}
		vector<int> oid(n+1);
		int id = 0;
		while(!top_sort.empty()) {
			int u = top_sort.top();
			oid[u] = id++; top_sort.pop();
		}
		for(auto &x : edge[0]){
			if(oid[x.first] > oid[x.second]) swap(x.first, x.second);
		}
		cout << "YES\n";
		for(int i = 0; i < 2; i++){
			for(auto &x : edge[i]){
				cout << x.first << " " << x.second << '\n';
			}
		}
	}
	return 0;
}
