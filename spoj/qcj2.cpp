#include <bits/stdc++.h>

using namespace std;

#define MOD                     761238923LL

typedef long long int ll;

ll dp[105][105];


void init() {
	for (int i = 1; i <= 100; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= 100; ++i) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			dp[i][j] = 0;
			if(i < j) continue;
			for (int k = 0; k <= j; ++k) {
				dp[i][j] += dp[i-1][j-k];
				dp[i][j] %= MOD;
			}
		}
	}
	return;
}


int main()
{
	init();
    while(1) {
    	ll n;
    	scanf("%lld",&n);
    	if(n == 0) break;
    	printf("%lld\n",dp[n][n]);
    }
    return 0;
}
