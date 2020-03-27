#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> PII;
const int MOD = 1e9 + 7;

ll bigmod(ll a,ll b, ll mod = MOD) {
    if(!b) return 1;
    ll x = bigmod(a,b/2);
    x = (x * x) % mod;
    if(a & 1) x = (x * a) % mod;
    return x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s,a = "",b = "";
        cin >> s;

        bool f = 0;

        for(int i = 0; i < s.size(); i++){
            if(!f){
                if(s[i] == '2') a += '1', b += '1';
                else if(s[i] == '1') a += '1', b += '0', f = 1;
                else if(s[i] == '0') a += '0', b += '0';
            }
            else {
                if(s[i] == '2') a += '0', b += '2';
                else if(s[i] == '1') a += '0', b += '1';
                else 
                    a += '0', b += '0';
            }
        }
        cout << a << '\n';cout << b << '\n';

    }
}