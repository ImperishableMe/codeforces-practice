#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair <int, int>;

int get_ind(PII p){
    int a, b;
    tie(a,b) = p;
    return ( a + b) / 2;
}
void solve(){
    auto comp = [](const PII &a, const PII &b){
        if(a.second -  a.first == b.second - b.first) return a.first < b.first;
        return a.second - a.first > b.second - b.first;
    };
    set< PII,decltype(comp)> st(comp);
    int n;
    cin >> n;
    if(n == 1) {
        cout << "1\n"; return;
    }
    st.insert({1,n});
    vector< int > v(n + 1);
    int cur = 1;
    while(cur <= n){
        auto tp = *st.begin();
        st.erase(st.begin());
        int ind = get_ind(tp);
        v[ get_ind(tp) ] = cur++;
        st.insert({tp.first, ind - 1});
        st.insert({ ind + 1, tp.second });
    }
    for(int i = 1 ; i <= n; i++) cout << v[i] << " ";
    cout << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}