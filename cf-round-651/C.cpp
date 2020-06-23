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

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	sieve(N);
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		bool f = 1;
		if(n == 1){
			f = 0;
		}
		else if( n & 1){
			f = 1;
		}
		else if(n != 2 and ((n & (n-1)) == 0) ){
			f = 0;
		}
		else {
			int cnt = 0;
			while(n % 2 == 0) n /= 2, cnt++;
			if(cnt > 1 ){
				f = 1;
			}		
			else {
				vector<int> pc;
				int tot = 0;
				for(auto x : primes){
					if(x * x > n) break;
					if( n % x == 0){
						int cc = 0;
						while(n % x == 0) n/=x , cc++;
						tot += cc;
						pc.push_back(x);
					}
				}
				if(n != 1) pc.push_back(n), tot++;

				if(tot == 1){
					f = 0;
				}
			}
		}
		if(f){
			cout << "Ashishgup" << "\n";
		}
		else {
			cout << "FastestFinger" << '\n';
		}
	}
	return 0;
}