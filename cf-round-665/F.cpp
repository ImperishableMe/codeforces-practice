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
#define all(v) ((v).begin(),(v).end())

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
int const LOG = 19;
int n;
ll a[(1<<LOG)] , seg[4 * (1<<LOG)] ;
bool swp[LOG];

void build(int p, int l,int r){
	if(l == r) {
		seg[p] = a[l] ; return;
	}
	int mid = (l+r) >> 1;
	build(p<<1,l,mid) ; build(p<<1|1,mid+1,r);
	seg[p] = seg[p<<1] + seg[p<<1|1] ;
}

void update(int p, int l, int r, int ind, ll val, int lvl = n){
	if( l > ind or r < ind) return;
	if(l == r and l == ind) {
		seg[p] = val; return;
	}	
	int mid = (l + r) >> 1;
	PII left = {l, mid} , right = {mid+1,r};
	if(swp[lvl-1]){
		swap(left,right);
	}
	update(p<<1,left.F, left.S, ind, val, lvl - 1);
	update(p<<1|1, right.F, right.S, ind, val, lvl - 1);
	seg[p] = seg[p<<1] + seg[p<<1|1];
}

ll Q(int p, int l, int r, int ql, int qr, int lvl = n)
{
	if(ql <= l and r <= qr) return seg[p] ;
	if(l > qr or r < ql) return 0;	
	int mid = (l + r) >> 1;
	PII left = {l, mid} , right = {mid+1,r};
	if(swp[lvl-1]){
		swap(left,right);
	}
	return Q(p << 1, left.F, left.S, ql, qr, lvl - 1) +
		   Q(p << 1 | 1, right.F, right.S, ql, qr, lvl - 1);
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int q;
	cin >> n >> q;

	for(int i = 1; i <= (1<<n); i++) cin >> a[i];
	
	build(1, 1, 1 << n);
	
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			ll x,k;
			cin >> x >> k;
			update(1,1,1<<n, x, k);
		}
		else if(type == 2){
			int k;
			cin >> k;
			k--;
			for(int i = 0; i <= k; i++) swp[i] ^= 1;

		}
		else if(type == 3){
			int k;
			cin >> k;
			swp[k] ^= 1;
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << Q(1,1,1<<n, l, r) << '\n';
		}

	}
		
	return 0;
}
