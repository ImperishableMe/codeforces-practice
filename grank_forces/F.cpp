#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
vector<PII> ans;

void D_and_Q(vector <int> &v, int l,int r){
    if(l >= r) return;
    int mid = ( l + r) / 2;
    D_and_Q(v, l, mid);
    D_and_Q(v, mid + 1, r);
    while(l < r){
        ans.emplace_back(v[l],v[r]);
        l++, r--;
    }
}
int main(){
    int n;
    cin >> n;
    int msb = 0;
    for(int i = 0; i < 25; i++){
        if(n & (1<<i)) msb = i;
    }
    vector < int > tmp;
    for(int i = 1; i <= (1<< msb); i++) tmp.push_back(i);
    assert( (tmp.size() & ( (int)tmp.size() - 1)) == 0);
    D_and_Q(tmp, 0, (int)tmp.size() - 1);
    tmp.clear();
    if(n > (1 << msb)) {
        for(int i = n + 1 - (1 << msb); i <= n; i++){
            tmp.push_back(i);
        }
        assert( (tmp.size() & ( (int)tmp.size() - 1)) == 0);
        D_and_Q(tmp, 0, (int)tmp.size() - 1);
    }
    assert( ans.size() < 5e5 );
    cout << ans.size() << endl;
    for(auto x : ans) cout << x.first << " " << x.second << '\n';

}