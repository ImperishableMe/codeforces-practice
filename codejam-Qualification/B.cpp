#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') ans += '0';
            else {
                ans += "(1";
                while(i + 1 < s.size() and s[i+1] == '1')
                    ans += '1', i++;
                ans += ')';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}