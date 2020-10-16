#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        printf("%.9f\n", 1.0 / tan( acos(-1.0) / (2*n)) );
    }
}