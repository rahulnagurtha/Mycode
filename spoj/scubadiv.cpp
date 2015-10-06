#include <bits/stdc++.h>

using namespace std;



#define CYLINDERS 1005
#define OXYGEN    23
#define NITROGEN  82



int dp[CYLINDERS][OXYGEN][NITROGEN];
int oxy,nit,n;
int coxy[CYLINDERS];
int cnit[CYLINDERS];
int cweight[CYLINDERS];



void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= oxy; ++j) {
			for (int k = 0; k <= nit; ++k) {
				if(coxy[i] <= j && cnit[i] <= k) dp[i][j][k] = min(dp[i-1][j][k],cweight[i] + dp[i-1][j-coxy[i]][k-cnit[i]]);
				else if(cnit[i] > k && coxy[i] > j) dp[i][j][k] = min(dp[i-1][j][k],cweight[i] + dp[i-1][0][0]);
				else if(cnit[i] > k) dp[i][j][k] = min(dp[i-1][j][k],cweight[i] + dp[i-1][j-coxy[i]][0]);
				else if(coxy[i] > j) dp[i][j][k] = min(dp[i-1][j][k],cweight[i] + dp[i-1][0][k-cnit[i]]);
				else dp[i][j][k] = dp[i-1][j][k];
			}
		}
	}
	printf("%d\n",dp[n][oxy][nit]);
}

void cleardata() {
	for (int i = 0; i <= oxy ; ++i) {
		for (int j = 0; j <= nit ; ++j) {
			dp[0][i][j] = 99999999;
		}
	}
	for (int i = 0; i <= n; ++i) {
		dp[i][0][0] = 0;
	}
}


// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	scanf("%d %d",&oxy,&nit);
    	scanf("%d",&n);
    	for (int i = 1; i <= n; ++i) scanf("%d %d %d",&coxy[i],&cnit[i],&cweight[i]);
		cleardata();
		solve();
    }
    return 0;
}