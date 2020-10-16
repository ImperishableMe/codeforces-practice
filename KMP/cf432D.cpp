#include <bits/stdc++.h>
using namespace std;
using PLL = pair <long long int, long long int >;

int main(){
    string s;
    cin >> s;
    vector<int> pi(s.size()+1), cnt(s.size()+1,0);
    pi[0] = -1;
    for(int i = 1; i < s.size(); i++){
        int now = pi[i-1];
        while(now != -1 and s[now + 1] != s[i]) now = pi[now] ;
        if(s[now+1] == s[i]) pi[i] = ++now, cnt[now]++;
        else pi[i] = now = -1;
    }
    for(int i = s.size() - 1; i >= 0; i--){
        if(pi[i] != -1) cnt[pi[i]] += cnt[i];
    }
    for(int i = 0; i < s.size() - 1; i++) cnt[i]++;
    vector<PLL> ans;
    ans.push_back({s.size(), 1});
    int now = pi[s.size()-1];
    while(now != -1){
        ans.push_back({now+1,cnt[now]});
        now = pi[now];
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x.first << " " << x.second << '\n';
} 