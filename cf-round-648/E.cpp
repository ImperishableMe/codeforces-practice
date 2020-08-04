#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    v.push_back(0);
    v.push_back(0);

    long long mx = 0;
    for(auto x : v){
        for(auto y : v){
            for(auto z : v){
                mx = max(mx, x | (y | z));
            }
        }
    }
    cout << mx << endl;
    return 0;
}