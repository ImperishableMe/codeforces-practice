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
int const N = 1e5 + 10;
int cnt;
int Q(char ch, int val){
    cout << ch << " " << val << endl;
    int tmp;
    cin >> tmp;
    cnt++;
    assert(cnt <= 10000);
    return tmp;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    sieve(N);
    int n;
    cin >> n;
    ll x = 1;
    vector<ll> s, g;
    int cc = 0;
    for(auto x : primes){
        if( x < 1000) cc++;
        if( x <= n and x * x > n ) g.push_back(x);
        else if(x <= n) s.push_back(x);
    }
    // cout << s.size() << " " << cc << " "  << g.size() << endl;
    for(ll p : s){
        int mul = Q('B', p);
        ll pp = p;
        if( Q('B', p) == 1){
            while( pp * p <= n and Q('B', pp * p) == 1 ){
                pp *= p;
            }
            x *= pp;
        }
    }
    int h = Q('A', 1);
    // cout << g.size() << " " << h << endl;
    if(h == 1 + g.size()){
        int period = 100;
        vector<int> to_check;
        for(int i = 0; i < g.size(); i++){
            Q('B', g[i]);
            to_check.push_back(g[i]);
            h--;
            if(i and i % period == 0){
                int chk = Q('A', 1);
                if(h < chk){
                    while(to_check.size()){
                        if(Q('A', to_check.back()) == 1) {
                            cout << "C " << to_check.back() << endl;
                            return 0;
                        }
                        to_check.pop_back();
                    }
                }
                to_check.clear();
            }
        }
        while(to_check.size()){
            if(Q('A', to_check.back()) == 1) {
                cout << "C " << to_check.back() << endl;
                return 0;
            }
            to_check.pop_back();
        }
    }
    else {
        for(auto v : g){
            if( Q('B', v) == 2 ) {
                x *= v; break;
            }
        }
    }
    cout << "C " << x << endl;
	return 0;
}
