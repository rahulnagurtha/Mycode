#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n,arr[300005],answer;

// main code begins now

int main()
{
    scanf("%I64d",&n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%I64d",&arr[i]);
    }
    sort(arr+1,arr+n+1);
    for (int i = 1; i <= n; ++i) {
    	answer += abs(i-arr[i]);
    }
    cout << answer ;
    return 0;
}