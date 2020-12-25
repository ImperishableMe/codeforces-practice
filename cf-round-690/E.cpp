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
PLL,
null_type,
less<PLL>,
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
int const N = 3e5 + 100;

ll fact[N];
ll inv[N];

ll ncr(ll n, ll r) {
    if (n < r or n < 0 or r < 0)  return 0;

    return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
}

void solve() {

    int n, m, k;
    cin >> n >> m >>  k;

    vector < int > v(n), cnt(n + k + 100, 0);

    for(auto &x : v) cin >> x, cnt[x]++;

    for (int i = 1; i <  cnt.size(); i++) cnt[i] += cnt[i-1];

    ll ans = 0;

    for (int mn = 1; mn <= n; mn++){
        int cnt_this = cnt[mn] - cnt[mn-1];
        if (cnt_this <= 0) continue;

        int available = cnt[mn + k] - cnt[mn];        

        for (int take_it = 1; take_it <= cnt_this; take_it++){

            cout << cnt_this << " " << take_it << " " << available << endl;
            ans = (ans + ncr(cnt_this, take_it) * ncr(available, m - take_it)) % MOD;
            cout << "ans " << ans << endl;
        }

    }

    cout << ans << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = (fact[i-1] * i) % MOD;
    inv[N - 1] = bigmod(fact[N-1], MOD - 2);
    for (int i = N - 2; i >= 0; i--){
        inv[i] = (inv[i+1] * (i + 1)) % MOD;
    }    


    int t;
    cin >> t;
    while(t--) solve();
	return 0;
}
