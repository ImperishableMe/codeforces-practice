#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

vector < ll > get_divisors(ll num) {
    vector < ll > divs;
    for (ll i = 1 ; i * i <= num; i++) {
        if (num % i == 0) {
            divs.push_back(i);
            if (i * i != num) divs.push_back(num / i);
        }
    }
    return divs;
}

int ops_needed(vector < ll > &v, ll els) {

    int cnt = 0;

    for (int i = 0; i < v.size(); ) {
        int j = i;
        ll sum = v[i];

        while (j + 1 < v.size() and sum < els) {
            sum += v[j+1];
            j++;
            cnt++;
        }
        if (sum != els) return INT_MAX;
        i = j + 1;
    }
    return cnt;
}

void solve(){
    int n;
    cin >> n;

    vector < ll > v(n);
    ll sum = 0;
    for (auto &x : v) cin >> x, sum += x;

    vector < ll > divs = get_divisors(sum);

    ll ans = INT_MAX;

    for (auto x : divs) {
        ans = min(ans, 1LL * ops_needed(v, x));
    }
    assert ( ans < INT_MAX);

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}