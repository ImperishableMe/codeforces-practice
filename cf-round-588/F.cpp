#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 10;
vector<int> gin[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> ind(n+1,0), out(n+1,0);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        ind[a]++,out[b]++;
        gin[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {
        //cout << i << " " << ind[i] << " " << out[i] << endl;
        ans += ind[i]*out[i];
    }
    int q;
    cin >> q;
    cout << ans << '\n';
    while(q--){
        int node;
        cin >> node;
        ans -= ind[node]*out[node];
        for(auto &x : gin[node]){
            ans -= ind[x]*out[x];
            out[x]--;
            ind[x]++;
            //ans += ind[x]*out[x];
            //gin[x].push_back(node);
        }
        ind[node] = 0;
        out[node] += gin[node].size();
        // for(int i = 1; i <= n; i++) {
        //     cout <<q << " " <<  i << " " << ind[i] << " " << out[i] << endl;
        //     //ans += ind[i]*out[i];
        // }
        for(auto &x : gin[node]) {
            ans += ind[x]*out[x];
            gin[x].push_back(node);
        }
        //ans += 
        gin[node].clear();
        cout << ans << '\n';
    }

    return 0;
}
