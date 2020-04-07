#include <bits/stdc++.h>
using namespace std;

struct dat{
    int l,r,i;
    dat(){}
    dat(int x,int y,int z):l(x),r(y),i(z){}
    bool operator<(const dat& rhs)const{
        if(l == rhs.l) return r < rhs.r;
        return l < rhs.l;
    }
};

int main(){
    int t;//c = 0;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int n;
        scanf("%d",&n);
        vector < dat > v(n);
        vector < int > cnt(24*60+100,0);

        for(int i = 0; i < n; i++){
            int a,b;
            scanf("%d %d",&a,&b);//)
            v[i] = dat(a,b,i);
            cnt[b]--;
            cnt[a]++;
        }
        bool done = 1;
        for(int i = 1; i <= 24*60+ 10; i++) {
            cnt[i] += cnt[i-1];
            if(cnt[i] > 2) {done = 0; break;}
        }
        if(!done){
            printf("Case #%d: IMPOSSIBLE\n",cs);
            continue;
        }
        sort(v.begin(),v.end());
        // for(auto x : v) 
        //     cout << x.l << " " << x.r <<" " << x.i <<  endl;
        vector<int>ans(n), taken(n,0);
        int now = 0;
        for(int i = 0; i < n; i++){
            //if(taken[i]) continue;
            ans[v[i].i] = now;
            int x = i;
            //cout << v[i].i << " " << i << endl;

            while(i+1 < n and v[i+1].l < v[x].r)
                ans[v[i+1].i] = now^1 , i++;
        }
        printf("Case #%d: ",cs);
        for(int i = 0; i < n; i++){
            if(ans[i]) printf("J");
            else printf("C");
        }
        printf("\n");
    }

}