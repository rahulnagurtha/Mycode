#include <bits/stdc++.h>

using namespace std;

void test(vector<int> tmp) {
    for(int i = 0; i < tmp.size();i++) {
        tmp[i]++;
    }
    return;
}


int main()
{
    vector<int> t;
    for(int i = 0; i < 10;i++) {
        t.push_back(i);
    }
    test(t);
    for(int i = 0; i < 10;i++) {
        cout << t[i] << endl;
    }
    return 0;
}
