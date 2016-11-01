int Solution::climbStairs(int A) {
	A++;
	int dp[A + 5];
	dp[A] = 1;
    for (int i = A - 1; i > 0; --i) {
    	dp[i] = 0;
    	dp[i] = dp[i+1];
    	if(i + 2 <= A) dp[i] += dp[i+2];
    }
    return dp[1];
}