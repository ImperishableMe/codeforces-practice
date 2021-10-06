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

#define L(x) (x) << 1
#define R(x) (x) << 1 | 1

using ll = long long int;

struct Node { // change
    ll lv, rv, tot = 0, ending = 0, starting = 0, sz;
    Node(){
		tot = 0, ending = 0, starting = sz = 0;
	}
    Node(ll v){
		sz = tot = ending = starting = (v != 0);
		lv = rv = v;
	}
    // bool operator==(const Node &node) const { return val == node.val; }
};

const Node QUERY_IDENTITY(0); // change
const Node LAZY_IDENTITY(0);  // change

int const N = 2e5 + 10;
Node t[4 * N]; ll a[N];
// Node lazy[4 * N];

Node merge(const Node &a, const Node &b) { 
	Node tmp;
	tmp.tot = a.tot + b.tot;
	tmp.lv = a.lv ? a.lv : b.lv;
	tmp.rv = b.rv ? b.rv : a.rv;
	tmp.starting = a.starting;
	tmp.ending = b.ending;
	tmp.sz = a.sz + b.sz;

	if (a.rv <= b.lv){
		tmp.tot += a.ending * b.starting;
	}
	if (a.starting == a.sz && a.rv <= b.lv) {
		tmp.starting += b.starting;
	}
	if (b.ending == b.sz && a.rv <= b.lv) tmp.ending += a.ending;

	return tmp;

} // change

/**
 * Given the lazy in the node, and a new operation,
 * update the lazy value.
 **/
// void assignLazy(int p, Node op) { lazy[p].val += op.val; } // change

/**
 *  Given the lazy in for a node, calculate its value,
 *  and push the lazy down to the childs
 **/
void push(int p, int l, int r) { // change
	return;
    // if (lazy[p] == LAZY_IDENTITY) {
    //     auto last = lazy[p];
    //     if (l != r) { for (auto ch : {L(p), R(p)}) { assignLazy(ch, last); } }
    //     t[p].val += (r - l + 1) * last.val;
    // }
    // lazy[p] = LAZY_IDENTITY;
}


void build(int p, int l, int r) {
    if (l == r) { 
		t[p] = a[l]; return; 
	}
    int mid = (l + r) / 2;
    build(L(p), l, mid); build(R(p), mid + 1, r);
    t[p] = merge(t[L(p)], t[R(p)]);
}

void update(int p, int l, int r, int ul, int ur, ll val) {
    push(p, l, r); // The order matters
    if (l > ur || r < ul) return;
    if (ul <= l && r <= ur) {
		t[p] = val;
		// assignLazy(p, op);
		return;
	}
	int mid = (l + r) / 2;
    update(L(p), l, mid, ul, ur, val); update(R(p), mid + 1, r, ul, ur, val);
    t[p] = merge(t[L(p)], t[R(p)]);
}

Node query(int p, int l, int r, int ql, int qr) {
    push(p, l, r); // The order matters
    if (l > qr || r < ql) return QUERY_IDENTITY;
    if (ql <= l && r <= qr) return t[p];
    int mid = (l + r) / 2;
    return merge(query(L(p), l, mid, ql, qr), query(R(p), mid + 1, r, ql, qr));
}

void solve(int t){
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);

	// cout << "hello" << endl;

	while (q--){
		int tp, x, y;
		cin >> tp >> x >> y;
		if (tp == 1){
			update(1, 1, n, x, x, y);
		}
		if (tp == 2) {
			cout << query(1, 1, n, x, y).tot << "\n";
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1; 
	// cin >> t; // if no testcase, comment this out
	for (int i = 1; i <= t; i++) solve(t);	
	return 0;
}
