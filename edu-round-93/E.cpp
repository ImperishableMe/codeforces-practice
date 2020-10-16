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
ll,
null_type,
greater<ll>,
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
	ordered_set ost;
	set < ll > st[2] ;
	ll best_sum = 0, ans = 0, tot = 0;

	int t;
	cin >> t;

	while(t--){
		ll tp, d;
		cin >> tp >> d;
		tot += d;

		if(tp == 1 and d > 0){
			int ord = ost.order_of_key(d);
			if(ord > st[1].size()){
				best_sum += *ost.find_by_order(st[1].size());
			}
			else 
				best_sum += d;
			st[tp].insert(d);
			ost.insert(d);
		}
		else if(tp == 1 and d < 0){
			d *= -1;
			int ord = ost.order_of_key(d);
			if(ord >= st[tp].size()){
				best_sum -= *ost.find_by_order((int)st[tp].size()-1);
			}
			else 
				best_sum -= d; 
			st[tp].erase(d);
			ost.erase(d);
		}
		else if(tp == 0 and d > 0){

			int ord = ost.order_of_key(d);
			if(ord < st[1].size()){
				best_sum += d;
				if(!st[1].empty())
					best_sum -= *ost.find_by_order((int)st[1].size()-1);
			}
			ost.insert(d);
			st[tp].insert(d);
		}
		else {
			d *= -1;
			int ord = ost.order_of_key(d);
			
			if(ord < st[1].size()){
				best_sum -= d;
				if(!st[1].empty())
					best_sum += *ost.find_by_order((int)st[1].size() );
			}
			ost.erase(d);
			st[tp].erase(d);	
		}
		//cout << " db " << tot << " " << best_sum << '\n';

		if(!st[1].empty() and ost.order_of_key(*st[1].begin()) + 1 == st[1].size()){
			ans = tot + best_sum - *st[1].begin() ;
			if(!st[0].empty()){
				ans += *ost.find_by_order(st[1].size());
			}
			cout << ans << '\n';
		}
		else 
			cout << tot + best_sum << '\n';
	}



	return 0;
}