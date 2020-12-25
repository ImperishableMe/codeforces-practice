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
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Q(int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << endl;
	int lca;
	cin >> lca;
	return lca;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int h;
	cin >> h;
	int n = (1<<h) - 1;

	set < PII, greater<PII> > st;
	vector < int > cnt (n+1, 0);

	int random_cnt = 420;

	while (random_cnt) {
		int a, b, c;
		do {
			a = rng() % n + 1;
			b = rng() % n + 1;
			c = rng() % n + 1;
		}while (a == b or b == c or c == a);

		int ret = Q(a, b, c);
		if(st.count({cnt[ret], ret}))
			st.erase({cnt[ret], ret});

		cnt[ret]++;
		st.insert({cnt[ret], ret});
		random_cnt--;
	}

	assert(st.size() >= 2);

	int c1 = st.begin()->second;
	st.erase(st.begin());
	int c2 = st.begin()->second;

	for (int i = 1; i <= n; i++) {
		if( i != c1 and i != c2) {
			int ret = Q(i, c1, c2 );
			if (ret == i) {
				cout << "! " << ret << endl;
				exit(0);
			}
		}
	}

	assert(0);

	return 0;
}