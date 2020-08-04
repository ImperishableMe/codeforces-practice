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

bool can(ll cnt,ll tot, ll k)
{
	return cnt + (cnt+1)*k <= tot;
}

ll calc(ll pos, ll k){
	ll lo = 0,hi = pos;

	ll ret = 0;

	while(lo <= hi){
		ll mid = (lo + hi+1) / 2;

		if(can(mid,pos,k)){
			ret = max(ret, mid);
			lo = mid + 1;
		}	
		else {
			hi = mid - 1;
		}
	}
	return ret;
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		string s;
		cin >> s;

		string tmp = "1";
		for(int i = 0; i < k; i++) tmp += '0';
		tmp += s;
		for(int i = 0; i < k; i++) tmp += '0';
		tmp += '1';

		ll ans = 0;
		vector<int> ind;

		for(int i = 0; i < tmp.size(); i++){
			if(tmp[i] == '1') ind.push_back(i);
		}

		for(int i = 1; i < ind.size(); i++){
			ans += calc(ind[i]-ind[i-1]-1,k);
		}
		cout << ans << '\n';
	}
	return 0;
}