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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; string s;
    cin >> n >> s;
    vector < vector < int > > pos(26, vector < int > ());
    for(int i = n - 1; i >= 0; i--){
        int p = s[i] - 'a';
        pos[p].push_back( n - i - 1);
    }
    ll ans = 0;
    ordered_set target;
    for(int i = n - 1; i >= 0; i--){
        int p = s[i] - 'a';
        assert(!pos[p].empty());
        ans += target.order_of_key( pos[p].back());
        target.insert(pos[p].back());
        pos[p].pop_back();
    }
    cout << ans << '\n';
    return 0;
}
