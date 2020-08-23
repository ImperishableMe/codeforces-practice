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
int const N = 1e6 + 10;
ll y_seg[4*N] ;
vector<int> y_st[N], y_en[N] ;
vector< PII > x_seg[N];
int const LIM = 1e6 ;

void update(int p, int l, int r, int ind, ll val){
	if(ind < l or ind > r) return;
	if(l == r and l == ind) {
		y_seg[p] += val; return;
	}
	int mid = (l+r) >> 1;
	update(p<<1, l,mid, ind, val);
	update(p<<1|1,mid+1, r, ind, val);
	y_seg[p] = y_seg[p<<1] + y_seg[p<<1|1];
}

ll Q(int p, int l, int r, int ql, int qr){
	if(ql <= l and r <= qr) return y_seg[p] ;
	if(l > qr or r < ql) return 0;
	int mid = (l + r) >>1;
	return Q(p<<1, l, mid, ql, qr) + Q(p<<1|1, mid+1, r, ql, qr);
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int n, m ;
	cin >> n >> m;
	ll ans = 0, x_full = 0, y_full = 0;

	for(int i =0 ; i < n; i++){
		int y, lx, ly;
		cin >> y >> lx >> ly;

		if(lx == 0 and ly == LIM) x_full++;
		y_st[lx].push_back(y);
		y_en[ly].push_back(y);
	}

	for(int i = 0; i < m ; i++){
		int x, ly, ry;
		cin >> x >> ly >> ry;
		
		if(ly == 0 and ry == LIM) y_full++;
		x_seg[x].push_back({ly,ry});
	}

	for(int x = 0; x <= LIM; x++){
		for(auto a : y_st[x])	update(1,0,LIM,a,1);
		for(auto sg : x_seg[x]) ans += Q(1,0,LIM, sg.F, sg.S);
		for(auto a : y_en[x]) update(1,0,LIM,a,-1);
	}

	cout << ans + x_full + y_full + 1 << endl;
	return 0;
}
