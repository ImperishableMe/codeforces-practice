#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t;
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    typedef pair<char,ll> PCL;
    vector <PCL> v;
    int cnt = 0;
    char l = '#';
    for(int i = 0; i < s.size(); ){
        int x = i;
        cnt = 1;
        while(i + 1 < s.size() and s[i+1] == s[x]) i++, cnt++;
        if(cnt){
            v.emplace_back(s[x],cnt);
            cnt = 0;
        }
        i++;
    }
    ll neg = 0;

    for(int i = 0; i + 1 < v.size(); i++){
        neg += v[i].second + v[i+1].second - 1;
    }
    cout << 1LL*n*(n-1)/2 - neg << endl;
    return 0;
}

