#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

bool const DEBUG = 0;
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
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	set < int > left[n];
	vector<int> v(n);

	for(int i = 0; i < n; i++) {
		cin >> v[i] ;
		// cout << bitset<9>(v[i]) << endl;
	}


	for(int i = 0; i < m; i++){
		int tmp;
		cin >> tmp;
		// cout << bitset<9>(tmp) << endl;

		for(int j = 0; j < n; j++)
			left[j].insert(tmp);
	}

	int ans = 0;

	for(int i = 8; i >= 0; i--){

		bool can_zero = 1;
		bool has_one = 0;
		for(int el = 0; el < n; el++){
			bool prob = 0;

			if(v[el] & (1<<i)){
				prob = 1, has_one = 1;
				for(auto x : left[el]){
					if(!(x & (1<<i))){
						prob = 0;
					}
				}

				if(!prob){
					
				}
			}
			can_zero &= !prob;
		}
		if(!can_zero and has_one){
			ans ^= (1<<i);
		}
		else {

			for(int el = 0; el < n; el++){
				if(v[el] & (1<<i)){
					for(auto it = left[el].begin(); it != left[el].end(); ){
						if((*it) & (1<<i)) {
							it = left[el].erase(it);
						}
						else {
							it++;
						}
					}
				}
			}
		}

		if(DEBUG){
			if(!can_zero and has_one){
				cout << i << " th bit taken" << endl;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
