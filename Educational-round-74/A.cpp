#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        //cin >> a >> b;
        scanf("%lld %lld",&a,&b);
        //ll g = __gcd(a,b);
        printf("%s\n",(a - b == 1)?"NO":"YES");
    }
    return 0;
}
