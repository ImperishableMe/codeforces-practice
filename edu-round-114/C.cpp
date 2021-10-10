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

void solve(int t){
	int n;
	cin >> n;
	ll tot = 0;
	vector<ll> a(n);
	
	for (auto &x : a) cin >> x, tot += x;

	sort(all(a));
	
	int m;
	cin >> m;

	auto calc = [&] (int pos, ll x, ll y)-> ll {
		return max(0LL, x - a[pos]) + max(0LL, y - (tot - a[pos]));
	};

	while (m--){
		ll x, y;
		cin >> x >> y;
		ll ans = 4e18;
		int up_ind = upper_bound(all(a), x) - a.begin();
		ans = min(ans, calc(up_ind, x, y));
		if (up_ind > 0) {
			ans = min(ans, calc(up_ind-1, x, y));
		}
		up_ind--;
		if (up_ind > 0) {
			ans = min(ans, calc(up_ind-1, x, y));
		}
		cout << ans << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1; 
	// cin >> t; // if no testcase, comment this out
	for (int i = 1; i <= t; i++) solve(t);	
	return 0;
}
