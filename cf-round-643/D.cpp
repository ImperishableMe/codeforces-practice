#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;

    vector< int > v(n);
    for(int i = 0; i + 1 < n; i++) v[i] = 1;
    v[n-1] = s - n + 1;
    if(n * 2  >  s){
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for(int x : v) cout << x << " ";
        cout << endl;
        cout << n << endl;
    }
}