#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 5001;
int dp[2][N][N];

string a, b;
int n, m;

int DP(int started, int i, int j) {
    if (i >= n or j >= m) return 0;
    int &ret = dp[started][i][j];

    if (ret > -50505) return ret;

    ret = -10000000;

    if (a[i] == b[j]){
        ret = max(2 + DP(1, i+1, j+1), ret);
    }

    if (started){
        ret = max(ret, -1 + DP(1, i+1, j));
        ret = max(ret, -1 + DP(1, i, j+1));
        ret = max(ret, 0);
    }
    else {
        ret = max(ret, DP(0, i+1, j));
        ret = max(ret, DP(0, i, j+1));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;    
    cin >> a >> b;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++) dp[0][i][j] = dp[1][i][j] = -1000000;
    }
    cout << DP(0, 0, 0) << '\n';    
    return 0;
}