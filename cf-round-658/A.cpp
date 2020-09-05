#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n),b(m);
        for(int i = 0; i < n; i++){
            cin >> a[i] ;
        }
        for(int &x : b) cin >> x;
        bool f = 0;
        for(int i = 0; i < n and !f ; i++){
            for(int j = 0; j < m and !f ; j++){
                if(a[i] == b[j]){
                    cout << "YES\n";
                    cout << "1 " << a[i] << '\n';
                    f = 1;
                }
            }
        }
        if(!f){
            cout << "NO\n";
        }
    }
    return 0;
}