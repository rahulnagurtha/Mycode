#include <bits/stdc++.h>

using namespace std;

string S,T;
int dp[1003][1002];

void initiate() {
	for (int i = 0; i < 1002; ++i) {
		dp[0][i] = 30*i;
	}
	for (int i = 0; i < 1002; ++i) {
		dp[i][0] = 15*i;
	}
	return;
}

void solve() {
	for (int i = 1; i < S.size(); ++i) {
		for (int j = 1; j < T.size(); ++j) {
			if(S[i] == T[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(15+dp[i-1][j],30+dp[i][j-1]);
		}
	}
	cout << dp[S.size()-1][T.size()-1] << endl;
	return;
}


// main code begins now

int main()
{
	initiate();
    while(1) {
    	string tmp;
    	S = "z";
    	T = "z";
    	cin >> tmp;
    	if(tmp == "#") break;
    	S += tmp;
    	cin >> tmp;
    	T += tmp;
    	solve();
    }
    return 0;
}