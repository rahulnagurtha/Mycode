#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int n,a,b,c,temp;
    int dp[4005] = {0};
    scanf("%d %d %d %d",&n,&a,&b,&c);
    temp = min(a,min(b,c));
    for (int i = 0; i < temp ; ++i) {
    	dp[i] = -9999999;
    }
    dp[temp] = 1; 
    for (int i = temp + 1; i <= n ; ++i) {
    	temp = -9999999;
    	if(i-a >= 0) temp = max(temp,dp[i-a]);
    	if(i-b >= 0) temp = max(temp,dp[i-b]);
    	if(i-c >= 0) temp = max(temp,dp[i-c]);
    	dp[i] = 1+temp;
    }
    printf("%d\n",dp[n]);
    return 0;
}