#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
int const MOD = 1e9 + 7;
int ara[N][N] ;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(ara,-1,sizeof ara);
    int h,w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        int r;
        cin >> r;
        for(int _w = 1; _w <= r; _w++)
            ara[i][_w] = 1;
        if(r+1 <= w) ara[i][r+1] = 0;
    }

    // for(int i = 1; i <= h; i++){
    //     for(int j = 1; j <= w; j++)
    //         cout << ara[i][j] << " ";
    //     cout << endl;
    // }
    for(int i = 1; i <= w; i++){
        int c;
        cin >> c;
        for(int _h = 1; _h <= c ; _h++){
            if(ara[_h][i] == 0){
                cout << "0\n";
                exit(0);
            } 
            else 
                ara[_h][i] = 1;
        }
        if(c + 1 <= h){
            if(ara[c+1][i] == 1){
                cout << "0\n";
                exit(0);
            } 
            else 
                ara[c+1][i] = 0;
        }
    }
    long long cnt = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++) 
            //cout << ara[i][j] << " ",
            cnt += (ara[i][j] == -1);
        //cout << endl;
    }  
    long long ans = 1;
    while(cnt--)
        ans = (ans * 2) % MOD;
    cout << ans << endl;
    return 0;
}