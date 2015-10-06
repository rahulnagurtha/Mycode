#include <bits/stdc++.h>

using namespace std;

#define	N	2005

int dp[N][N];
int n,day,j;
int val[N];

int main()
{
	// freopen("in.txt", "r", stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&val[i]);
	}
	for (int i = 1; i <= n ; ++i) {
		dp[i][i] = n*val[i];
	}
	for (int l = 2; l <= n ; ++l) {
		day = n-l+1;
		for (int i = 1; i+l <= n+1 ; ++i) {
			j = i+l-1;
			dp[i][j] = max(day*val[i] + dp[i+1][j], day*val[j] + dp[i][j-1]);
		}
	}
	printf("%d\n",dp[1][n]);
    return 0;
}