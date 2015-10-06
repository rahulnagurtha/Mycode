#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;


LL dp[100005][2];
LL n,xco[100005],height[100005],ans = 0;


int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%I64d",&n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%I64d %I64d",&xco[i],&height[i]);
    }
    if(n == 1) {
    	printf("1\n");
    	return 0;
    }
    if(n == 2) {
    	printf("2\n");
    	return 0;
    }
    if(n == 3) {
    	if(xco[1] < xco[2] - height[2] || xco[3] > xco[2] + height[2]) printf("3\n");
    	else printf("2\n");
    	return 0 ;
    }
    //dp[n-1][0]
    if( xco[n-2] < xco[n-1] - height[n-1] ) {
    	dp[n-1][0] = 2;
    }
	else {
		//can make it fall right
		if(xco[n-1] + height[n-1] < xco[n]) {
			dp[n-1][0] = 2;
		}
		else dp[n-1][0] = 1;	//make it stand nill
	}
	//dp[n-1][1]
	if( xco[n-2] + height[n-2] < xco[n-1] - height[n-1] ) dp[n-1][1] = 2;
	else {
		//can make it fall right
		if(xco[n-1] + height[n-1] < xco[n]) dp[n-1][1] = 2;
		else dp[n-1][1] = 1;	//make it stand nill
	}

    for (int i = n-2; i >= 2; --i) {
		//make it fall left
    	if( xco[i-1] < xco[i] - height[i] ) dp[i][0] = 1 + dp[i+1][0];
    	else {
    		//can make it fall right
    		if(xco[i] + height[i] < xco[i+1]) dp[i][0] = max(1 + dp[i+1][1],dp[i+1][0]);
    		else dp[i][0] = dp[i+1][0];	//make it stand nill
    	}
    	//can make it fall left
    	if( xco[i-1] + height[i-1] < xco[i] - height[i] ) dp[i][1] = 1 + dp[i+1][0];
    	else {
    		//can make it fall right
    		if(xco[i] + height[i] < xco[i+1]) dp[i][1] = max(1 + dp[i+1][1],dp[i+1][0]);
    		else dp[i][1] = dp[i+1][0];	//make it stand nill
    	}
    }
    ans = 1 + dp[2][0];
    printf("%I64d\n",ans);
    return 0;
}