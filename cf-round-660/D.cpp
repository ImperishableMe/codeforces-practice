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
const int N = 2e5 + 10;
vector<int>g[N];

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<ll>a(n+1),b(n+1), deg(n+1,0);

	for(int i = 1; i <= n; i++) cin >> a[i] ;
	for(int i = 1; i <= n; i++) cin >> b[i] ;

	for(int i = 1; i <= n; i++){
		if(b[i] != -1){
			deg[b[i]]++;
			g[i].push_back(b[i]);
		}
	}

	queue <int> q;
	for(int i = 1; i <= n; i++){
		if(!deg[i]){
			q.push(i);
		}
	}
	vector<int> shoja,ulta;
	ll ans = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		if(a[u] >= 0){
			shoja.push_back(u);
		}
		else {
			ulta.push_back(u);
		}
		ans += a[u] ;
		assert(g[u].size() <= 1);
		for(auto x : g[u]){
			deg[x]--;
			if(a[u] > 0 )
				a[x] += a[u];
			if(!deg[x]) q.push(x);
		}
	}

	cout << ans << endl;
	for(auto x : shoja) cout << x << " ";
	reverse(ulta.begin(),ulta.end());
	for(auto x : ulta) cout << x << " ";
	cout << endl;

	return 0;
}