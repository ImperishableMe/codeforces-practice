#include <bits/stdc++.h>
using namespace std;

int const ALPHA = 10;

struct Node {
	int to[ALPHA] ;
	bool bad;
	int link = 0;
	Node(){
		bad = 0;
		for(int i = 0;  i < ALPHA ; i++) to[i] = 0;
	}
};

vector<Node> t(1);

void add(string &s){
	int v = 0;
	for(auto x : s){
		if(!t[v].to[x-'0']){
			t[v].to[x-'0'] = t.size();
			t.push_back(Node());
	}
		v = t[v].to[x-'0'];
	}
	t[v].bad = 1;
}

void build_aho(){
	int v = 0;
	queue < int > q;
	q.push(0);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i = 0; i < ALPHA; i++){
			int &to = t[u].to[i];
			if(to){
				t[to].link = (u == 0)? 0 : t[t[u].link].to[i];
				q.push(to);
			}
			else{ 
				to = t[t[u].link].to[i];
			}
		}
	}
}

int next_move(int nd, int mv){
	return t[nd].to[mv];
}

int x;
void gen(string s, int tot){
	if(tot == x){
		for(int i = 0; i < s.size(); i++){
			int sum = 0;
			for(int j = i; j < s.size(); j++){
				sum += s[j] - '0';
				if(j - i + 1 != s.size() and (x % sum == 0)) return;
			}
		}
		add(s);
		return;
	}	
	for(auto v : s){
		if( x % (v - '0') == 0) return;
	}
	for(int i = 1; i <= 9; i++){
		if(tot + i > x) break;
		gen(s + (char)('0' + i), tot + i);
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s >> x;
	gen("", 0);
	build_aho();

	vector< vector< int > > dp((int)s.size() + 1, vector< int > (t.size() + 1, (int)1e9));

	dp[0][0] = 0;

	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < t.size(); j++){
			dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
			int ns = next_move(j, s[i] - '0');
			if (t[j].bad or t[ns].bad)
				continue;
			dp[i + 1][ns] = min(dp[i + 1][ns], dp[i][j]);
		}
	}	
	int n = s.size();
	cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
	return 0;
}
