#include <bits/stdc++.h>

using namespace std;

#define maxhealth 1005
#define maxarm	  1005

int health,arm,dp[3][maxhealth][maxarm];


void initialise() {
	for (int i = 0; i <= 1000; ++i) {
		dp[0][0][i] = 0;	//air	+3  +2
		dp[1][0][i] = 0;	//water	-5  -10
		dp[2][0][i] = 0;	//fire	-20 +5
	}
	for (int i = 0; i <= 1000; ++i) {
		dp[0][i][0] = 0;	//air	+3  +2
		dp[1][i][0] = 0;	//water	-5  -10
		dp[2][i][0] = 0;	//fire	-20 +5
	}
}

void solve() {
	for (int i = 1; i <= 1000 ; ++i) {
		for (int j = 1; j <= 1000 ; ++j) {
			//solving for air situation
			dp[0][i][j] = max(dp[1][i-5][j-10],dp[2][i-20][j+5]);
		}
	}
}


// main code begins now

int main()
{
	initialise();
	solve();
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	cin >> health >> arm ;
    	printf("%d\n",dp[health][arm]);
    }
    return 0;
}