#include <bits/stdc++.h>
using namespace std;

int const N = 1e6 + 10;
vector<int> plist[N] ;
vector<bool> np(N,0);
vector <int> primes;
vector<int> g[N] ;

void sieve(){
    primes.push_back(1) ; // haha :|

    for(int i = 2; i < N; i++){
        if(np[i]) continue;
        primes.push_back(i);
        for(int j = i; j < N ; j += i ){
            if(j != i) np[j] = 1;
            plist[j].push_back(i);
        }
    }
}
typedef pair<int,int> PII;
PII create_prime_pair(int n){
    vector< int > v;

    for(auto x : plist[n]){
        int _n = n;
        int cnt = 0;
        while(_n % x == 0) cnt++,_n/= x;
        if(cnt&1) v.push_back(x);
    }
    v.push_back(1);
    v.push_back(1);
    assert(v.size() <= 4) ;
    return {v[0],v[1]};
}
int n;
vector<int> undo;
int dist[N] ;
bool vis[N] ;

int bfs(int p){
    undo.push_back(p);
    dist[p] = 0;
    queue<PII> q;
    q.push({p,-1});

    while(!q.empty()){
        int u = q.front().first; 
        int pr = q.front().second;

        q.pop();
        for(auto x : g[u]){
            if(x == pr) continue;
            if(vis[x]) return 1 + dist[u] + dist[x] ;
            //if(dist.count(x)) 
            q.push({x,u});
            vis[x] = 1;
            undo.push_back(x);
            dist[x] = 1 + dist[u] ;
        }
    }
    return n + 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    sieve();
    cin >> n;
    vector<PII>v(n);
    bool one = 0, two = 0;
    map < PII, int > cnt;

    for(int i = 0; i < n ; i++){
        int tmp;
        cin >> tmp;
        PII p = create_prime_pair(tmp);
        cnt[p]++;
        v[i] = p;

        if(p == PII(1,1)) one = 1;
        if(cnt[p] == 2) two = 1;

    }   
    //cout << "one " << one << endl;
    if(one) {cout << "1\n"; exit(0);}
    if(two) {cout << "2\n"; exit(0);}
    
    for(int i = 0; i < n; i++){
        g[v[i].first].push_back(v[i].second);
        g[v[i].second].push_back(v[i].first);
    }
    int ans = n+1;
    for(int i = 0; i < primes.size(); i++){
        if(primes[i]*1LL*primes[i] > N) break;
        int tmp = bfs(primes[i]);
        ans = min(ans,tmp);

        for(auto x : undo){
            vis[x] = 0;
            dist[x] = 0;
        }
        undo.clear();
    }

    if(ans > n) {
        cout << "-1" << endl;
    }
    else 
        cout << ans << endl;
    return 0;
}