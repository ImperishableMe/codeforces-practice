#include <bits/stdc++.h>
using namespace std;

double bigmod(double a, int b){
    if(!b) return 1;
    double x = bigmod(a,b/2);
    x = (x*x);
    if(b&1) 
        x *= a;
    return x;
}

int main(){
    int n,m;
    cin >> m >> n;

    double ans = 0;

    for(int i = 1; i <= m; i++){
        ans += (bigmod(1.0*i/m, n) - bigmod(1.0*(i-1)/m,n)) * i;

    }
    printf("%.9f\n",ans);
}