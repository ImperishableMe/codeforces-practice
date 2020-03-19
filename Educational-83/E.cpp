#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int const N = 550;
bool vis1[N][N] , vis2[N][N];
int dp1[N][N], dp2[N][N] ;
int n;

int side_chick(int l, int r){
    if(l > r) return -1;
    if(l == r) return v[l] ;
    if(vis2[l][r]) return dp2[l][r];

    vis2[l][r] = 1;
    int &ret = dp2[l][r] ;
    ret = -1;
    for(int k = l; k < r; k++){
        if(side_chick(l,k) != -1 and side_chick(l,k) == side_chick(k+1,r)){
            ret = side_chick(l,k) + 1;
        }
    }
    return ret;
}

int gf(int l,int r){
    if(l == r) return 1;
    if(l > r) return 0;
    if(vis1[l][r]) return dp1[l][r];

    int ans = INT_MAX;
    vis1[l][r] = 1;
    for(int k = l; k < r; k++){
        ans = min(ans, gf(l,k)+gf(k+1,r) );
    }
    if(side_chick(l,r) > 0 ) {
        ans = min(ans,1);
    }
    return dp1[l][r] = ans;
}

void solve(int n){
    
    v.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i] ;

    memset(vis1,0,sizeof vis1);
    memset(vis2,0,sizeof vis2);

    cout << gf(1,n) << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n){
        solve(n);
    }
    return 0;
}