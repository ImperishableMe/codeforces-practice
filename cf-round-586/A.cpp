#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    map < char, int > mp;
    string s;
    cin >> s;
    for(auto x : s)
        mp[x]++;

    while(mp['n']){
        printf("1 ");
        mp['n']--;
    }
    while(mp['z']){
        printf("0 ");
        mp['z']--;
    }
    return 0;
}
