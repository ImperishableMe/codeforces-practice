#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int recur(int pos, vector < int > &v) {
    if (pos < 0) {
        // for (auto x : v) cout << x << " " ;
        // cout << endl;
        assert(v.size() <= 1);
        return v.size();
    } 
    vector < int > cache[2];
    for (auto x : v) {
        cache[ (x & (1<<pos)) > 0].push_back(x);
    }
    if (cache[1].size() < cache[0].size()) swap(cache[1], cache[0]);

    if (cache[0].size() > 1) {
        return max(recur(pos-1, cache[0]), recur(pos-1, cache[1])) + 1;
    }
    return cache[0].size() + recur(pos-1, cache[1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector < int > v(n);
    for (auto &x : v) cin >> x;

    cout << n - recur(30, v) << '\n';

    return 0;
}