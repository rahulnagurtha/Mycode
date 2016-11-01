int Solution::numDecodings(string A) {
    int dp[A.size() + 5];
    dp[A.size()] = 1;
    for(int i = A.size() - 1; i >= 0; i--) {
        int soFar = 0;
        dp[i] = 0;
        for(int j = i; j < A.size(); j++) {
            soFar = soFar*10 + (A[j] - '0');
            if(soFar > 26) break;
            dp[i] += dp[j+1];
        }
    }
    return dp[0];
}