#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int x = r / 2;
        if(x < l) cout << "-1 -1" << '\n';
        else    cout << x << " " << 2 * x << '\n';
    }
}