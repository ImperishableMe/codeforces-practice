#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

vector < int > g[1010] ;
priority_queue<PII, vector<PII>, greater<PII> > pq;
vector<bool> vis;
vector < int > deg;
vector < int > take;

void do_it(int top){
    for(auto x : g[top]){
        deg[x]--;
        if(deg[x] == 1) take.emplace_back(x);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int bound = n / 2;
    deg.resize(n+1,0);
    vis.resize(n+1,0);

    for(int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        deg[a]++, deg[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(deg[i] == 1 ) take.push_back(i);
    }

    while(!take.empty()){
        if(take.size() == 1) {
            int v1 = take.back();
            cout << "! " << v1 << endl;
            exit(0);
        }
        else {
            int v1 = take.back();
            take.pop_back();
            int v2 = take.back();
            take.pop_back();
            vis[v1] = 1;
            vis[v2] = 1;

            do_it(v1);
            do_it(v2);
    
            cout << "? " << v1 << " " << v2 << endl;
            int lca ;
            cin >> lca;
            if(lca == v1) {
                cout << "! " << v1 << endl;
                exit(0);
            }
            else if(lca == v2){
                cout << "! " << v2 << endl;
                exit(0);
            }
        }
    }
    return 0;
}