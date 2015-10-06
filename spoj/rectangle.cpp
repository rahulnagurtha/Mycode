#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
    int n,length[1005],breadth[1005];
    int dp[1005][2],ans = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
	    scanf("%d %d",&length[i],&breadth[i]);	
    }
    dp[1][0] = length[1];		//along length
    dp[1][1] = breadth[1];      //along breadth
    for (int i = 2; i <= n ; ++i) {
    	
    	//asumming current is length
			//if length
		if(breadth[i-1] > breadth[i]) {
			dp[i][0] = length[i] + breadth[i-1]-breadth[i] + dp[i-1][0];
		}
		else {
			dp[i][0] = length[i] + breadth[i]-breadth[i-1] + dp[i-1][0];
		}
			//if breadth
		if(length[i-1] > breadth[i]) {
			dp[i][0] = max(dp[i][0],length[i] + length[i-1]-breadth[i] + dp[i-1][1]);
		}
		else {
			dp[i][0] = max(dp[i][0],length[i] + breadth[i] - length[i-1] + dp[i-1][1]);
		}
		//so according to length completed
		
		//asumming current is breadth
			//if length
		if(breadth[i-1] > length[i]) {
			dp[i][1] = breadth[i] + breadth[i-1] - length[i] + dp[i-1][0];
		}
		else {
			dp[i][1] = breadth[i] + length[i]-breadth[i-1] + dp[i-1][0];
		}
			//if breadth
		if(length[i-1] > length[i]) {
			dp[i][1] = max(dp[i][1],breadth[i] + length[i-1] - length[i] + dp[i-1][1]);
		}
		else {
			dp[i][1] = max(dp[i][1],breadth[i] + length[i] - length[i-1] + dp[i-1][1]);
		}
		//so according to breadth completed
    }
	if ( n!= 1) {
	    ans = max(dp[n][0],dp[n][1]);
	}
	else {
		ans = max(length[1]+2*breadth[1],breadth[1]+2*length[1]);
	}
	printf("%d\n",ans);
    return 0;
}