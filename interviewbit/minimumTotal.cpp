int Solution::minimumTotal(vector<vector<int> > &A) {
    vector<int> dp;
    dp.resize(A.back().size() + 1);
    for (int i = 0; i < A.back().size() + 1; ++i) {
    	dp[i] = 0;
    }
    for (int i = A.size() - 1; i >= 0; --i) {
    	vector<int> cur;
    	for (int j = 0; j < A[i].size(); ++j) {
    		cur.push_back(A[i][j] + min(dp[j],dp[j+1]));
    	}
    	dp = cur;
    }
    return dp[0];
}