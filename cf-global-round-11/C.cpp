#include <bits/stdc++.h>
using namespace std;
using tp = tuple < int,int,int >; // (t, x , y)

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int r, n;
    cin >> r >> n;
    vector < tp > cel(n+1);
    for(int i = 1; i <= n; i++){
        int t, x, y;
        cin >> t >> x >> y;
        cel[i] = make_tuple(t,x,y);
    }
    vector< int > pref(n + 5, INT_MIN), dp(n + 5, 0);
    cel[0] = make_tuple(0,1,1);
    pref[0] = 0;

    auto dist = [cel]( int i, int j)->int {
        return get<0>( cel[j] ) - get<0> (cel[i]);
    };
    auto can_reach = [cel](int i, int j)->bool {
        int t1, x1, x2, t2, y1, y2;
        tie(t1, x1, y1) = cel[i] ;
        tie(t2, x2, y2) = cel[j] ;
        int d = abs(x1 - x2) + abs(y1 - y2);
        int ache = t2 - t1;
        return ache >= d;
    };
    for(int i = 1; i <= n; i++){
        int l = i - 1;
        int can = INT_MIN;
        while(l >= 0 && dist(l, i) <= 3 * r){
            if(can_reach(l, i)) can = max(can, dp[l]);
            l--;
        }
        if(l >= 0) can = max(can, pref[l]);
        if(can == INT_MIN) dp[i] = INT_MIN;
        else dp[i] = 1 + can;
        pref[i] = max(pref[i - 1], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}