int Solution::uniquePaths(int A, int B) {
    int dp[A+2][B+2];
    for(int i = 0;i < A;i++){
        dp[i][B-1] = 1;
    }
    for(int i = 0;i < B;i++){
        dp[A-1][i] = 1;
    }
    for(int i = B-2;i >= 0;i--) {
        for(int j = A-2;j >= 0;j--) {
            dp[j][i] = dp[j][i+1] + dp[j+1][i];
        }
    }
    return dp[0][0];
}