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

bool cmp(PII &a, PII &b){
	if(a.S == b.S) return a.F > b.F;
	return a.S < b.S;
}
int const N = 7000;
vector<int> L[N] ;

vector<vector<int> > dp;

int DP(int l,int r){

    if(l > r or l < 0 or r < 0 ) return 0;
    //dp[l][r];
    int &ret = dp[l][r];
    if(ret != -1){
        return ret;
    }
    ret = DP(l+1,r);

    int complete = 0;
    for(int i = 0; i < L[l].size();i++){
        if(L[l][i] == r) {
            complete++;
        }
    }

    for(int i = 0; i < L[l].size(); i++){
        if(L[l][i] >= r) continue;
        ret = max(ret, DP(l,L[l][i]) + DP(L[l][i]+1,r));
    }
    ret += complete;
    return ret;
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--){

		int n;
		cin >> n;
		vector< PII > v(n+1);
        set<int>values;
        map<int,int> mp;

		for(int i = 0; i < n; i++) {
			cin >> v[i].F >> v[i].S;
			values.insert(v[i].F);
			values.insert(v[i].S);
		}

        for(auto x : values){
            mp[x] = mp.size();
        }

        for(int i = 0; i < n; i++){
            v[i].F = mp[v[i].F] ;
            v[i].S = mp[v[i].S] ;
            L[v[i].F].push_back(v[i].S);
        }

        dp = vector<vector<int> >(mp.size()+1,vector<int>(mp.size()+1,-1));

        //cout << 0 << " "<< mp.size() <<  endl;

        //cout << "first :" << DP(mp[2],mp[4]) << endl;

        cout << DP(0,mp.size()) << '\n';


        for(int i = 0; i < N; i++){
            L[i].clear();
        }

	}
	return 0;
}
/**
4
4
1 5
2 4
2 3
3 4
5
1 5
2 3
2 5
3 5
2 2
3
1 3
2 4
2 3
7
1 10
2 8
2 5
3 4
4 4
6 8
7 7
**/
