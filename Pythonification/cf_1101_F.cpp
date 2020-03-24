#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct dat {
    int s,f,c,r;
    dat(){}
    dat(int a,int b, int _c, int d){
        s = a, f = b, c = _c, r = d;
    }
};
vector < dat > buses;
vector < int > cities;

bool can(ll v, int pos) {
    dat t = buses[pos] ;
    ll s = t.s, f = t.f , c = t.c , r = t.r;
    s -= 1;
    f -= 1;
    int refill_count = 0;
    ll cap = v;
    for(int i = s; i < f ; i++){
        ll diff = (cities[i+1] - cities[i]) * c;
        if (diff > v)
             return 0;
        if (diff > cap )
            cap = v - diff,refill_count += 1;
        else 
            cap -= diff;
    }
    return refill_count <= r;
}

ll binary_search(int pos) {
    ll lo = 0, hi = 2e18, ans = 2e18;
    
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(can(mid,pos)){
            ans = min(ans,mid);
            hi = mid -1;
        } 
        else 
            lo = mid + 1;
    }
        
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n,m;
    cin >> n >> m;
    cities.resize(n);
    buses.resize(m);

    for(int i = 0; i < n; i++){
        cin >> cities[i] ;
    }
    for(int i = 0; i < m; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        buses[i] = dat(a,b,c,d);
    }

    shuffle(buses.begin(),buses.end(),rng);

    ll ans = 0;
    for(int i = 0; i < m; i++){
        if(!can(ans,i)) ans = binary_search(i);

    }
    cout << ans << endl;
}
