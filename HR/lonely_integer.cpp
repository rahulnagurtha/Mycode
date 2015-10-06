#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int n,temp,ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> temp;
    	ans = ans ^ temp;
    }
    cout << ans << endl;
    return 0;
}