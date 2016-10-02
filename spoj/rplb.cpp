#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int dp[1005][1005],capacity,items,berries[1005],cnt;

//dp[i][j] denotess the maximum weight that can be collected from first i items with max limit j

void initialise() {
	for (int i = 0; i <= capacity; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= items; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= capacity; ++i) {
		dp[1][i] = ( (i-berries[items] >= 0) ? berries[items] : 0 );
	}
}


void solve() {
	for (int i = 2; i <= items; ++i) {
		for (int j = 1; j <= capacity; ++j) {
			if(j-berries[items-i+1] >= 0) {
				dp[i][j] = max(dp[i-1][j],berries[items-i+1]+dp[i-2][j-berries[items-i+1]]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << "Scenario #"<< cnt <<": " << dp[items][capacity] << endl ;
	cnt++;
}

// main code begins now

int main()
{
	int t;
	cin >> t ;
	cnt = 1;
	while(t--) {
	    cin >> items >> capacity ;
	    for (int i = 1; i <= items ; ++i) {
	    	cin >> berries[i];
	    }
	    initialise();
	    solve();
	    // printdp();
    }
    return 0;
}