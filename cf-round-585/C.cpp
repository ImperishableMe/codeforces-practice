#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> PII;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < int > a,b;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a' and t[i] == 'b') a.push_back(i);
        if(s[i] == 'b' and t[i] == 'a') b.push_back(i);
    }
    vector < PII > v;
    while(a.size() >= 2 ) {
        int l1 = a.back(); a.pop_back();
        int l2 = a.back() ; a.pop_back();
        v.emplace_back(l1,l2);
    }
    while(b.size() >= 2 ){
        int l1 = b.back(); b.pop_back();
        int l2 = b.back() ; b.pop_back();
        v.emplace_back(l1,l2);        
    }
    if(a.size() != b.size() ) {
        return cout << "-1\n",0;
    }
    else {
        if(a.size()){
            v.emplace_back(a.back(),a.back());
            v.emplace_back(a.back(),b.back());
        }
        cout << v.size() << endl;
        for(auto p : v) {
            cout << p.first + 1<< " " << p.second + 1 << '\n';
        }
    }
    return 0;
}