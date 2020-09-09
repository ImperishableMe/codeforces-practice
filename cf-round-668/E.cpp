#include <bits/stdc++.h>
using namespace std;
int const N = 3e5 + 10;
int const LOG = 20;
using PII = pair<int,int>;
using ll = long long int;
vector<PII> R[N] ;
ll t[N] ;
ll Q(int pos){
    ll ret = 0;
    for( ; pos ; pos -= (pos & (-pos))) ret += t[pos];
    return ret;
}
void update(int pos, int val){
    for( ; pos < N; pos += (pos & (-pos))) t[pos] += val;
}

int lower(int val, int lim){
    int cur_ind = 0, tot = 0;
    for(int i = LOG-1; i >= 0; i--){
        if(cur_ind + (1<<i) > lim) continue;
        if(t[cur_ind + (1<<i)] + tot >= val){
            cur_ind |= (1<<i), tot += t[cur_ind];
        }
    }
    return cur_ind;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int>a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] = i - a[i];
    for(int i = 1 ; i <= q; i++){
        int x,y;
        cin >> x >> y; R[n-y].emplace_back(x+1,i);
    }
    vector<int> ans(q+1);
    for(int i = 1; i <= n; i++){
        if(a[i] >= 0){
            int right_valid = lower(a[i], i);
            // cout << right_valid << " " << a[i] << " " << i  << endl;
            if(right_valid){
                update(1,1);
                update(right_valid+1,-1);
            }
        }
        for(auto p : R[i]){
            ans[p.second] = Q( p.first );
        }
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}