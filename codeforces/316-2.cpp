#include <bits/stdc++.h>

using namespace std;



// main code begins now

int main()
{
    long long n,m,a,left,right;
    cin >> n >> m;
    if(n == 1 && m == 1) {
    	printf("1\n");
    	return 0;
    }
    if( m > n) {
    	a = max(1LL,2*n-m+1);
    }
    else {
    	left = m - 1;
    	right = n - m;
    	if(left >= right) {
    		a = m - 1;
    	}
    	else a = m + 1;
    }
    printf("%I64d\n",a);
    return 0;
}