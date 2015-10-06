#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    vector<list<int> > v(100);
    for (int i = 0; i < 10; ++i) {
        v[0].push_back(i)
;    }
    // cout << v[0].size() << " " ;
    while(!v[0].empty()) {
        cout << v[0].back() << " " ;
        v[0].pop_back()
;    }
    return 0;
}