#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    int one_c = 0;
    for(int i = 0; i < n ; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1) one_c++;
    }
    int out = 0;
    if(one_c * 2 > n) out = 1;
    int how = n/2;
    if(out) how += how & 1;
    cout << how << '\n';
    for(int i = 0; i < how; i++) cout << out << " ";
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}