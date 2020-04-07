#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x : v) cin >> x, x--;
    vector< vector<long long int> > cnt(21,vector<long long int>(21,0));
    for(int age = 0; age < 20; age++){
        for(int pore = 0; pore < 20; pore++){
            if(pore == age) continue;
            int c = 0;
            for(auto x : v){
                if(x == age) cnt[age][pore] += c;
                else if(x == pore) c++;
            }
        }
    }
    vector<long long>dp((1<<20)+10,(long long )1e18);
    dp[0] = 0;
    for(int msk = 1; msk < (1<<20); msk++){

        for(int pos = 0; pos < 20; pos++){
            if(msk&(1<<pos)){
                long long tmp = 0;
                for(int _ = 0; _ < 20; _++){
                    if( (msk&(1<<_)) && _ != pos)
                        tmp += cnt[pos][_];
                }
                dp[msk] = min(dp[msk], tmp + dp[msk^(1<<pos)]);
            }
        }
    }
    cout << dp[(1<<20) - 1] << endl;

    return 0;
}
