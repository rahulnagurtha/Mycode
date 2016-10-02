#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;


// main code begins now

int main()
{
    LL m,n,ans1,ans2,tmp1,tmp2,tmp3;
    cin >> n >> m ;
    tmp1 = (n - m)/m;
    tmp2 = (n - m)%m;
    tmp3 = m - tmp2;
    ans1 = ( tmp1*tmp1*tmp3 + (tmp1+1)*(tmp1+1)*tmp2 + (n - m))/2;
    ans2 = ((n - m)*(n - m + 1))/2;
    cout << ans1 << " " << ans2 << endl;
    return 0;
}