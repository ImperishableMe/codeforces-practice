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
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	
	ordered_set ost;
	int n;
	cin >> n;

	vector<int> v(n);
	map<int,int> mark;
	vector<int> can_take;
	set < int > left;

	for(auto &x :v) cin >> x, mark[x] = 1;

	for(int i = 0; i <= 1e6 ; i++){
		if(!mark.count(i)) {
			can_take.push_back(i);
		}
		left.insert(i);
	}

	vector<int>b(n);

	int nxt = 0;
	for(int i = 0; i < n; i++){
		int ord = ost.order_of_key(v[i]);
		//cout << ord << endl;
		if(ord > v[i] or (v[i] - ord >= 2)){
			cout << "-1" << endl;
			exit(0);
		}
		if(ord == v[i]){
			while(can_take[nxt] <= v[i] or (left.find(can_take[nxt]) == left.end())){
				nxt++;
			}
			b[i] = can_take[nxt];
			ost.insert(b[i]);
			left.erase(b[i]);
		}
		else if(ord + 1 == v[i]){
			int el = *left.begin();

			if(el >= v[i]){
				cout << "-1" << endl;
				exit(0);
			}
			b[i] = el;
			ost.insert(b[i]);
			left.erase(el);
		}

		//cout << b[i] << endl;
	}

	for(int i = 0; i < n; i++) cout << b[i] << ' ';
	cout << endl;

	return 0;
}