#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
set <int> g[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > edges; 
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        edges.emplace_back(a,b);
    }
    set <int> alive;
    for(int i = 1; i <= n; i++) alive.insert(i);
    set<int>ans[3];
    map<int,int> which_set;

    int id = 0;
    while(id < 3){
        if(alive.empty()) {
            cout << "-1\n"; exit(0);
        }
        int now = *alive.begin();
        //cout << now << endl;
        ans[id].insert(now);
        which_set[now] = id;
        alive.erase(alive.begin());
        for(auto it = alive.begin();it != alive.end() ;){
            if(g[now].find(*it) == g[now].end()){
                ans[id].insert(*it);
                which_set[*it] = id;
                it = alive.erase(it);
            }
            else it++;
        }
        id++;
    }

    // for(int i = 0; i < 3; i++){
    //     for(auto x : ans[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    //for(auto x : alive) cout <<"alive "<< x << endl;
    if(!alive.empty()){
        cout << "-1\n"; exit(0);
    }
    //cout << "here" << endl;
    long long cnt[5][5];
    memset(cnt,0,sizeof cnt);
    for(auto [a,b] : edges){
        if(which_set[a] > which_set[b]) swap(a,b);
        cnt[which_set[a]][which_set[b]]++;
    }
    
    //cout << cnt[0][1] << " " << cnt[1][2] << " " << cnt[0][2] << endl;
    if(cnt[0][1] != 1LL*ans[0].size()*ans[1].size() or
        cnt[1][2] != 1LL*ans[1].size()*ans[2].size() or
        cnt[0][2] != 1LL*ans[0].size()*ans[2].size() or
        cnt[0][1] + cnt[0][2] + cnt[1][2] != m
        ){
            cout << "-1\n"; exit(0);
    }
    
    for(int i = 1; i <= n; i++){
        cout << which_set[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}