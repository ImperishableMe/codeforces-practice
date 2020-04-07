#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,int> PLI;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k ;
    string s;
    cin >> s;
    set < PLI > shoja,ulta;
    vector<ll>dp(n+5,(ll)1e18);
    dp[n] = 0;
    shoja.insert({0,n});
    //ulta.insert({0,n});

    for(int i = n - 1; i >= 0; i--){
        dp[i] = dp[i+1] + (i+1); // connect it directly :)
        if(s[i] == '1'){
            while(!shoja.empty() and (shoja.begin())->second - i > k + 1){
                shoja.erase(shoja.begin());
            }
            if(!shoja.empty()){
                dp[i] = min(dp[i],i + 1 + shoja.begin()->first );
                ulta.insert({i+1+shoja.begin()->first,i});
            }
        }
        while(!ulta.empty() and ulta.begin()->second - i > k)
            ulta.erase(ulta.begin());
        if(!ulta.empty())
            dp[i] = min(dp[i], ulta.begin()->first);
        shoja.insert({dp[i],i});

    }
    cout << dp[0] << '\n';
    return 0;
}
