#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool can(string &s, int l, int r) {
    int left_len = l + 1 + (s.size() - r);
    if (left_len > 10) return 0;

    string ss = "2020";
    int pos = 0;
    string tmp = s.substr(0, l + 1);
    tmp += s.substr(r);

    return tmp == ss;
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (can(s, i, j)){
                cout << "YES\n"; return;
            }
        }

        if (s.substr(0, i + 1) == "2020"){
            cout << "YES\n"; return;
        }

        if (s.substr(i) == "2020"){
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}