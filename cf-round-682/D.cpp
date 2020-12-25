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

typedef tuple <int,int,int> tp;
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;

	vector < int > v(n+1);
	int x_or = 0;
	for (int i = 1; i <= n; i++) cin >> v[i], x_or ^= v[i];

	if (n % 2 == 0 and x_or) {
		cout << "NO\n"; return 0;
	}
	cout << "YES\n";

	vector < tp > ans;

	int cnt = 2;
	while (cnt > 0) {

		for (int i = 2; i + 1 <= n; i += 2) {
			ans.emplace_back(1, i, i + 1);
			int tmp = v[1] ^ v[i] ^ v[i + 1];
			v[1] = v[i] = v[i + 1] = tmp;
		}

		cnt--;
	}

	assert (ans.size() <= n );
	cout << ans.size() << endl;

	for (auto &[a, b, c] : ans) {
		cout << a << " " << b << " " << c << '\n';
	}

	return 0;
}