#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    vector<int> v(10,100);
    std::vector<int>::iterator low,up;
    low = std::lower_bound (v.begin(), v.begin()+3, 200);
    cout << "lower_bound at position " << (low- v.begin()) << '\n';
    return 0;
}