#include <bits/stdc++.h>
using namespace std;
int const N = 71;
int dp[N][N][N][N];

int n,m,k;
vector < vector < int > > brd;

int DP(int r, int c, int ct, int rem){
    if(r == n) {
        if(rem == 0) return 0;
        else return INT_MIN;
    }
    int &ret = dp[r][c][ct][rem];
    if(ret != -1) return ret;
    ret = INT_MIN;
    if(c == m){
        ret = DP(r + 1, 0, 0, rem);
        return ret;
    }
    if(c < m){
        ret = max(ret, DP(r, c + 1, ct, rem) );
        if( ct + 1 <= m/2 ){
            ret = max(ret, brd[r][c] + DP(r, c + 1, ct + 1, (rem + brd[r][c]) % k ));
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    brd.resize(n);
    for(int i = 0; i < n; i++){
        brd[i] = vector < int > (m);
        for(int j = 0; j < m; j++) cin >> brd[i][j] ;
    }
    memset(dp, -1, sizeof dp);
    cout << DP(0,0,0,0) << '\n';
}