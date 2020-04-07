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

    return 0;
}