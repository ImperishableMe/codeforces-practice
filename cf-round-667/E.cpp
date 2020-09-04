#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 2e5 + 10;
vector< int >  x;
int dp[3][N];
int n,k;

int DP(int pos, int l){
    if(pos >= n) return 0;
    int &ret = dp[l][pos] ;
    if(ret != -1) return ret;
    ret = DP(pos+1,l);
    if(l>0){
        int _pos = upper_bound(x.begin() , x.end(), x[pos]+k) - x.begin();
        ret = max(ret, _pos - pos + DP(_pos, l-1));
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        x.resize(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        int tmp;
        for(int i = 0; i < n; i++) cin >> tmp;
        sort(x.begin(), x.end());
        for(int i= 0; i <= 2; i++)
            for(int j = 0; j <= n + 5; j++) 
                dp[i][j] = -1;
        cout << DP(0,2) << '\n';
    }
}