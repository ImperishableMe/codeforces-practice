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

ll const INFI = (ll)1e15;

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int n,k;
	cin >> n >> k;
	
	vector<ll> a,b,both;

	for(int i = 0 ;i < n; i++){
		int x,y,t;
		cin >>t >>  x >> y;
		
		if(x && y) both.push_back(t);
		else if(x) a.push_back(t);
		else if(y) b.push_back(t);
	}
	if(both.size() + a.size() < k or both.size() + b.size() < k) {
		cout << "-1" << endl;
		return 0;
	}
	
	ll ans = INFI;

	sort(both.begin(), both.end());
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());

	for(int i = 0; i < both.size(); i++){
		if(i){
			both[i] += both[i-1] ;
		}
	}
	for(int i = 0; i < b.size(); i++){
		if(i){
			b[i] += b[i-1] ;
		}
	}
	for(int i = 0; i < a.size(); i++){
		if(i){
			a[i] += a[i-1] ;
		}
	}
	

	for(int bt = 0; bt <= both.size(); bt++){

		
		ll can = 0;
		if(bt){
			can += both[bt-1];
		}
		
		
		if(k - bt > b.size()){
			can = INFI;
		}
		else {
			if(k -bt > 0) 
				can += b[k-bt-1];
		}
		
		if(k - bt > a.size()){
			can = INFI ;
		}
		else {
			
			if(k -bt > 0) 
				can += a[k-bt-1];
		}
		
		if(can < ans) ans = can;
	}
	cout << ans << endl;

	return 0;
}