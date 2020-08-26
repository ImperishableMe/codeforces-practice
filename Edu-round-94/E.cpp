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

ll solve(vector<int> v)
{
	ll can = v.size();
	assert(v.size() >= 1);
	if(can == 1) return v.back() != 0;
	ll can2 = 0;
	ll mn = *min_element(all(v));
	can2 += mn;

	for(auto &x : v) x -= mn;

	vector< int > tmp;
	for(int i = 0; i < v.size(); i++){
		if(v[i] == 0) {
			if(tmp.size() != 0){
				can2 += solve(tmp);
				tmp.clear();
			}
		}
		else {
			tmp.push_back(v[i]);
		}
	}
	if(tmp.size()){
		can2 += solve(tmp);
	}
	return min(can, can2);
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);

	for(int i = 0; i < n; i++) cin >> v[i] ;

	cout << solve(v) << '\n';
	return 0;
}
