#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    ll ans = 0;

    vector < ll > v(n);

    for(int i =0 ; i < n; i++){
        cin >> v[i] ;
    }
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v[i] -= tmp;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        ll tmp = upper_bound(v.begin(), v.end(),-v[i]) - v.begin();
        tmp = n - tmp;
        if(v[i] > 0 && tmp > 0 ) tmp--;
        //cout << v[i] << " " << tmp << endl;

        ans += tmp;
    }
    cout << ans / 2 << endl;

    return 0;
}