int Solution::isInterleave(string A, string B, string C) {
    bool dp[C.size() + 5][A.size() + 5][B.size() + 5];
    memset(dp,false,sizeof(dp));
    dp[C.size()][A.size()][B.size()] = true;
    for (int idx = C.size() - 1; idx >= 0; --idx) {
    	for (int i = 0; i <= A.size(); ++i) {
    		for (int j = 0; j <= B.size(); ++j) {
    			if(i < A.size() && A[i] == C[idx]) {
    				dp[idx][i][j] |= dp[idx + 1][i + 1][j];
    			}
    			if(j < B.size() && B[j] == C[idx]) {
    				dp[idx][i][j] |= dp[idx + 1][i][j + 1];
    			}
    		}
    	}
    }
    return dp[0][0][0];
}