#include <bits/stdc++.h>

using namespace std;


char S[1005],T[1005];
int dp[1003][1002];

void initiate() {
	for (int i = 0; i <= 1001; ++i) {
		dp[0][i] = 30*i;
	}
	for (int i = 0; i <= 1001; ++i) {
		dp[i][0] = 15*i;
	}
	return;
}

void solve() {
	for (int i = 1; i <= strlen(S); ++i) {
		for (int j = 1; j <= strlen(T); ++j) {
			if(S[i] == T[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(15+dp[i-1][j],30+dp[i][j-1]);
		}
	}
	printf("%d\n",dp[strlen(S)][strlen(T)]);
	return;
}


// main code begins now

int main()
{
	S[0] = 'z';
	T[0] = 'z';
	initiate();
    while(1) {
    	scanf("%s",S+1);
    	if(S[1] == '#') break;
    	scanf("%s",T+1);
    	solve();
    }
    return 0;
}