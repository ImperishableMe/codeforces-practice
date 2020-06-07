#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, c = 0;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int _x = abs(x);
        int _y = abs(y);

        if(_x & _y){
            printf("Case #%d: IMPOSSIBLE\n",++c);
            continue;
        }

    }
}