#include <bits/stdc++.h>

using namespace std;

// main code begins now

int main()
{
    long long int n,t,arr[100005],*ptr;
    cin >> n >> t ;
    for (int i = 1; i <= n; ++i) {
    	cin >> arr[i] ;
    }
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	arr[i] += arr[i-1];
    }
    for (int i = 1; i <= n; ++i) {
    	printf("%d ",arr[i]);
    }
    printf("\n");
    ptr = lower_bound(arr+1,arr+n+1,t);
    if(*ptr != 4) ptr--;
    printf("%d\n",ptr-arr);
    return 0;
}