#include <bits/stdc++.h>
using namespace std;

int const N = 110;
int ara[N][N] ;

bool valo(vector <int> &v, int n){
    vector < int  > seen(n+2,0);
    for(auto x : v){
        if(seen[x]) return 0;
        seen[x] = 1;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for(int caseNo = 1; caseNo <= t; caseNo++){
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) cin >> ara[i][j] , sum += (i==j)*ara[i][j];

        int r = 0, c = 0;
        for(int i = 0; i < n; i++){
            vector < int > v(n);
            for(int j = 0; j < n; j++){
                v[j] = ara[i][j] ;
            }
            r += !valo(v,n);
        }
        for(int cc = 0; cc < n; cc++){
            vector <int> v(n);
            for(int i = 0; i < n; i++) 
                v[i] = ara[i][cc];
            c += !valo(v,n);
        }
        cout << "Case #"<< caseNo << ": " << sum << " " << r << " " << c << '\n';
    }
    return 0;
}