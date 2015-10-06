#include <bits/stdc++.h>

using namespace std;


int n,arr[500005],*lpntr,*rpntr,temp,lpos,rpos;
bool status[500005];

// main code begins now

int main()
{
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
    	cin >> arr[i];
    }
    sort(arr,arr+n+1);
    lpntr = lower_bound(arr+1,arr+n+1,arr[1]);
    rpos = lpntr-arr;
    for (int i = 0; i < ; ++i) {
    	
    	// printf("%d->%d\n",lpntr-arr,*lpntr);
    	
    }
    return 0;
}