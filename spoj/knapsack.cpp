#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL dp[2005][2005],capacity,items,weight[2005],value[2005];

//dp[i][j] denotess the maximum weight that can be collected from first i items with max limit j

void initialise() {
	for (LL i = 0; i <= capacity; ++i) {
		dp[0][i] = 0;
	}
	for (LL i = 0; i <= items; ++i) {
		dp[i][0] = 0;
	}
}


void solve() {
	for (LL i = 1; i <= items; ++i) {
		for (LL j = 1; j <= capacity; ++j) {
			if(j-weight[i] >= 0) dp[i][j] = max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[items][capacity] << endl;
}

// void printdp() {
// 	printf("\n\n\n");
// 	for (int i = 0; i <= items ; ++i) {
// 		for (int j = 0; j <= capacity; ++j) {
// 			printf("%lld ",dp[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

// main code begins now

int main()
{
    cin >> capacity >> items ;
    for (LL i = 1; i <= items; ++i) {
    	cin >> weight[i] >> value[i] ;
    }
    initialise();
    solve();
    // printdp();
    return 0;
}