int Solution::minPathSum(vector<vector<int> > &A) {
    int dp[A.size() + 5][A[0].size() + 5];
    dp[A.size() - 1][A[0].size() - 1] = A[A.size() - 1][A[0].size() - 1];
    //fill last column
    for(int i = A.size() - 2; i >= 0; i--) {
        dp[i][A[0].size()-1] = dp[i+1][A[0].size()-1] + A[i][A[0].size()-1];
    }
    //fill last row
    for(int j = A[0].size() - 2; j >= 0; j--) {
        dp[A.size()-1][j] = dp[A.size()-1][j + 1] + A[A.size()-1][j];
    }
    for(int i = A.size() - 2; i >= 0; i--) {
        for(int j = A[i].size() - 2; j >= 0; j--) {
            dp[i][j] = A[i][j] + min(dp[i+1][j],dp[i][j+1]);    
        }    
    }
    return dp[0][0];
}