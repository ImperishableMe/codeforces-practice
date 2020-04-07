#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;
int const MOD = 1e9 + 7;

ll bigmod(ll a,ll b){
    if(!b) return 1;
    ll x = bigmod(a,b/2);x = (x*x)% MOD;
    if(b&1) x = (x*a)%MOD; 
    return x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vector < int > has(300,0);
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            has[tmp] = 1;
        }

        for(int i = 299; i >= 0; i--){
            int cnt = 0;
            for(int p = 1; p <= i; p++) cnt += !(has[p]);
            if(cnt <= x) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}