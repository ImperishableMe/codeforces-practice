#include <bits/stdc++.h>
using namespace std;
int const N = 110, ALPHA = 26;
int dp[N][N][N];

void update_with_itself(int &x , int y){
    x = max(x,y);
}
int pi[N], aut[N][ALPHA+10] ;
void prefix_calc(string s)
{
    pi[0] = -1;
    int now = -1;
    for(int i = 1; i < s.size(); i++){
        while(now != -1 and s[now+1] != s[i]) now = pi[now];
        if(s[now+1] == s[i]) pi[i] = ++now;
        else pi[i] = now = -1;
    }

    for(int i = 0; i < s.size(); i++){
        for(int ch = 0; ch < ALPHA; ch++){
            if(s[i] == 'A' + ch) aut[i][ch] = i + 1;
            else if(i == 0) aut[i][ch] = i;
            else 
                aut[i][ch] = aut[pi[i-1]+1][ch];
        }
    }

/*     pi[0] = 0;
    for(int i = 1;  i < s.size(); i++){
        int j = pi[i-1];
        while(j < 0 and s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    s += '#';
    for(int i = 0; i < s.size(); i++){
        for(int c = 0; c < ALPHA; c++){
            if( i > 0 and 'A' + c != s[i]) aut[i][c] = aut[pi[i-1]][c];
            else  aut[i][c] = i + ('A' + c == s[i]);
        }
    } */
}
int next_state(int state, char ch){
    return aut[state][ch-'A'];
}
string s1, s2, s3;
int mo[N][N][N];

int DP(int i, int j, int state)
{
    if(state == s3.size()) return INT_MIN;
    if(i == s1.size()) return 0;
    if(j == s2.size()) return 0;
    int &ret = dp[i][j][state];
    if(ret != -1) return ret;
    ret = 0;
    if(s1[i] == s2[j]){
        int nxt = next_state(state, s1[i]);
        if(ret < 1 + DP(i+1,j+1,nxt)){
            ret = 1 +  DP(i+1,j+1,nxt);
        }
    }
    if(ret < DP(i,j+1, state)){ 
        ret = DP(i,j+1, state);
    }
    if(ret < DP(i+1,j,state)) {
        ret = DP(i+1,j,state);
    }

    return ret;
}

void solve(int i, int j, int state){

    if(i == s1.size() or j == s2.size()) return;
    int ans = DP(i,j,state);
    if(ans == DP(i+1,j,state)){
        solve(i+1,j,state);
    }
    else if(ans == DP(i,j+1,state)){
        solve(i,j+1,state);
    }
    else{
        int nxt = next_state(state,s1[i]);
        if(s1[i] == s2[j] and ans == 1 + DP(i+1,j+1,nxt)) 
            cout << s1[i],
            solve(i+1,j+1,nxt);
        else
        {
            assert(0);
        }
        
    }
/*     if( s1[i] == s2[j] and DP(i,j,state) == 1 + DP(i+1,j+1,next_state(state,s1[i]))){
        cout << s1[i] ;
        solve(i+1,j+1,next_state(state,s1[i]));
    } 
    else if(DP(i,j,state) == DP(i+1,j,state)){
        solve(i+1,j,state);
    }
    else 
        solve(i,j+1,state); */
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s1 >> s2 >> s3;
    prefix_calc(s3);
    memset(dp,-1,sizeof dp);
    memset(mo,-1,sizeof mo);
    int ans = DP(0,0,0);
    // cout << ans << endl;
    if(ans)
        solve(0,0,0);
    else 
        cout << ans << endl;

/*     for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            for(int state = 0; state < s3.size(); state++){
                if(s1[i] == s2[j]) {
                    int mv = next_state(state, s1[i]);
                    if(mv != s3.size())
                        dp[i+1][j+1][mv] = max(dp[i+1][j+1][mv], dp[i][j][state] + 1);
                }
                update_with_itself(dp[i+1][j][state],dp[i][j][state]),
                update_with_itself(dp[i][j+1][state], dp[i][j][state]);
            }
        }
    }
    cout << *max_element(dp[s1.size()][s2.size()], dp[s1.size()][s2.size()] + N ) << endl;
 */
}