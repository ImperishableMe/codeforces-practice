#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e6 + 10;
vector < ll > primes;
vector<bool> mark(N,0);

void sieve(){
    for(int i = 2; i < N; i++){
        if(!mark[i]){
            for(int j = i*2; j < N ; j += i)
                mark[j] = 1;
        }
    }    
    for(int i = 2; i < N ; i++){
        if(!mark[i]) 
            primes.push_back(i);
    }
}
vector < ll > v;

ll solve(ll n){
    vector < ll > pd;

    for(auto x : primes){
        if(x > n ) continue;
        if(n % x == 0){
            pd.push_back(x);
            while(n % x == 0) n /= x;
        }
    }
    if(n > 1 ) pd.push_back(n);

    ll ret = 1e9;

    for(auto d : pd) {
        ll tot = 0;
        for(auto x : v){
            ll c = d - x % d;
            if(d <= x) c = min(c, x % d); 
            tot += c;
        }
        ret = min(ret, tot);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    sieve();

    int n;
    cin >> n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i] ;

    shuffle(v.begin(), v.end(), rng);

    int how_many = 20;
    ll ans = n;

    for(int i = 0; i < min(how_many,n); i++){
        ll can = n;
        if(v[i] > 1 ) can = min(can,solve(v[i]));
        can = min(can,solve(v[i]+1));
        if(v[i] > 1 ) can = min(can, solve(v[i] - 1));

        ans = min(ans,can);        
    }
    cout << ans << endl;
}