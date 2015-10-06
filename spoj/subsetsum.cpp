#include <bits/stdc++.h>

using namespace std;

#define N 20
#define eachsize 50


int n,num[N+10],sum;
bool dp[N+20][eachsize*N+10];  //dp[i][j] indicates if the sum i can be formed with subset of elements num[0,....,j]

// main code begins now

bool solve() {
	dp[1][num[1]] = true;
	dp[1][0] = true;
	for (int i = 2; i <= n ; ++i) {
		for (int j = 0; j <= sum ; ++j) {
			if(j >= num[i]) dp[i][j] = dp[i-1][j-num[i]] || dp[i-1][j];
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}



int main()
{
	memset(dp,false,sizeof(dp));
    scanf("%d %d",&n,&sum);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d",&num[i]);
    }
    if(solve()) printf("true\n");
    else printf("false\n");
    return 0;
}