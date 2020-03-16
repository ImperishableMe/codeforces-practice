#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
       
        string s;
        cin >> s;

        s = 'R'+s + 'R';
        int ans = 0;

        int last = 0, now = -1;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == 'R'){
                ans = max(ans, i - last) ;
                last = i;
            }
        }
        cout << ans << '\n';
    }

    
    return 0;
}