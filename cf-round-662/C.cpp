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

int const N = 1e5 + 10;
int cnt[N], n, l_cnt[N];

bool can(int gap, vector<int> &yo){
	
	set < PII, greater<PII> > s;

	for(int i = 1; i <= n; i++) l_cnt[i] = cnt[i];

	for(int i = 1; i <= n; i++){
		if(l_cnt[i] >= 1){
			s.insert({l_cnt[i], i});
		}
	}
	gap++;

	vector<int> tkn;

	for(int i = 0; i < n; i++){
		if(i >= gap and l_cnt[ tkn[i-gap] ] > 0){
			s.insert({ l_cnt[ tkn[i-gap] ], tkn[i-gap] });
		}
		if(s.empty()) return 0;
		tkn.push_back(s.begin()->second);
		l_cnt[s.begin()->second]--;
		s.erase(s.begin());
	}
	
	return 1;
}

void solve(){
	cin >> n;

	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}

	int lo = 0, hi = n, ans = 0;
	vector<int> freq;
	
	
	while(lo <= hi){
		int mid = (lo + hi) / 2;

		if(can(mid, freq)){
			ans = max(ans, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}

	}

	cout << ans << '\n';


	for(int i = 0; i <= n; i++) cnt[i] = 0;
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