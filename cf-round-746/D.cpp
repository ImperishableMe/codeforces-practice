#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

using ll = long long int;
typedef pair <int,int> PII;
typedef pair <ll,ll> PLL;
#define F first
#define S second
#define all(v) (v).begin(),(v).end()

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//find_by_order(k) --> returns iterator to the kth largest element counting from 0 
//order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// to generate a uniform random integer over a range [l,r], use 
// int x = uniform_int_distribution<int>(l,r)(rng);

// unordered map
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash { /// use most bits rather than just the lowest ones
	const uint64_t C = ll(2e18*acos((long double)-1))+71; // large odd number
	const int RANDOM = rng();
	ll operator()(ll x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x^RANDOM)*C); }
};
template<class K,class V> using ht = gp_hash_table<K,V,chash>;

// declare map of <int,PLL> as 
// ht<int, PLL> mp;


ll const MOD = 1e9 + 7;
int const N = 1e5 + 10;
vector<int> g[N];
vector<PII> e;
int cnt = 0;
int mx;
vector<int> euler;

int ask(vector<PII> &e){
	set<int> s;

	// cout << "dbg " << st << " "  << en << endl;

	for (auto [a, b] : e) {
		s.insert(a);
		s.insert(b);
	}
	assert(s.size());

	cout << "? " << s.size() << " ";

	for (auto x : s) cout << x << " ";
	cout << endl;

	int val;
	cin >> val;

	return val;
}


bool can(vector<PII> &e){
	return ask(e) == mx;
}


// void dfs(int u, int p){
// 	euler.push_back(u);

// 	for (auto v : g[u]){
// 		if (v == p) continue;
// 		dfs(v, u);
// 		euler.push_back(u);
// 	}
// }

vector<PII> e_order;
void dfs(int u, int p){

	for (auto v : g[u]){
		if (v == p) continue;
		e_order.push_back({u, v});
		dfs(v, u);
	}
}

void solve(int t){

	int n;
	cin >> n;
	vector<PII> e, le, re;
	e.clear();

	for (int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		e.push_back({a, b});
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1, 0);

	// cout << "euler ";
	// for (auto x : euler) cout << x << " ";
	// cout << endl;


	int lo = 0, hi = euler.size() - 1;

	mx = ask(e_order);

	while (e_order.size() > 1){
		le.clear(), re.clear();
		for (int i = 0; i < e_order.size(); i++){
			if (le.size() * 2 < e_order.size()) le.push_back(e_order[i]);
			else re.push_back(e_order[i]);
		}

		if (can(le)) e_order = le;
		else e_order = re;
	}

	cout << "! " << e_order[0].second << " " << e_order[0].first << endl;

	// while (lo + 1 < hi){
	// 	int mid = (lo + hi)/2;
	// 	if (can(lo, mid)) hi = mid;
	// 	else lo = mid ;
	// }

	// cout << "! " << euler[lo] << " " << euler[hi] << endl;
	
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1; 
	// cin >> t; // if no testcase, comment this out
	for (int i = 1; i <= t; i++) solve(t);	
	return 0;
}
