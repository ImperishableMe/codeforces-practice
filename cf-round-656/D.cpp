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

int csum[30][N];
string s;
int cnt(int l, int r, int ch){
	int tmp = csum[ch][r] - csum[ch][l-1] ;
	return r - l + 1 - tmp;
}
int ans(int l,int r, int ch)
{
	if(l == r) return s[l-1] != ch + 'a';
	int mid = (l+r) / 2;
	// cout << l << " " << r << " " << ch << " " << cnt(l,r,ch) << endl;
	int c1 = ans(l,mid, ch+1) + cnt(mid+1, r, ch);
	int c2 = cnt(l,mid,ch) + ans(mid+1, r, ch + 1);
	return min(c1, c2);
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cin >> s;
		for(int ch = 0; ch <= 26; ch++){
			for(int i = 0; i <= n + 10; i++) csum[ch][i] = 0;
			for (int i = 1; i <= n; i++){
				csum[ch][i] = csum[ch][i-1] + (s[i-1] - 'a' == ch);				
			}
		}
		cout << ans(1,n,0) << '\n';
	}
	return 0;
}
