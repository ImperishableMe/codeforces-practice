#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        a += '0', b += '0';
        vector<int> mv;
        
        for(int i = 0; i < n; i++) if(a[i] != a[i+1]) mv.push_back(i);
        for(int i = n - 1; i >= 0; i--)
            if(b[i] != b[i+1]) mv.push_back(i);
        
        cout << mv.size() << ' ';
        for(auto x : mv) cout << x + 1 << " ";
        cout << '\n';
    }
}