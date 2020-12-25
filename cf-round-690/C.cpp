#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int x;
    cin >> x;

    vector < int > v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ll mx = 1e18;

    do {
        int sum = 0, pos = 0;
        ll num = 0;
        while (pos < v.size() and sum < x){
            sum += v[pos];
            num = num * 10 + v[pos];
            pos++;
        }
        if (x == sum) mx = min(mx, num); 

    }while (next_permutation(v.begin(), v.end()));

    cout << ((mx < 1e10)? mx : -1) << "\n";
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}