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

int const N = 210;
ll dp[N][N][N] ;
int r,g,b;
ll col[4][N] ;

ll DP(int _r, int _g, int _b){
	int z_c = 0;
	z_c += (_r <= 0);
	z_c += (_g <= 0);
	z_c += (_b <= 0);
	if(z_c > 1) return 0;
	if(_r < 0 or _g < 0 or _b < 0) return 0;

	ll &ret = dp[_r][_g][_b] ;
	if(ret != -1){
		return ret;
	}
	ret = 0;
	ret = max(ret, DP(_r-1, _g-1, _b) + col[0][_r] * col[1][_g]);
	ret = max(ret, DP(_r-1, _g, _b-1) + col[0][_r] * col[2][_b]);
	ret = max(ret, DP(_r, _g-1, _b-1) + col[1][_g] * col[2][_b]);
	
	return ret;

}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	cin >> r >> g >> b;

	for(int i = 1; i <= r; i++) cin >> col[0][i]; 	
	sort(col[0] + 1, col[0] + r + 1);
	for(int i = 1; i <= g; i++) cin >> col[1][i] ;
	sort(col[1] + 1, col[1] + g + 1);
	for(int i = 1; i <= b; i++) cin >> col[2][i] ;
	sort(col[2] + 1, col[2] + b + 1);
	memset(dp,-1,sizeof dp);
	cout << DP(r,g,b) << endl;
	return 0;
}