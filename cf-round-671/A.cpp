#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    bool can = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size() ; i++){
        if(i and ( s[i] - '0') % 2 == 0) can = 1;
    }
    if(n == 1) can = (s[0] - '0') & 1;
    if(can) cout << "2" << endl;
    else cout << "1" << endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    set < int > s;
    s.insert(1);
    s.erase(2);
    cout << "hello\n";
}