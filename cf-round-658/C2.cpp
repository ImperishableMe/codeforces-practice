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
	for(int i = 2; i < n; i++)
		if(!marks[i]){
			for(int j = 2*i; j < n; j += i)
				marks[j] = 1;
			primes.push_back(i);
		}
}
void flip(string &s, int ind){
	for(int i = 0; i <= ind/2 ; i++) swap(s[i], s[ind-i]);
	for(int i = 0; i <= ind; i++) s[i] = ((s[i]-'0')^1) + '0';
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n; 
		string a,b; cin >> a >> b;
		if(n == 1){
			if(a[0]  == b[0] ) cout << "0\n";
			else cout << "1 1\n";
			continue;
		}
		vector<int> mv;
		do {
			vector<int> ran_flip;
			mv.clear();
			string tmp_a = a;
			int cnt = min(100, (n+1)/2);
			for(int i = 0; i < cnt; i++) ran_flip.push_back(rng() % n);

			// for(int x : ran_flip) {
			// 	cout << x << " " ;
			// }
			// cout << endl;
			for(int x : ran_flip) flip(tmp_a, x), mv.push_back(x); 

			for(int i = 0; i < n; i++){
				if(tmp_a[i] != b[i]) 
					mv.push_back(i), mv.push_back(0), mv.push_back(i);
			}
		}while(mv.size() > 2 * n);

		cout << mv.size() << ' ';
		for(int i : mv) cout << 1 + i << " ";
		cout << '\n';

	}
	return 0;
}
