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
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define F first
#define S second
#define all(v) (v).begin(),(v).end()

void solve(){
	int n, m;
	cin >> n >> m;
	vector< ll > v(n);
	ordered_set ost;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		ll tmp = 0;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '1') tmp ^= (1LL << j);
		}
		v[i] = tmp;
	}
	for(ll i = 0; i < (1LL<< m); i++) ost.insert(i);
	for(auto x : v) ost.erase(x);
	int sz = ost.size();
	cout << *ost.find_by_order( (sz - 1) / 2) << endl;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
