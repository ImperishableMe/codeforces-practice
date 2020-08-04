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
int const N = 1e7 + 10;
vector<int>primes;

vector < bool > marks;
int mindivi[N] ;


void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	for(int i = 2; i < n; i++){
		
		if(!marks[i]){
			mindivi[i] = i;
			for(int j = 2*i; j < n; j += i){
				marks[j] = 1;
				mindivi[j] = min(mindivi[j],i);
			}
			primes.push_back(i);
		}
	}
}

//vector<int> div[N] ;

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	memset(mindivi,0x3f,sizeof mindivi);		
	sieve(N);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<PII> ans(n,PII(-1,-1));
	

	for(int i = 0; i < n; i++){
		cin >> v[i] ;
	}
	vector<int>pds;

	for(int i = 0; i < n; i++){
		pds.clear();

		int tmp = v[i];

		// for(auto x : primes) {
		// 	if(x * x > tmp) break;
		// 	if(tmp % x == 0){
		// 		while(tmp % x == 0) tmp /= x;
		// 		pds.push_back(x);
		// 	}	
		// }
		// if(tmp != 1) pds.push_back(tmp);
		while(mindivi[tmp] < N ){
			int cd = mindivi[tmp];
			pds.push_back(cd);
			while(tmp % cd == 0) tmp /= cd;
		}

		ll tot = 1;

		if(pds.size() <= 1) {
			continue;
		}
		else{
			for(auto x : pds) tot *= x;
			tot /= pds.back();
			ans[i].first = tot;
			ans[i].second = pds.back();
		}
	}

	for(int i = 0; i < n; i++) cout << ans[i].first << " ";
	cout << '\n';
	for(int i = 0; i < n; i++) cout << ans[i].second << " " ;
	cout << '\n';

	return 0;
}