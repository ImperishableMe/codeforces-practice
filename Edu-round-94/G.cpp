#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef pair<ll,ll> PII;
ll const MOD = 998244353;
int const N = 3e5 + 10, K = 50;
ll cum[K][N], F[N], INV[N];

ll ncr(int n, int r){
	if( n < r or n < 0 or r < 0) return 0;
	return F[n] * INV[r] % MOD * INV[n-r] % MOD;	
}
ll bigmod(ll a,ll b){
	if(!b) return 1;
	ll x = bigmod(a,b/2);
	x = ( x * x) % MOD;
	if(b & 1) x = (x * a) % MOD;
	return x;
}
int L[N], R[N] ;
ll cnt[N] ;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	F[0] = 1;
	for(int i = 1; i < N; i++){
		F[i] = (F[i-1] * i) % MOD;
	}
	INV[N-1] = bigmod(F[N-1], MOD - 2);
	for(int i = N - 2; i >= 0; i--) INV[i] = (INV[i+1] * (i + 1)) % MOD;
	for(int i = 1; i <= n; i++) cin >> L[i] >> R[i], cnt[L[i]]++, cnt[R[i]+1]--;
	for(int i = 1; i < N; i++) cnt[i] += cnt[i-1] ;

	for(int less = 0; less < K; less++){
		for(int pos = 1; pos <= n; pos++){
			cum[less][pos] = (cum[less][pos-1] + ncr(cnt[pos]-less,pos-less));
			if(cum[less][pos] >= MOD) cum[less][pos] -= MOD;
		}
	}
	ll ans = cum[0][n] ;

	vector< PII > edge;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge.emplace_back(a,b);
	}

	for(int msk = 1; msk < (1<<m); msk++){
		vector<int> nodes;
		for(int bit = 0; bit < m; bit++){
			if(msk & (1<<bit)) nodes.push_back(edge[bit].first), nodes.push_back(edge[bit].second);
		}
		sort(nodes.begin(), nodes.end());
		nodes.erase( unique(nodes.begin(), nodes.end()), nodes.end());
		int l = 0, r = n;
		for(auto x : nodes){
			l = max(l, L[x]), r = min(r, R[x]) ;
		}
		if(l > r) continue;
		ll contrib = (cum[nodes.size()][r] - cum[nodes.size()][l-1] + MOD) % MOD;
		
		if(__builtin_popcount(msk) & 1) {
			ans = (ans - contrib + MOD) % MOD;
		}
		else ans = (ans + contrib) % MOD;
	}
	cout << ans << endl;	
	return 0;
}
