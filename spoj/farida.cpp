#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL dp[10005],coins[10005],N,cnt;

void initialise() {
	dp[0] = 0;
	dp[N] = coins[N];
	dp[N-1] = max(coins[N],coins[N-1]);
}


void solve() {
	for (LL i = N-2; i > 0 ; --i) {
		dp[i] = max(dp[i+1],coins[i]+dp[i+2]);
	}
	printf("Case %lld: %lld\n",cnt,dp[1]);
	cnt++;
}

// main code begins now

int main()
{
    LL t;
    cnt = 1 ;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	cin >> N ;
    	for (LL i = 1; i <= N; ++i) {
    		cin >> coins[i] ;
    	}
    	if(N == 0) {
    		printf("Case %lld: 0\n",cnt);
    		cnt++;
    		continue;
    	}
    	initialise();
    	solve();
    	// printdp();
    }
    return 0;
}