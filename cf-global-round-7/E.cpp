#include <bits/stdc++.h>
using namespace std;
int const INF = 1e9 + 7;

struct SegTree{
    vector<int>t,lz;
    int n;
    SegTree(int _n):n(_n),t(4*_n,0),lz(4*_n,0){}
    
    void push(int pos,int l,int r){
        if(lz[pos]){
            t[pos] += lz[pos] ;
            if(l != r) lz[pos*2]+= lz[pos], lz[pos*2+1] += lz[pos];
        }
        lz[pos] = 0;
    }
    int Q(int pos,int l,int r,int ql,int qr){
        push(pos,l,r);
        if(ql > r or qr < l) return -INF;
        if(ql<= l and r <= qr) return t[pos];
        int mid = (l+r)/2;
        return max(Q(pos*2,l,mid,ql,qr),Q(pos*2+1,mid+1,r,ql,qr));
    }
    void Update(int pos,int l,int r,int ul,int ur,int val){
        push(pos,l,r);
        if(ul > r or ur < l) return;
        if(ul <= l and r <= ur){
            lz[pos] += val;
            push(pos,l,r);
            return;
        }
        int mid = (l+r)/2;
        Update(pos*2,l,mid,ul,ur,val);
        Update(pos*2+1,mid+1,r,ul,ur,val);
        t[pos] = max(t[pos*2],t[2*pos+1]);
    }

};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n ;
    SegTree seg(n);

    vector < int > p(n+1),holes(n+1), back_p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i] , back_p[p[i]] = i;

    for(int i = 1; i <= n; i++) cin >> holes[i] ;

    int ans = n;
    seg.Update(1,1,n,1,back_p[ans],1);

    for(int i = 1; i <= n; i++){
        while(seg.Q(1,1,n,1,n) <= 0){
            ans--;
            seg.Update(1,1,n,1,back_p[ans],1);
        }
        seg.Update(1,1,n,1,holes[i],-1);

        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}