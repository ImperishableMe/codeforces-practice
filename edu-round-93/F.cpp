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
	int n;
	while(cin >> n){
		string tmp, s;
		cin >> tmp;
		s = "#" + tmp + "#";
		int l = 0, r = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '?')
			{
				l = i;
				continue;
			}
			r = i;
			while (r + 1 < s.size() and s[r + 1 ] == '?')
			{
				r++;
			}
			assert(r + 1 < s.size());
			if (s[l] == '#' or s[r + 1] == '#' or s[l] == s[r + 1])
			{
				char sub;
				if (s[l] == '#' and s[r + 1] == '#')
				{
					sub = '1';
				}
				else if (s[l] == '#')
					sub = s[r + 1];
				else if (s[r + 1] == '#')
					sub = s[l];
				else
					sub = s[l];

				for (int x = l + 1 ; x <= r; x++)
				{
					s[x] = sub;
				}
			}
			i = r + 1;
		}

		vector< pair < ll, char > > v;

		for(int i = 0; i < s.size(); i++){
			int cur = i;
			int cnt = 1;
			while( i + 1 < s.size() and s[i+1] == s[cur]) 
				cnt++, i++;
			v.push_back({cnt,s[cur]});
		}
		if(v.size() == 3){
			for(int i = 1; i <= n; i++){
				cout << v[1].first / i << " ";
			}
			cout << endl;
			continue;
		}
		/* 		
		using Block = array<ll, 4> ;
		vector <Block> blocks;

		for(int i = 1; i + 1 < v.size(); i++){
			
			if(v[i].second == '?'){
				blocks.push_back({v[i-1].first, v[i].first, v[i+1].first});
			}
			else {
				int t1, t2, t3;
				if(v[i-1].first != '?') t1 = 0;
				if(v[i+1].first != '?') t3 = 0;
				t2 = v[i].first;
				blocks.push_back({t1,t2,t3});
			}
		}	
		cout << "blocks :" << endl;
		for(auto x : blocks) {
			auto [t1,t2,t3] = x;
			cout << t1 << " " << t2 << " " << t3 << endl;	
		} */
	}
	return 0;
}