#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    map < int , vector < int > > mp;

    vector<int>type(n), cost(n);
    for(int i = 0; i < n; i++) cin >> type[i] ;
    for(int i = 0; i < n; i++) cin >> cost[i] ;// , mp[cost[i]].push_back(type[i]);

    for(int i = 0; i < n;i++) mp[type[i]].push_back(cost[i]);

    long long ans = 0, cur = 0;
    priority_queue < PII> pq;

    auto it = mp.begin();

    while(true){
        if(mp.count(cur)) {
            for(auto x : mp[cur]) pq.push({x,cur});
            it++;
        }
        if(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans += (cur - top.second ) * top.first;
        }
        //it++;// = mp.erase(cur);
        if(!pq.empty() or mp.count(cur+1)) cur++;
        else if(it != mp.end()) cur = it->first;
        else break;
    }
    cout << ans << '\n';    
    return 0;
}