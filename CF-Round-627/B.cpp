#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector < int > v(n);

        for(int i = 0; i < n; i++) cin >> v[i] ;
        
        bool ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 2; j < n; j++){
                if(v[i] == v[j] ) ans = 1;
            }
        }
        cout << ((ans)?"YES":"NO") << '\n';
    }

    return 0;
}