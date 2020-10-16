#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < int > deck(n);
    for(auto &x : deck) cin >> x;
    vector < vector < int > > ops;
    while (true)
    {
        // cout << " now " << now << endl;
        // cout <<" array " ;
        // for(auto &x : deck) cout << x << " ";
        // cout << endl;
        int l = -1, r = -1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(deck[i] == deck[j] + 1){
                    l = i, r = j;
                }
            }
        }
        if(l == -1) {
            break;
        }
        int t = -1;
        for(int i = l ; i < r; i++) if(deck[i] > deck[i+1]){
            t = i; break;
        }
        vector < int > tmp;
        ops.push_back(vector <int>());
        if(l >= 1) ops.back().push_back(l);
        if(t - l + 1 >= 1) ops.back().push_back(t - l + 1);
        if(r - t >= 1) ops.back().push_back(r - t);
        if(n - 1 - r >= 1) ops.back().push_back( n - 1 - r);

        for(int i = r + 1; i < n; i++) tmp.push_back(deck[i]);
        for(int i = t + 1; i <= r; i++) tmp.push_back(deck[i]);
        for(int i = l; i <= t; i++) tmp.push_back(deck[i]);
        for(int i = 0; i < l; i++) tmp.push_back(deck[i]);
        deck = tmp;
        assert(deck.size() == n);
    }
    assert(ops.size() <= n) ;
    cout << ops.size() << endl;
    for(auto &x : ops) {
        cout << x.size() << " ";
        for(auto &y : x) cout << y << " ";
        cout << '\n';
    }
}