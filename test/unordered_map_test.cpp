#include <bits/stdc++.h>

using namespace std;


int main()
{
    unordered_map<int,int *> T;
    int *a = new int;
    *a = 100;
    int *b = a;
    T[5] = b;
    auto it = T.find(5);
    T.erase(it);
    cout << *a << endl;
    return 0;
}