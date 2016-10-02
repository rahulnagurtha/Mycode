#include <bits/stdc++.h>


using namespace std;


#define ROWS	505
#define COLUMNS 505


int n,m;
int dp[ROWS][COLUMNS];
int b[ROWS][COLUMNS];
int y[ROWS][COLUMNS];
int bsum[ROWS][COLUMNS];
int ysum[ROWS][COLUMNS];



void solve() {
	for (int i = 1; i <= n ; ++i) {
		for (int j = 1; j <= m ; ++j) {
			dp[i][j] = max(dp[i][j-1] + bsum[i][j],dp[i-1][j] + ysum[i][j]);
		}
	}
	printf("%d\n",dp[n][m]);
}



void initdata() {
	// for (int i = 0; i <= n; ++i) {
	// 	ysum[i][0] = 0;
	// 	dp[i][0] = 0;
	// }
	// for (int i = 0; i <= m; ++i) {
	// 	bsum[0][i] = 0;
	// 	dp[0][i] = 0;
	// }
	for (int i = 1; i <= n ; ++i) {
		for (int j = 1; j <= m ; ++j) {
			bsum[i][j] = b[i][j] + bsum[i-1][j];
		}
	}
	for (int j = 1; j <= m ; ++j) {
		for (int i = 1; i <= n ; ++i) {
			ysum[i][j] = y[i][j] + ysum[i][j-1];
		}
	}

}


void readdata() {
	for (int i = 1; i <= n ; ++i) {
		for (int j = 1; j <= m ; ++j) {
			scanf("%d",&y[i][j]);
		}
	}
	for (int i = 1; i <= n ; ++i) {
		for (int j = 1; j <= m ; ++j) {
			scanf("%d",&b[i][j]);
		}
	}
}


int main()
{
    freopen("in.txt", "r", stdin);
    while(1) {
    	scanf("%d %d",&n,&m);
    	if(n == 0 && m == 0) break;
    	readdata();
    	initdata();
    	solve();
    }
    return 0;
}