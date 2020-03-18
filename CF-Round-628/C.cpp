#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
vector < int > g[N] ;
typedef pair <int,int> PII;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int deg_3 = -1;
    vector<int>deg(n+1,0);
    map < int, PII > ind; 
    for(int i = 0 ; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
        if(deg[a]  >= 3 ) deg_3 = a;
        if(deg[b]  >= 3 ) deg_3 = b;

        if(a > b ) swap(a,b);
        //mp[{a,b}] = i;
        ind[i] = {a,b};
    }
    map < PII, int > ans;

    if(deg_3  == -1){
        for(int i = 0; i < n - 1; i++) {
            cout << i << '\n';
        }
        exit(0);
    }
    else {
        
        for(int i = 0; i < 3; i++){
            int t = deg_3;
            auto x = g[deg_3][i] ;
            
            if(t > x) swap(x,t);
            ans[{t,x}] = i;
            //cout << t <<  " " << x << " " << i << endl;
        }
        int cnt = 3;
        for(int i = 0;i < n - 1; i++){
            if(!ans.count({ind[i]})){
                cout << cnt++ << "\n" ;
            }
            else {
                cout << ans[ind[i]] << '\n';
            }
        }
    }
    return 0;
}