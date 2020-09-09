#include <bits/stdc++.h>
using namespace std;
int cnt;
int Q(int a, int b){
    cout << "? " << a <<  " " << b << endl;
    int tmp;
    cin >> tmp;
    cnt++;
    return tmp;
}
int main(){
    int n;
    cin >> n;
    vector<int> p(n+1, 0);
    set < int > ind;
    for(int i = 1; i <= n; i++) ind.insert(i);

    while(ind.size() >= 2){
        auto x = *ind.begin();
        auto y = *ind.rbegin();
        int v1 = Q(x,y);
        int v2 = Q(y,x);
        //if(v1 < v2) swap(x,y);
        if(v1 > v2) {
            p[x] = v1;
            ind.erase(x);
        }
        else p[y] = v2, ind.erase(y);
    }
    p[*ind.begin()] = n;
    cout << "! "   ;
    for(int i = 1; i<= n; i++) cout << p[i] << " " ;
    cout << endl;

}