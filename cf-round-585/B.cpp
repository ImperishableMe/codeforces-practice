#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0) ; cin.tie(0);
    int n;
    cin >> n ;
    vector < long long > v(n);
    long long pos = 0, neg = 0;
    long long so_far = 0;
    vector < long long > par(2,0);
    par[0] = 0;
    int tmp;
    cin >> tmp;
    if(tmp > 0 ) so_far = 0, par[0] = 1, pos = 1;
    else 
        so_far = 1, par[1] = 1, neg = 1;

    for(int i = 1; i < n; i++) {
    
        cin >> tmp ;
        if(tmp < 0 ) so_far ^= 1;
        par[so_far]++;
        neg += par[so_far^1];
        pos += par[so_far];

        cout << i << " " << neg << " " << pos << endl;

    }
    cout << neg << " " << pos << endl;
    return 0;
}