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
int n;
vector<string> v;
vector< vector<PII> >spell;
vector< vector<PLL> > h;

// Hash const
PLL B = {37,43};
PLL M = {1e9+7, 1e9 + 9};
PLL P[N] ;
//

PLL help_hash(int sid, int i, int j){

    PLL tmp = h[sid][j];
    if(i){
        tmp = (tmp - h[sid][i-1]*P[j-i+1] % M + M ) % M;
    }
    return tmp;
}

PLL substr_hash(int s_id, int l_id, int j){

    if(l_id > j){
        return help_hash(s_id,0,j);
    }

    PLL h1 = {0,0};
    if(l_id)
        h1 = help_hash(s_id, 0,l_id-1);

    PLL h2 = {0,0};
    if(l_id < j)
        h2 = help_hash(s_id, l_id+1, j);

    return  h1 * P[j-l_id] + h2;
}

bool can(int s1,int r1, int s2,int r2, int len){
    if(!len) return 1;

    int c1 = (len)?len-1:0 ;
    int c2 = (len)?len-1:0 ;

    if(r1 <= c1) c1++;
    if(r2 <= c2) c2++;

    if(c1 >= v[s1].size() or c2 >= v[s2].size()) return 0;

    //cout << c1 << " " << r1 << " "  << c2 << " " << r2 << endl;

    PLL h1 = substr_hash(s1, r1, c1);
    PLL h2 = substr_hash(s2, r2, c2);

    //cout << h1 << " " << h2 << endl;

    return h1 == h2;
}

bool cmp(int s1, int r1, int s2, int r2){

    int lo = 0, hi = min(v[s1].size(), v[s2].size());

    int ans = -1;

    while(lo <= hi){
       int mid = (lo + hi + 1)/2;

        if(can(s1,r1,s2,r2,mid)){
            ans = max(ans,mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
        //cout << "range " << mid << endl;
    }
    
    //cout << "len " << ans << endl;

    int c1 = ans;
    int c2 = ans;

    if(r1 <= c1) c1++;
    if(r2 <= c2) c2++;

    //cout << "ind " << c1 << " " << r1 << " " << c2 << " " << r2 << endl;
    if(c1 >= v[s1].size() and c2 >= v[s2].size()) return 0;
    if(c1 >= v[s1].size()) return 1;
    if(c2 >= v[s2].size()) return 0;
    //cout << "ind " << c1 << " " << r1 << " " << c2 << " " << r2 << endl;
    return v[s1][c1] < v[s2][c2];
}

bool sort_cmp(PII a, PII b){
    return cmp(a.second,a.first,b.second,b.first);
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
    
    P[0] = {1,1};

    for(int i = 1; i < N; i++){
        P[i] = (P[i-1] * B) % M;
    }

    cin >> n;
    v.resize(n);

    for(int i = 0; i < n;i++) cin >> v[i];

    for(int i = 0; i < n; i++){
        h.push_back(vector<PLL>());
        PLL prev = {0,0};
        for(auto ch : v[i]){
            prev = (prev*B + (ch-'a'+1));
            h.back().push_back(prev);
        }

        spell.push_back(vector<PII>());

        for(int j = 0; j <= v[i].size(); j++){
            spell.back().push_back({j,i});
        }
    }       
    
    for(int i = 0; i < n; i++){
        sort(spell[i].begin(), spell[i].end(),sort_cmp);
    }

    vector< vector<ll> > dp;

    for(int i = 0; i < n; i++){

        if(!i){
            dp.push_back(vector<ll>( spell[i].size(),1));
        }
        else {
            dp.push_back(vector<ll> (spell[i].size(),0));
            int last = -1;
            ll here = 0;
            
            for(int j = 0; j < spell[i].size(); j++){
                
                while( last + 1 < dp[i-1].size() &&
                    !cmp(i, spell[i][j].F,i-1,spell[i-1][last+1].F)){

                        last++;
                        here = (here + dp[i-1][last]) % MOD;
                }

                dp[i][j] = here;
            }

        }

    }
    
    ll ans = 0;
    
    for(auto x : dp[n-1]){
        ans = (ans + x) % MOD;
    }

    cout << ans << endl;

	return 0;
} 