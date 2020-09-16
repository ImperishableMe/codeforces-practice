#include <bits/stdc++.h>
using namespace std;

int main(){
    set < int > s;
    s.insert(1);
    auto it = s.upper_bound(1);
    assert(it == s.end());
    auto age = prev(it);
    assert(age == s.begin());
    age = prev(age);
    assert(age == s.begin());
}
