#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

set < int > dhara(int a, int d, int n){
    set < int > s;
    for(int i = 0; i < n; i++)
        s.insert(a + i*d);
    return s;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> divi;
        ll diff = y - x;
        for(int i = 1; i <= diff; i++) if( diff % i == 0) divi.push_back(i);

        int mx = 1e9 , df, aa;

        for(int a = 1; a <= x ; a++){
            for(auto d : divi){
                set < int > s = dhara(a,d,n);
                if(s.count(x) and s.count(y)){
                    if(*s.rbegin() < mx) {
                        mx = *s.rbegin();
                        df = d, aa = a;
                    }
                }
            }
        }
        set < int > ans = dhara(aa,df,n);
        for(auto x : ans) cout << x << " " ;
        cout << '\n';
    }
}