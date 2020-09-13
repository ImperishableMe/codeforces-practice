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
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void solve(){
	int n,m;
	cin >> n >> m;
	vector< vector<int> > g(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> g[i][j];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int valid = 0;
			for(int x = 0; x < 4; x++){
				int nx = i + dx[x], ny = j + dy[x];
				valid += (nx >= 0 and nx < n and ny >= 0 and ny < m);
			}
			if(valid < g[i][j]) {
				cout << "NO\n"; return ;
			}
			g[i][j] = valid;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cout << g[i][j] << " " ;
		cout << '\n';
	}
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