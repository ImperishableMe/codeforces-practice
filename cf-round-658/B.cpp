#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int v = 0, seen = 0;
        int win = -1;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp; 
            if(tmp == 1 and !seen) v ^= 1;
            else if(tmp != 1 and !seen) win = i & 1, seen = 1;
        }
        if(win == -1)
            cout << (v==1?"First":"Second") << '\n';
        else 
            cout << (win==0?"First":"Second") << '\n';
    }
    return 0;
}
    

