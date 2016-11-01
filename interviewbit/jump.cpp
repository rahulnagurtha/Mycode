int Solution::jump(vector<int> &A) {
    int dp[A.size() + 5];
    dp[A.size() - 1] = 0;
    for (int i = A.size() - 2; i >= 0; --i) {
    	dp[i] = INT_MAX;
    	for (int j = i + 1; j < A.size() && j <= i + A[i]; ++j) {
    		if(dp[j] != INT_MAX) dp[i] = min(dp[i],1 + dp[j]);
    	}
    }
    return (dp[0] == INT_MAX ? -1 : dp[0]);
}