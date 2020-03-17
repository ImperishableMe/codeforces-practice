#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int ans = 1;

    int n,m;
    cin >> n >> m;

    vector < int > v(n);

    for(int i = 0; i < n; i++) cin >> v[i] ;

    if(n > m ) {
        ans = 0;
    }
    else {

        for(int i = 0;i < n; i++) {
            for(int j = i + 1; j < n; j++){
                ans = (1LL * ans * abs(v[i]-v[j])) % m;
            }
        }
    }
    cout << ans << endl;
    
}