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

	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;
		vector<int>ans(n);
		string s;
		cin >> s;
		set<int>st[2];

		for(int i = 0; i < n; i++){
			st[s[i]-'0'].insert(i);
		}
		int sz = 0;				

		while(!st[0].empty() && !st[1].empty()){
			sz++;
			auto s0 = st[0].begin();
			auto s1 = st[1].begin();
			int now = 0, last_val = 0;

			if(*s0 < *s1){
				now = 0;
			}
			else {
				now = 1;
			}

			while(1){	
				auto tmp = st[now].lower_bound(last_val);
				if(tmp == st[now].end()) break;
				last_val = *tmp;
				ans[last_val] = sz;
				st[now].erase(tmp);
				now ^= 1;
			}
		}

		while(!st[0].empty()){
			sz++;
			ans[*st[0].begin()] = sz;
			st[0].erase(st[0].begin());
		}

		while(!st[1].empty()){
			sz++;
			ans[*st[1].begin()] = sz;
			st[1].erase(st[1].begin());
		}

		cout << sz << '\n';
		for(auto x : ans){
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}